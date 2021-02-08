#include "stringCalculator.h"

#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#include"doctest.h"

#include <iostream>
#include <string>

const std::string test_suite_name = "CS-372 TDD Kata - String Calculator";

TEST_CASE("Part 1")
{
    SUBCASE("An empty string returns zero")
    {
        REQUIRE(strCalc("") == 0);
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
