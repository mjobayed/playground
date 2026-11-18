#include <cmath>
#include <iostream>

int main() {
  double num = 1;
  double steps = 0;
  double minMax = 0;
  bool positive = true;

  std::cout << "Enter a number: ";
  std::cin >> num;

  if (num < 0) {
    positive = false;
  }

  std::cout << "\nCounting for: " << num << "\n";

  // Test for all currently possible loop (as of writing this program).
  // For a list of all loops, see "Iterating on all integers" section here:
  // https://en.wikipedia.org/wiki/Collatz_conjecture
  while (num != 1 && num != -1 && num != -5 && num != -17 && num != 0) {
    if (fmod(num, 2) == 0) {
      num = num / 2;
    } else {
      num = (num * 3) + 1;
    }
    std::cout << num << "\n";

    if (positive && num > minMax) {
      minMax = num;
    }

    if (!positive && num < minMax) {
      minMax = num;
    }

    steps++;
  }

  std::cout << "Total stopping time: " << steps << "\n";

  if (positive && num != 0) {
    std::cout << "Maximum number: " << minMax << "\n";
  }

  if (!positive) {
    std::cout << "Minimum number: " << minMax << "\n";
  }

  return 0;
}
