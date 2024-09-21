#include <cstdint>

namespace ParallelBitOps
{
	struct Vector
	{
		int64_t a, b, c, d;
	};
	
	
	int64_t dot(const Vector& V, const Vector& U);	
	
}
