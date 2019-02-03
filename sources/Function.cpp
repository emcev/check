// Copyright emcev emcev084@gmail.com

#include "Function.hpp"

unsigned TheNum[] = { 8, 16, 32, 64, 128, 256, 512, 1024, 2048 };

int WarmingCache(const unsigned variant, const unsigned amount,
    const unsigned*&array, const unsigned*&position) {
  switch (variant) {
    case 0:
      for (unsigned i = 0; i < amount; ++i) {
        array[i];
      } return 0;
    case 1:
      for (int i = amount - 1; i >= 0; --i) {
        array[i];
      }  return 0;
    case 2:
      for (unsigned i = 0; i < amount; ++i) {
        std::swap(position[i], position[rand() % amount]);
      }
      for (unsigned i = 0; i < amount; ++i) {
        array[position[i]];
      } return 0;
    default: {
      return -1;
    }
  }
}

unsigned int64 Timer(const unsigned variant, const unsigned amount,
    const unsigned*&array, const unsigned*&position) {

  auto start = std::chrono::high_resolution_clock::now();
  for (unsigned k = 0; k < 1000; ++k) {
    switch (variant) {
      case 0:
        for (unsigned i = 0; i < amount; ++i) {
          array[i];
        } break;

      case 1:
        for (int i = amount - 1; i >= 0; --i) {
          array[i];
        } break;

      case 2:
        for (unsigned i = 0; i < amount; ++i) {
          std::swap(position[i], position[rand_r() % amount]);
        }
        for (unsigned i = 0; i < amount; ++i) {
          array[position[i]];
        } break;
      default:
        return -1;
    }
  }
  auto stop = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::nanoseconds>
      (stop - start).count();
}

int Experiment(const unsigned variant, const unsigned number,
    const unsigned elements, const unsigned*&array, const unsigned*&position) {

  unsigned amount = TheNum[elements];
  array = new unsigned[amount];
  position = new unsigned[amount];
  for (unsigned i = 0; i < amount; ++i) {
    array[i] = rand_r();
  }
  for (unsigned i = 0; i < amount; ++i) {
    position[i] = i;
  }
  if (WarmingCache(variant, amount, array, position) == -1) {
    return -1;
  }
  unsigned int64 duration = Timer(variant, amount, array, position);
  if (duration == -1) {
    return -1;
  } else {
    std::cout << "   - experiment:" << std::endl << "      number: "
              << number <<std::endl << "      input_data:" << std::endl <<
              "        buffer_size: \"" << 4 * amount << "kb\""
              << std::endl << "      results:" << std::endl <<
              "        duration: " << duration << " ns" << std::endl;
  }
  return 0;
}
