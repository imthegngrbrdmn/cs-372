#include <iostream>
#include <string>

#include "doctest.h"
#define DOCTEST_CONFIG_IMPLEMENT  // Manual main function
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS //Reduce compile time

int main(int argc, char** argv)
{
    const std::string tname = "CS-372 TDD Kata - String Calculator"; // Printable name for this test suite
    doctest::Context dtcontext; // Primary doctest object
    int dtresult;               // doctest return code; for return by main

    // Handle command line
    dtcontext.applyCommandLine(argc, argv);
    dtresult = 0; // doctest flags no command-line errors

    if (!dtresult)  // Continue only if no command-line error
    {
        // Run test suites
        std::cout << "BEGIN tests for "
                  << tname << std::endl << std::endl;
        dtresult = dtcontext.run();
        std::cout << "END tests for "
                  << tname << std::endl << std::endl;
    }

    // If we want to do something else here, then we need to check context.shouldExit() first.

    // Wait for user
    std::cout << "Press ENTER to quit ";
    std::cout.flush();
    while(std::cin.get()!='\n');

    // Program return value is return code from doctest
    return dtresult;
}
