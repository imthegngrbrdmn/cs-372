#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <random>

int main(int argc, char**argv)
{
  std::vector<uint_fast64_t> fibs{0,1};
  for(std::size_t i = 0; i < 93; ++i) {
    fibs.push_back(fibs[i]+fibs[i+1]);
  }
  std::random_device rd;
  std::mt19937 gen(rd());
  std::shuffle(fibs.begin(), fibs.end(), gen);
  std::sort(fibs.begin(), fibs.end(), [](uint_fast64_t a, uint_fast64_t b) { return a>b; });
  std::for_each(fibs.begin(), fibs.end(), [](uint_fast64_t& n) { std::cout << n << std::endl; });
	return 0;
}
