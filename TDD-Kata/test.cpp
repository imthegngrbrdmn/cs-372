#include "catch.hpp"
#include "string_calculator.h"

TEST_CASE("An empty string returns zero")
{
	REQUIRE(stringCalculator("") == 0);
}