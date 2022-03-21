#define CATCH_CONFIG_MAIN
#include "../../../tools/catch2/catch.hpp"
#include "../src/wordCounter.h"

std::string GetInput()
{
	return "first first second three three\n First SecOnd";
}

Statistic GetExpectedStatisticNoCaseSensitive()
{
	Statistic statistic;
	statistic.insert(std::pair<std::string, int>("first", 3));
	statistic.insert(std::pair<std::string, int>("second", 2));
	statistic.insert(std::pair<std::string, int>("three", 2));
	return statistic;
}

Statistic GetExpectedStatisticWithCaseSensitive()
{
	Statistic statistic;
	statistic.insert(std::pair<std::string, int>("first", 2));
	statistic.insert(std::pair<std::string, int>("second", 1));
	statistic.insert(std::pair<std::string, int>("three", 2));
	statistic.insert(std::pair<std::string, int>("First", 1));
	statistic.insert(std::pair<std::string, int>("SecOnd", 1));
	return statistic;
}

std::string GetExpectedPrintStatistic()
{
	return "first -> 3\n"
		   "second -> 2\n"
		   "three -> 2\n";
}

TEST_CASE("Test word count with empty input string")
{
	std::stringstream ss;
	auto statistic = GetWordCountStatistic(ss, false);
	REQUIRE(statistic.empty() == true);
}

TEST_CASE("Test word count no case sensitive")
{
	std::stringstream ss(GetInput());
	auto statistic = GetWordCountStatistic(ss, false);
	REQUIRE(statistic == GetExpectedStatisticNoCaseSensitive());
}

TEST_CASE("Test word count with case sensitive")
{
	std::stringstream ss(GetInput());
	auto statistic = GetWordCountStatistic(ss, true);
	REQUIRE(statistic == GetExpectedStatisticWithCaseSensitive());
}

TEST_CASE("Test print statistic")
{
	std::stringstream ss;
	PrintStatistic(ss, GetExpectedStatisticNoCaseSensitive());
	REQUIRE(ss.str() == GetExpectedPrintStatistic());
}
