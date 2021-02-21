#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

int main(int argc, char**argv)
{
  std::vector<uint_fast64_t> fibs{0,1};
  for(int i = 0; i < 255; ++i) {
    fibs.push_back(fibs[i]+fibs[i+1]);
  }
  std::for_each(fibs.begin(), fibs.end(), [](uint_fast64_t& n) { std::cout << n << std::endl; });
	return 0;
}
