#ifndef PUNCTURER_NO_HPP_
#define PUNCTURER_NO_HPP_

#include <vector>
#include "Tools/Perf/MIPP/mipp.h"

#include "../Puncturer.hpp"

namespace aff3ct
{
namespace module
{
template <typename B = int, typename Q = float>
class Puncturer_NO : public Puncturer<B,Q>
{
public:
	Puncturer_NO(const int K, const int N, const int n_frames = 1, const std::string name = "Puncturer_NO");
	virtual ~Puncturer_NO();

	void   puncture(const B *X_N1, B *X_N2) const;
	void depuncture(const Q *Y_N1, Q *Y_N2) const;
};
}
}

#endif /* PUNCTURER_NO_HPP_ */
