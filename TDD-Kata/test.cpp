#include "catch.hpp"
#include "string_calculator.h"

TEST_CASE("An empty string returns zero")
{
	REQUIRE(stringCalculator("") == 0);
}
TEST_CASE("Single number returns value")
{
	REQUIRE(stringCalculator("0") == 0);
	REQUIRE(stringCalculator("1") == 1);
	REQUIRE(stringCalculator("2") == 2);
	REQUIRE(stringCalculator("3") == 3);
	REQUIRE(stringCalculator("100") == 100);
	REQUIRE(stringCalculator("1000") == 1000);
}
TEST_CASE("Two numbers, comma delimited, returns the sum"){
	REQUIRE(stringCalculator("1,2") == 3);
	REQUIRE(stringCalculator("2,2") == 4);
	REQUIRE(stringCalculator("50,50") == 100);
	REQUIRE(stringCalculator("0,0") == 0);
	REQUIRE(stringCalculator("150,100") == 250);
}
TEST_CASE("Two numbers, newline delimited, returns the sum"){
	REQUIRE(stringCalculator("1\n2") == 3);
	REQUIRE(stringCalculator("2\n2") == 4);
	REQUIRE(stringCalculator("50\n50") == 100);
	REQUIRE(stringCalculator("0\n0") == 0);
	REQUIRE(stringCalculator("150\n100") == 250);
}
TEST_CASE("Three numbers, delimited either way, returns the sum")
{
	REQUIRE(stringCalculator("1,1\n1") == 3);
	REQUIRE(stringCalculator("1,1\n2") == 4);
	REQUIRE(stringCalculator("20,30\n50") == 100);
	REQUIRE(stringCalculator("0\n0,0") == 0);
	REQUIRE(stringCalculator("150\n10,90") == 250);
}