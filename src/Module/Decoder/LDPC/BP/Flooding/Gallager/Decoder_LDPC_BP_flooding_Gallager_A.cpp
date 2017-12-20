#include <chrono>
#include <limits>
#include <sstream>

#include "Tools/Exception/exception.hpp"
#include "Tools/Math/utils.h"

#include "Decoder_LDPC_BP_flooding_Gallager_A.hpp"

using namespace aff3ct;
using namespace aff3ct::module;

template <typename B, typename R>
Decoder_LDPC_BP_flooding_Gallager_A<B,R>
::Decoder_LDPC_BP_flooding_Gallager_A(const int K, const int N, const int n_ite, const tools::Sparse_matrix &H,
                                      const std::vector<unsigned> &info_bits_pos, const bool enable_syndrome,
                                      const int syndrome_depth, const int n_frames, const std::string name)
: Decoder               (K, N,                                            n_frames, 1, name),
  Decoder_LDPC_BP<B,R>  (K, N, n_ite, H, enable_syndrome, syndrome_depth, n_frames, 1, name),
  hard_decision         (N                                                                 ),
  info_bits_pos         (info_bits_pos                                                     ),
  HY_N                  (N                                                                 ),
  V_N                   (N                                                                 ),
  C_to_V_messages       (H.get_n_connections(), 0                                          ),
  V_to_C_messages       (H.get_n_connections(), 0                                          )
{
	transpose.resize(H.get_n_connections());
	std::vector<unsigned char> connections(H.get_n_rows(), 0);

	const auto &CN_to_VN = H.get_col_to_rows();
	const auto &VN_to_CN = H.get_row_to_cols();

	auto k = 0;
	for (auto i = 0; i < (int)CN_to_VN.size(); i++)
	{
		for (auto j = 0; j < (int)CN_to_VN[i].size(); j++)
		{
			auto id_V = CN_to_VN[i][j];

			auto branch_id = 0;
			for (auto ii = 0; ii < (int)id_V; ii++)
				branch_id += (int)VN_to_CN[ii].size();
			branch_id += connections[id_V];
			connections[id_V]++;

			if (connections[id_V] > (int)VN_to_CN[id_V].size())
			{
				std::stringstream message;
				message << "'connections[id_V]' has to be equal or smaller than 'VN_to_CN[id_V].size()' "
				        << "('id_V' = " << id_V << ", 'connections[id_V]' = " << connections[id_V]
				        << ", 'VN_to_CN[id_V].size()' = " << VN_to_CN[id_V].size() << ")'.";
				throw tools::runtime_error(__FILE__, __LINE__, __func__, message.str());
			}

			transpose[k] = branch_id;
			k++;
		}
	}
}

template <typename B, typename R>
Decoder_LDPC_BP_flooding_Gallager_A<B,R>
::~Decoder_LDPC_BP_flooding_Gallager_A()
{
}

template <typename B, typename R>
void Decoder_LDPC_BP_flooding_Gallager_A<B,R>
::_decode(const B *Y_N)
{
	for (auto ite = 0; ite < this->n_ite; ite++)
	{
		auto C_to_V_mess_ptr = C_to_V_messages.data();
		auto V_to_C_mess_ptr = V_to_C_messages.data();

		// V -> C (for each variable nodes)
		for (auto i = 0; i < (int)this->H.get_n_rows(); i++)
		{
			const auto node_degree = (int)this->H.get_row_to_cols()[i].size();

			for (auto j = 0; j < node_degree; j++)
			{
				auto cur_state = Y_N[i];
				if (ite > 0)
				{
					auto count = 0;
					for (auto k = 0; k < node_degree; k++)
						if (k != j && C_to_V_mess_ptr[k] != cur_state)
							count++;

					cur_state = count == (node_degree -1) ? !cur_state : cur_state;
				}

				V_to_C_mess_ptr[j] = (int8_t)cur_state;
			}

			C_to_V_mess_ptr += node_degree; // jump to the next node
			V_to_C_mess_ptr += node_degree; // jump to the next node
		}

		// C -> V (for each check nodes)
		auto transpose_ptr = this->transpose.data();
		for (auto i = 0; i < (int)this->H.get_n_cols(); i++)
		{
			const auto node_degree = (int)this->H.get_col_to_rows()[i].size();

			// accumulate the incoming information in CN
			auto acc = 0;
			for (auto j = 0; j < node_degree; j++)
				acc ^= V_to_C_messages[transpose_ptr[j]];

			// regenerate the CN outcoming values
			for (auto j = 0; j < node_degree; j++)
				C_to_V_messages[transpose_ptr[j]] = acc ^ V_to_C_messages[transpose_ptr[j]];

			transpose_ptr += node_degree; // jump to the next node
		}

		if (this->enable_syndrome && ite != this->n_ite -1)
		{
			auto C_to_V_ptr = C_to_V_messages.data();
			// for the K variable nodes (make a majority vote with the entering messages)
			for (auto i = 0; i < this->N; i++)
			{
				const auto node_degree = (int)this->H.get_row_to_cols()[i].size();
				auto count = 0;

				for (auto j = 0; j < node_degree; j++)
					count += C_to_V_ptr[j] ? 1 : -1;

				if (node_degree % 2 == 0)
					count += Y_N[i] ? 1 : -1;

				// take the hard decision
				this->V_N[i] = count > 0 ? 1 : 0;

				C_to_V_ptr += node_degree; // jump to the next node
			}

			if (this->check_syndrome_hard(this->V_N.data()))
				break;
		}
	}

	auto C_to_V_ptr = C_to_V_messages.data();
	// for the K variable nodes (make a majority vote with the entering messages)
	for (auto i = 0; i < this->N; i++)
	{
		const auto node_degree = (int)this->H.get_row_to_cols()[i].size();
		auto count = 0;

		for (auto j = 0; j < node_degree; j++)
			count += C_to_V_ptr[j] ? 1 : -1;

		if (node_degree % 2 == 0)
			count += Y_N[i] ? 1 : -1;

		// take the hard decision
		this->V_N[i] = count > 0 ? 1 : 0;

		C_to_V_ptr += node_degree; // jump to the next node
	}
}

template <typename B, typename R>
void Decoder_LDPC_BP_flooding_Gallager_A<B,R>
::_decode_hiho(const B *Y_N, B *V_K, const int frame_id)
{
//	auto t_decod = std::chrono::steady_clock::now(); // -------------------------------------------------------- DECODE
	this->_decode(Y_N);
//	auto d_decod = std::chrono::steady_clock::now() - t_decod;

//	auto t_store = std::chrono::steady_clock::now(); // --------------------------------------------------------- STORE
	for (auto i = 0; i < this->K; i++)
		V_K[i] = (B)this->V_N[this->info_bits_pos[i]];
//	auto d_store = std::chrono::steady_clock::now() - t_store;

//	(*this)[dec::tsk::decode_hiho].update_timer(dec::tm::decode_hiho::decode, d_decod);
//	(*this)[dec::tsk::decode_hiho].update_timer(dec::tm::decode_hiho::store,  d_store);
}

template <typename B, typename R>
void Decoder_LDPC_BP_flooding_Gallager_A<B,R>
::_decode_hiho_cw(const B *Y_N, B *V_N, const int frame_id)
{
//	auto t_decod = std::chrono::steady_clock::now(); // -------------------------------------------------------- DECODE
	this->_decode(Y_N);
//	auto d_decod = std::chrono::steady_clock::now() - t_decod;

//	auto t_store = std::chrono::steady_clock::now(); // --------------------------------------------------------- STORE
	std::copy(this->V_N.begin(), this->V_N.begin() + this->N, V_N);
//	auto d_store = std::chrono::steady_clock::now() - t_store;

//	(*this)[dec::tsk::decode_hiho_cw].update_timer(dec::tm::decode_hiho_cw::decode, d_decod);
//	(*this)[dec::tsk::decode_hiho_cw].update_timer(dec::tm::decode_hiho_cw::store,  d_store);
}

template <typename B, typename R>
void Decoder_LDPC_BP_flooding_Gallager_A<B,R>
::_decode_siho(const R *Y_N, B *V_K, const int frame_id)
{
//	auto t_load = std::chrono::steady_clock::now();  // ---------------------------------------------------------- LOAD
	hard_decision.decode_siho(Y_N, HY_N.data());
//	auto d_load = std::chrono::steady_clock::now() - t_load;

//	auto t_decod = std::chrono::steady_clock::now(); // -------------------------------------------------------- DECODE
	this->_decode(HY_N.data());
//	auto d_decod = std::chrono::steady_clock::now() - t_decod;

//	auto t_store = std::chrono::steady_clock::now(); // --------------------------------------------------------- STORE
	for (auto i = 0; i < this->K; i++)
		V_K[i] = (B)this->V_N[this->info_bits_pos[i]];
//	auto d_store = std::chrono::steady_clock::now() - t_store;

//	(*this)[dec::tsk::decode_siho].update_timer(dec::tm::decode_siho::load,   d_load);
//	(*this)[dec::tsk::decode_siho].update_timer(dec::tm::decode_siho::decode, d_decod);
//	(*this)[dec::tsk::decode_siho].update_timer(dec::tm::decode_siho::store,  d_store);
}

template <typename B, typename R>
void Decoder_LDPC_BP_flooding_Gallager_A<B,R>
::_decode_siho_cw(const R *Y_N, B *V_N, const int frame_id)
{
//	auto t_load = std::chrono::steady_clock::now();  // ---------------------------------------------------------- LOAD
	hard_decision.decode_siho(Y_N, HY_N.data());
//	auto d_load = std::chrono::steady_clock::now() - t_load;

//	auto t_decod = std::chrono::steady_clock::now(); // -------------------------------------------------------- DECODE
	this->_decode(HY_N.data());
//	auto d_decod = std::chrono::steady_clock::now() - t_decod;

//	auto t_store = std::chrono::steady_clock::now(); // --------------------------------------------------------- STORE
	std::copy(this->V_N.begin(), this->V_N.begin() + this->N, V_N);
//	auto d_store = std::chrono::steady_clock::now() - t_store;

//	(*this)[dec::tsk::decode_siho_cw].update_timer(dec::tm::decode_siho_cw::load,   d_load);
//	(*this)[dec::tsk::decode_siho_cw].update_timer(dec::tm::decode_siho_cw::decode, d_decod);
//	(*this)[dec::tsk::decode_siho_cw].update_timer(dec::tm::decode_siho_cw::store,  d_store);
}

// ==================================================================================== explicit template instantiation 
#include "Tools/types.h"
#ifdef MULTI_PREC
template class aff3ct::module::Decoder_LDPC_BP_flooding_Gallager_A<B_8,Q_8>;
template class aff3ct::module::Decoder_LDPC_BP_flooding_Gallager_A<B_16,Q_16>;
template class aff3ct::module::Decoder_LDPC_BP_flooding_Gallager_A<B_32,Q_32>;
template class aff3ct::module::Decoder_LDPC_BP_flooding_Gallager_A<B_64,Q_64>;
#else
template class aff3ct::module::Decoder_LDPC_BP_flooding_Gallager_A<B,Q>;
#endif
// ==================================================================================== explicit template instantiation
