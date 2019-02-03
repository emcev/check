// Copyright emcev emcev084@gmail.com

#include <iostream>
#include <string>
#include <utility>

#include "Function.hpp"

int main() {
  srand(time(0));
  std::cout << "investigation:" << std::endl;
  unsigned number = 1;
  std::string TravelVariant[] = { "direct", "reverse", "random" };
  for (unsigned variant = 0; variant < 3; ++variant) {
    std::cout << "   travel_variant: ";
    std::cout << TravelVariant[variant] << std::endl;
    std::cout << "   experiments:" << std::endl;
    for (unsigned i = 0; i < 9; ++i, ++number) {
      unsigned * array;
      unsigned * position;
      if (Experiment(variant, number, i, array, position) == -1) {
        std::cout << "Error" << std::endl;
      }
      delete[]array;
      delete[]position;
    }
  }
  char c;
  std::cin >> c;
  return 0;
}
