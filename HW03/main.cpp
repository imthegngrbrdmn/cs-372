/*
  Author:   Millard A. Arnold V
  Created:  2020-02-20
  Modified: 2020-02-21
  Project:  CS-372/Homework03
  
  Learn more about a new feature of C++ (since C++11).
  I am working on using Lambda Functions.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <random>

int main(int argc, char**argv) {
  // Create Vector of Fibonacci Numbers that fit into 64-bit unsigned int
  std::vector<uint_fast64_t> fibs{0,1};
  for(std::size_t i = 0; i < 93; ++i) {
    fibs.push_back(fibs[i]+fibs[i+1]);
  }
  
  // Randomize Vector
  std::random_device rd;
  std::mt19937 gen(rd());
  std::shuffle(fibs.begin(), fibs.end(), gen);

  // Pass Lambda Fuctions to sort & print
  std::sort(fibs.begin(), fibs.end(), [](uint_fast64_t a, uint_fast64_t b) { return a > b; });
  std::for_each(fibs.begin(), fibs.end(), [](uint_fast64_t& n) { std::cout << n << std::endl; });
	return 0;
}

