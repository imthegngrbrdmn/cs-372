#include "stringCalculator.h"

int strCalc(std::string input)
{
    if (input.empty())
    {
        return 0;
    }
    std::vector<std::string> nums = { "" };
    std::size_t i = 0;
    for (char c : input)
    {
        if (c == ',' || c == '\n')
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
        sum += std::stoi(num);
    }
    return sum;
}
