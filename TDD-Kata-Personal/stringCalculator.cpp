#include "stringCalculator.h"

int strCalc(std::string input)
{
    if (input.empty())
    {
        return 0;
    }
    return std::stoi(input);
}
