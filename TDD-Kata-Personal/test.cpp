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
    }
    SUBCASE("Mixes")
    {
        REQUIRE(strCalc("1,1000") == 1001);
        REQUIRE(strCalc("123,1") == 124);
    }
}
TEST_CASE("Two numbers, newline delimited, returns the sum")
{
    SUBCASE("Single digits")
    {
        REQUIRE(strCalc("0\n1") == 1);
        REQUIRE(strCalc("1\n1") == 2);
        REQUIRE(strCalc("1\n2") == 3);
        REQUIRE(strCalc("2\n3") == 5);
        REQUIRE(strCalc("3\n5") == 8);
    }
    SUBCASE("Double digits")
    {
        REQUIRE(strCalc("10\n11") == 21);
        REQUIRE(strCalc("13\n31") == 44);
        REQUIRE(strCalc("21\n12") == 33);
        REQUIRE(strCalc("72\n43") == 115);
        REQUIRE(strCalc("63\n75") == 138);
    }
    SUBCASE("Three or more digits")
    {
        REQUIRE(strCalc("111\n222") == 333);
    }
    SUBCASE("Mixes")
    {
        REQUIRE(strCalc("123\n1") == 124);
    }
}
TEST_CASE("Three numbers, delimited either way, returns the sum")
{
    SUBCASE("Single digits")
    {
        REQUIRE(strCalc("0\n1,0") == 1);
        REQUIRE(strCalc("0,1\n1") == 2);
        REQUIRE(strCalc("1\n1,1") == 3);
        REQUIRE(strCalc("2\n1,2") == 5);
        REQUIRE(strCalc("3\n1,4") == 8);
    }
    SUBCASE("Double digits")
    {
        REQUIRE(strCalc("10\n1,10") == 21);
        REQUIRE(strCalc("13\n16,15") == 44);
        REQUIRE(strCalc("10,11\n12") == 33);
        REQUIRE(strCalc("40,32\n43") == 115);
        REQUIRE(strCalc("32,31\n75") == 138);
    }
    SUBCASE("Three or more digits")
    {
        REQUIRE(strCalc("111\n111,111") == 333);
    }
    SUBCASE("Mixes")
    {
        REQUIRE(strCalc("1\n400,600") == 1001);
        REQUIRE(strCalc("100,23\n1") == 124);
    }
}
TEST_CASE("Negative numbers throw an exception")
{
    bool throws;
    SUBCASE("Single numbers")
    {
        try
        {
            strCalc("-1");
            throws = false;
        }
        catch (...)
        {
            throws = true;
        }
        REQUIRE(throws);
        try
        {
            strCalc("-123");
            throws = false;
        }
        catch (...)
        {
            throws = true;
        }
        REQUIRE(throws);
    }
    SUBCASE("Sums")
    {
        try
        {
            strCalc("-1,-7");
            throws = false;
        }
        catch (...)
        {
            throws = true;
        }
        REQUIRE(throws);
        try
        {
            strCalc("1,-8");
            throws = false;
        }
        catch (...)
        {
            throws = true;
        }
        REQUIRE(throws);
    }
}
TEST_CASE("Numbers greater than 1000 are ignored")
{
    SUBCASE("Single numbers")
    {
        REQUIRE(strCalc("1000") == 1000);
        REQUIRE(strCalc("1001") == 0);
        REQUIRE(strCalc("10000000") == 0);
    }
    SUBCASE("Sums")
    {
        REQUIRE(strCalc("1\n4000,600") == 601);
        REQUIRE(strCalc("100,23\n10001") == 123);
        REQUIRE(strCalc("1001,23\n1") == 24);
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
