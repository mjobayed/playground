#include <cmath>
#include <iostream>

int main() {
  double num = 1;
  double steps = 0;

  std::cout << "Enter a number: ";
  std::cin >> num;

  std::cout << "\nCounting for: " << num << "\n";
  while (num != 1 && num != -1 && num != -5 && num != -17 && num != 0) {
    if (fmod(num, 2) == 0) {
      num = num / 2;
    } else {
      num = (num * 3) + 1;
    }
    std::cout << num << "\n";
    steps++;
  }

  std::cout << "Total stopping time: " << steps << "\n";
  return 0;
}
