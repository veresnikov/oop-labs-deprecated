#include "src/StringsFunction.h"
#include <iostream>

int main()
{
	std::string input;
	std::getline(std::cin, input);
	std::string result = RemoveExtraSpaces(input);
	std::cout << result << std::endl;
	return 0;
}