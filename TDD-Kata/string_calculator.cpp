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
		if(!split && delimeter.compare((std::string)input[i]) == 0){
			split = true;
		}
	}
	
	return std::stoi(input);
}

