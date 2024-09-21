#include "ParallelBitOps.hpp"

namespace ParallelBitOps {

int64_t dot(const Vector& V, const Vector& U)
{
	return V.a * U.a + V.b * U.b + V.c * U.c + V.d * U.d;
}

}
