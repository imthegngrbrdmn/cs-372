#include "string_calculator.h"

int stringCalculator(std::string input)
{
	if (input == "")
	{
		return 0;
	}
	return std::stoi(input);
}

