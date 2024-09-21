#include <iostream>

#include "ParallelBitOps.hpp"

int main() {
	std::cout << "Hello World!" << std::endl;

	int i = std::cin.get();
	
	ParallelBitOps::Vector v{1,2,3};
//	ParallelBitOps::Vector u{3,4,5};

	auto a = ParallelBitOps::dot(v, v);

	std::cout << i << a << std::endl; 

	return 0;
}
