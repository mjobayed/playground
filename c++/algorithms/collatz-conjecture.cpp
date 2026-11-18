#include <iostream>

int main() {
  int num = 1;

  std::cout << "Enter a number: ";
  std::cin >> num;

  std::cout << "\nCounting for: " << num << "\n";
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = (num * 3) + 1;
    }
    std::cout << num << "\n";
  }

  return 0;
}
