#define CATCH_CONFIG_MAIN
#include "../../../tools/catch2/catch.hpp"
#include "../TV/TVSet.h"


TEST_CASE("Test power function")
{
	TVSet tv;
	REQUIRE(tv.IsTurnedOn() == false);
	tv.TurnOn();
	REQUIRE(tv.IsTurnedOn() == true);
	tv.TurnOff();
	REQUIRE(tv.IsTurnedOn() == false);
}

TEST_CASE("Test channel function")
{
	TVSet tv;
	REQUIRE(tv.GetCurrentChannel() == 0);
	REQUIRE(tv.GetPrevousChannel() == 0);
	REQUIRE(tv.SetChannel(1) == false);
	REQUIRE(tv.SelectPrevousChannel() == false);
	REQUIRE(tv.SetChannel("First channel") == false);
	REQUIRE(tv.SetChannelAlias(1, "First channel") == false);
	REQUIRE(tv.SetChannel("First channel") == false);

	tv.TurnOn();
	REQUIRE(tv.GetCurrentChannel() == 1);
	REQUIRE(tv.GetPrevousChannel() == 1);
	REQUIRE(tv.SetChannel(5) == true);
	REQUIRE(tv.GetCurrentChannel() == 5);
	REQUIRE(tv.GetPrevousChannel() == 1);
	REQUIRE(tv.SelectPrevousChannel() == true);
	REQUIRE(tv.GetCurrentChannel() == 1);
	REQUIRE(tv.SetChannelAlias(5, "Test channel") == true);
	REQUIRE(tv.SetChannel("Test channel") == true);
	REQUIRE(tv.GetCurrentChannel() == 5);
}

TEST_CASE("Incorrect channel")
{
	TVSet tv;
	tv.TurnOn();
	REQUIRE(tv.SetChannel(0) == false);
	REQUIRE(tv.SetChannel(100) == false);
	REQUIRE(tv.SetChannelAlias(0, "test") == false);
	REQUIRE(tv.SetChannelAlias(100, "test") == false);
	REQUIRE(tv.SetChannel("test") == false);
}

TEST_CASE("Min and max range channel")
{
	TVSet tv;
	tv.TurnOn();
	REQUIRE(tv.SetChannel(1) == true);
	REQUIRE(tv.SetChannel(99) == true);
	REQUIRE(tv.SetChannelAlias(1, "1") == true);
	REQUIRE(tv.SetChannelAlias(99, "2") == true);
	REQUIRE(tv.SetChannel("1") == true);
	REQUIRE(tv.SetChannel("2") == true);
}

TEST_CASE("Alias channel")
{
	TVSet tv;
	tv.TurnOn();
	REQUIRE(tv.SetChannelAlias(1, "1") == true);
	REQUIRE(tv.SetChannelAlias(2, "2") == true);
	REQUIRE(tv.SetChannelAlias(3, "3") == true);

	REQUIRE(tv.SetChannel("1") == true);
	REQUIRE(tv.GetCurrentChannel() == 1);

	REQUIRE(tv.SetChannel("2") == true);
	REQUIRE(tv.GetCurrentChannel() == 2);

	REQUIRE(tv.SetChannel("3") == true);
	REQUIRE(tv.GetCurrentChannel() == 3);

	REQUIRE(tv.SetChannelAlias(5, "2") == true);
	REQUIRE(tv.SetChannel("2") == true);
	REQUIRE(tv.GetCurrentChannel() == 5);
}