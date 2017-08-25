#include <type_traits>

#include "Tools/Exception/exception.hpp"

#include "Module/Quantizer/Standard/Quantizer_standard.hpp"
#include "Module/Quantizer/Fast/Quantizer_fast.hpp"
#include "Module/Quantizer/Tricky/Quantizer_tricky.hpp"
#include "Module/Quantizer/NO/Quantizer_NO.hpp"

#include "Quantizer.hpp"

using namespace aff3ct;
using namespace aff3ct::factory;

const std::string aff3ct::factory::Quantizer::name   = "Quantizer";
const std::string aff3ct::factory::Quantizer::prefix = "qnt";

template <typename R, typename Q>
module::Quantizer<R,Q>* Quantizer::parameters
::build() const
{
	     if (this->type == "STD"     ) return new module::Quantizer_standard<R,Q>(this->size, this->n_decimals, this->n_bits, this->n_frames);
	else if (this->type == "STD_FAST") return new module::Quantizer_fast    <R,Q>(this->size, this->n_decimals, this->n_bits, this->n_frames);
	else if (this->type == "TRICKY"  ) return new module::Quantizer_tricky  <R,Q>(this->size, this->range,      this->n_bits, this->n_frames);
	else if (this->type == "NO"      ) return new module::Quantizer_NO      <R,Q>(this->size,                                 this->n_frames);

	throw tools::cannot_allocate(__FILE__, __LINE__, __func__);
}

template <typename R, typename Q>
module::Quantizer<R,Q>* Quantizer
::build(const parameters& params)
{
	return params.template build<R,Q>();
}

void Quantizer
::build_args(arg_map &req_args, arg_map &opt_args, const std::string p)
{
	req_args[{p+"-size", "N"}] =
		{"positive_int",
		 "number of real to quantize."};

	opt_args[{p+"-fra", "F"}] =
		{"positive_int",
		 "set the number of inter frame level to process."};

	opt_args[{p+"-type"}] =
		{"string",
		 "type of the quantizer to use in the simulation.",
		 "STD, STD_FAST, TRICKY"};

	opt_args[{p+"-dec"}] =
		{"positive_int",
		 "the position of the fixed point in the quantified representation."};

	opt_args[{p+"-bits"}] =
		{"positive_int",
		 "the number of bits used for the quantizer."};

	opt_args[{p+"-range"}] =
		{"positive_float",
		 "the min/max bound for the tricky quantizer."};
}

void Quantizer
::store_args(const arg_val_map &vals, parameters &params, const std::string p)
{
	if(exist(vals, {p+"-size", "N"})) params.size       = std::stoi(vals.at({p+"-size", "N"}));
	if(exist(vals, {p+"-fra",  "F"})) params.n_frames   = std::stoi(vals.at({p+"-fra",  "F"}));
	if(exist(vals, {p+"-type"     })) params.type       =           vals.at({p+"-type"     });
	if(exist(vals, {p+"-dec"      })) params.n_decimals = std::stoi(vals.at({p+"-dec"      }));
	if(exist(vals, {p+"-bits"     })) params.n_bits     = std::stoi(vals.at({p+"-bits"     }));
	if(exist(vals, {p+"-range"    })) params.range      = std::stof(vals.at({p+"-range"    }));
}

void Quantizer
::make_header(params_list& head_gnt, const parameters& params, const bool full)
{
	std::string quantif = "unused";
	if (params.type == "TRICKY")
		quantif = "{"+std::to_string(params.n_bits)+", "+std::to_string(params.range)+"f}";
	else if (params.type == "STD" || params.type == "STD_FAST")
		quantif = "{"+std::to_string(params.n_bits)+", "+std::to_string(params.n_decimals)+"}";

	head_gnt.push_back(std::make_pair("Type", params.type));
	if (full) head_gnt.push_back(std::make_pair("Frame size (N)", std::to_string(params.size)));
	if (full) head_gnt.push_back(std::make_pair("Inter frame level", std::to_string(params.n_frames)));
	head_gnt.push_back(std::make_pair("Fixed-point config.", quantif));
}

// ==================================================================================== explicit template instantiation
#include "Tools/types.h"
#ifdef MULTI_PREC
template aff3ct::module::Quantizer<R_8 ,Q_8 >* aff3ct::factory::Quantizer::parameters::build<R_8 ,Q_8 >() const;
template aff3ct::module::Quantizer<R_16,Q_16>* aff3ct::factory::Quantizer::parameters::build<R_16,Q_16>() const;
template aff3ct::module::Quantizer<R_32,Q_32>* aff3ct::factory::Quantizer::parameters::build<R_32,Q_32>() const;
template aff3ct::module::Quantizer<R_64,Q_64>* aff3ct::factory::Quantizer::parameters::build<R_64,Q_64>() const;
template aff3ct::module::Quantizer<R_8 ,Q_8 >* aff3ct::factory::Quantizer::build<R_8 ,Q_8 >(const aff3ct::factory::Quantizer::parameters&);
template aff3ct::module::Quantizer<R_16,Q_16>* aff3ct::factory::Quantizer::build<R_16,Q_16>(const aff3ct::factory::Quantizer::parameters&);
template aff3ct::module::Quantizer<R_32,Q_32>* aff3ct::factory::Quantizer::build<R_32,Q_32>(const aff3ct::factory::Quantizer::parameters&);
template aff3ct::module::Quantizer<R_64,Q_64>* aff3ct::factory::Quantizer::build<R_64,Q_64>(const aff3ct::factory::Quantizer::parameters&);
#else
template aff3ct::module::Quantizer<R,Q>* aff3ct::factory::Quantizer::parameters::build<R,Q>() const;
template aff3ct::module::Quantizer<R,Q>* aff3ct::factory::Quantizer::build<R,Q>(const aff3ct::factory::Quantizer::parameters&);
#endif
// ==================================================================================== explicit template instantiation