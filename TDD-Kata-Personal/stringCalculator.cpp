#include "stringCalculator.h"

int strCalc(std::string input)
{
    if (input.empty())
    {
        return 0;
    }
    std::vector<std::string> nums = { "" };
    std::size_t i = 0;
    char userdel = '\n';
    try
    {
        std::stoi(std::string(1,input[0]));
    }
    catch (...)
    {
        if (input[1] == '\n')
        {
            userdel = input[0];
            input = input.substr(2);
        }
        else
        {
            throw std::logic_error("Unknown");
        }
    }
    for (char c : input)
    {
        if (c == '-')
        {
            throw std::logic_error("Negative numbers are not allowed");
        }
        if (c == ',' || c == '\n' || c == userdel)
        {
            ++i;
            nums.push_back("");
            continue;
        }
        nums[i] += c;
    }
    int sum = 0;
    for (std::string num : nums)
    {
        if (std::stoi(num) > 1000) continue;
        sum += std::stoi(num);
    }
    return sum;
}
