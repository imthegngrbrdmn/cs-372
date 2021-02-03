#include "string_calculator.h"

int stringCalculator(std::string input)
{
	if (input == "")
	{
		return 0;
	}
	//Two numbers, comma delimited, returns the sum
	std::string left = "";
	std::string right = "";
	std::string delimeter = ",";
	bool split = false;
	for (int i = 0; i < input.length(); i++)
	{
		if(!split && delimeter.compare(input.substr(i,i+1)) == 0)
		{
			split = true;
			continue;
		}
		if (!split)
		{
			left += input.substr(i, i + 1);
		}
		else
		{
			right += input.substr(i, i + 1);
		}
	}
	if (split)
	{
		return std::stoi(left) + std::stoi(right);
	}
	return std::stoi(input);
}

