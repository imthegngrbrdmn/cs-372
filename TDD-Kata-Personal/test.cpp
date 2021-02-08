#include "stringCalculator.h"

#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#include"doctest.h"

#include <iostream>
#include <string>

const std::string test_suite_name = "CS-372 TDD Kata - String Calculator";

TEST_CASE("An empty string returns zero")
{
    SUBCASE("\"\"==0")
    {
        REQUIRE(strCalc("") == 0);
    }
}
TEST_CASE("A single number returns the value")
{
    SUBCASE("single digit ints")
    {

        REQUIRE(strCalc("0") == 0);
        REQUIRE(strCalc("1") == 1);
        REQUIRE(strCalc("3") == 3);
        REQUIRE(strCalc("5") == 5);
        REQUIRE(strCalc("8") == 8);
    }
    SUBCASE("two digit ints")
    {
        REQUIRE(strCalc("10") == 10);
        REQUIRE(strCalc("63") == 63);
        REQUIRE(strCalc("56") == 56);
        REQUIRE(strCalc("79") == 79);
        REQUIRE(strCalc("13") == 13);
    }
    SUBCASE("three or more digit ints")
    {
        REQUIRE(strCalc("113") == 113);
        REQUIRE(strCalc("1234") == 1234);
        REQUIRE(strCalc("54321") == 54321);
        REQUIRE(strCalc("1234567890") == 1234567890);
    }
}
TEST_CASE("Two numbers, comma delimited, returns the sum")
{
    SUBCASE("Single digits")
    {
        REQUIRE(strCalc("0,1") == 1);
        REQUIRE(strCalc("1,1") == 2);
        REQUIRE(strCalc("1,2") == 3);
        REQUIRE(strCalc("2,3") == 5);
        REQUIRE(strCalc("3,5") == 8);
    }
    SUBCASE("Double digits")
    {
        REQUIRE(strCalc("10,11") == 21);
        REQUIRE(strCalc("13,31") == 44);
        REQUIRE(strCalc("21,12") == 33);
        REQUIRE(strCalc("72,43") == 115);
        REQUIRE(strCalc("63,75") == 138);
    }
    SUBCASE("Three or more digits")
    {
        REQUIRE(strCalc("111,222") == 333);
        REQUIRE(strCalc("1234,1234") == 2468);
        REQUIRE(strCalc("1567,2289") == 3856);
        REQUIRE(strCalc("200000,345678") == 545678);
    }
    SUBCASE("Mixes")
    {
        REQUIRE(strCalc("10000,45") == 10045);
        REQUIRE(strCalc("1,1000") == 1001);
        REQUIRE(strCalc("123,1") == 124);
    }
}

int main(int argc, char** argv)
{
    doctest::Context dtcontext;
    
    int dtresult;   //Doctest return code holder

    //Handle & check command line
    dtcontext.applyCommandLine(argc, argv);
    dtresult = 0;
    
    //Continue if no errors
    if (!dtresult)
    {
        std::cout << "BEGIN tests for " << test_suite_name << "\n" << std::endl;
        dtresult = dtcontext.run();     //run tests
        std::cout << "END tests for " << test_suite_name << "\n" << std::endl;
    }

    // Wait for user
    std::cout << "Press ENTER to quit ";
    std::cout.flush();
    while (std::cin.get() != '\n');

    // Return code from doctest
    return dtresult;
}
