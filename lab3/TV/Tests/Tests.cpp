#define CATCH_CONFIG_MAIN
#include "../../../tools/catch2/catch.hpp"
#include "../TV/TVSet.h"

SCENARIO("Tests for base functional")
{
	GIVEN("TV")
	{
		TVSet tv;
		WHEN("tv is turning off")
		{
			tv.TurnOff();
			THEN("Check if features are not available")
			{
				REQUIRE(tv.IsTurnedOn() == false);
				REQUIRE(tv.GetCurrentChannel() == 0);
				REQUIRE(tv.SetChannel(10) == false);
			}
		}
		WHEN("tv is turning on")
		{
			tv.TurnOn();
			THEN("Check if features are available")
			{
				REQUIRE(tv.IsTurnedOn() == true);
				REQUIRE(tv.GetCurrentChannel() == 1);
				REQUIRE(tv.SetChannel(10) == true);
				REQUIRE(tv.GetCurrentChannel() == 10);
				REQUIRE(tv.SetChannel(-1) == false);
			}
		}
	}
}