#include "src/wordCounter.h"
#include <iostream>

int main()
{
	auto statistic = GetWordCountStatistic(std::cin, false);
	PrintStatistic(std::cout, statistic);
	return 0;
}
