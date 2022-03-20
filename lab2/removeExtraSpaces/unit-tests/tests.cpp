#define CATCH_CONFIG_MAIN
#include "../../../tools/catch2/catch.hpp"
#include "../src/StringsFunction.h"

TEST_CASE("Test empty string")
{
	std::string input;
	std::string expected;
	REQUIRE(expected == RemoveExtraSpaces(input));
}

TEST_CASE("Test a single character string")
{
	std::string input = "a";
	std::string expected = "a";
	REQUIRE(expected == RemoveExtraSpaces(input));
}

TEST_CASE("Test a spaces around character string")
{
	std::string input = "    a     ";
	std::string expected = "a";
	REQUIRE(expected == RemoveExtraSpaces(input));
}

TEST_CASE("Test a extra spaces in string")
{
	std::string input = "42        42           42";
	std::string expected = "42 42 42";
	REQUIRE(expected == RemoveExtraSpaces(input));
}

TEST_CASE("Test with extra spaces in and around a string")
{
	std::string input = "           42        42           42 ";
	std::string expected = "42 42 42";
	REQUIRE(expected == RemoveExtraSpaces(input));
}