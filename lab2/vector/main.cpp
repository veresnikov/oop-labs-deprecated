#include "vector/vector.h"
#include <iostream>

int main()
{
	auto v = ParseVector(std::cin);
	if (!v.has_value())
	{
		return 1;
	}
	MultiplyEverythingByTheMinimumElement(v.value());
	SortVectorInAscendingOrder(v.value());
	PrintVector(std::cout, v.value());
	return 0;
}

