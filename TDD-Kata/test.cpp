#include "catch.hpp"
#include "string_calculator.h"

TEST_CASE("An empty string returns zero")
{
	REQUIRE(stringCalculator("") == 0);
}
TEST_CASE("Single number returns value")
{
	REQUIRE(stringCalculator("1") == 1);
	REQUIRE(stringCalculator("2") == 2);
	REQUIRE(stringCalculator("3") == 3);
	REQUIRE(stringCalculator("100") == 100);
	REQUIRE(stringCalculator("1000") == 1000);
}