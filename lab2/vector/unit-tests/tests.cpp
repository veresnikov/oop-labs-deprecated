#define CATCH_CONFIG_MAIN
#include "../../../tools/catch2/catch.hpp"
#include "../vector/vector.h"

std::vector<double> GetInputVector()
{
	std::vector<double> input;
	input.push_back(3);
	input.push_back(2.12);
	input.push_back(-1);
	input.push_back(4);
	input.push_back(5.0002);
	return input;
}

std::vector<double> GetExpectedVector()
{
	std::vector<double> expected;
	expected.push_back(-3);
	expected.push_back(-2.12);
	expected.push_back(1);
	expected.push_back(-4);
	expected.push_back(-5.0002);
	return expected;
}

std::vector<double> GetSortedVector()
{
	std::vector<double> input;
	input.push_back(-1);
	input.push_back(2.12);
	input.push_back(3);
	input.push_back(4);
	input.push_back(5.0002);
	return input;
}

TEST_CASE("Test parse vector")
{
	std::stringstream ss("3 2.12 -1 4 5.0002");
	REQUIRE(ParseVector(ss) == GetInputVector());
	ss.clear();

	ss.str("-1 2 a 4 5");
	REQUIRE(ParseVector(ss) == std::nullopt);
	ss.clear();

	ss.str("");
	REQUIRE(ParseVector(ss) == std::nullopt);
	ss.clear();
}

TEST_CASE("Test print vector")
{
	std::stringstream ss;
	PrintVector(ss, GetInputVector());
	REQUIRE(ss.str() == "3.000 2.120 -1.000 4.000 5.000\n");
}

TEST_CASE("Test process vector")
{
	auto vector = GetInputVector();
	MultiplyEverythingByTheMinimumElement(vector);
	REQUIRE(vector == GetExpectedVector());
}

TEST_CASE("Test sort vector in ascending order")
{
	auto vector = GetInputVector();
	SortVectorInAscendingOrder(vector);
	REQUIRE(vector == GetSortedVector());
}
