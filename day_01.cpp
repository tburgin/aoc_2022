#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::ifstream stream("day_01_input.txt");
  std::string line;
  std::vector<uint64_t> elves;
  uint64_t calories = 0;
  while (std::getline(stream, line)) {
    if (line.compare("") == 0) {
      elves.push_back(calories);
      calories = 0;
      continue;
    }
    calories += std::stoull(line);
  }

  // Add the last elf.
  elves.push_back(calories);

  sort(elves.begin(), elves.end(), std::greater<uint64_t>());
  if (elves.size() > 2) {
    std::cout << "The most prepared elf calorie count: " << elves[0]
              << std::endl;
    std::cout << "The top three most prepared elves combined calorie count: "
              << (elves[0] + elves[1] + elves[2]) << std::endl;
  }
}