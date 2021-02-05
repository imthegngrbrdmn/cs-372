#include "string_calculator.h"
#include <iostream>
int stringCalculator(std::string input)
{
	if (input == "")
	{
		return 0;
	}
	//Two numbers, comma delimited, returns the sum
	std::string left = "";
	std::string right = "";
	bool split = false;
	for (int i = 0; i < input.length(); ++i)
	{
		if(!split && (','==input[i] || '\n'==input[i]))
		{
			split = true;
			continue;
		}
		if (!split)
		{
			left += input[i];
		}
		else
		{
			right += input[i];
		}
	}
	if (split)
	{
		return (std::stoi(left) + std::stoi(right));
	}
	return std::stoi(input);
}

