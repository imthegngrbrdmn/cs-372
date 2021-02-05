#include "string_calculator.h"
#include <iostream>
#include <vector>
int stringCalculator(std::string input)
{
	if (input == "")
	{
		return 0;
	}
	std::vector<std::string> numbers = {""};
	int index = 0;
	for (int i = 0; i < input.length(); ++i)
	{
		if((','==input[i] || '\n'==input[i]))
		{
			index++;
			numbers.push_back("");
			continue;
		}
		numbers[index] += input[i];
	}
	int output = 0;
	for(auto number: numbers){
		output += std::stoi(number);
	}
	return output;
}

