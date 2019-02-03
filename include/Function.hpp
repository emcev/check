// Copyright emcev emcev084@gmail.com


#ifndef INCLUDE_FUNCTION_HPP_
#define INCLUDE_FUNCTION_HPP_
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>


int WarmingCache(const unsigned variant, const unsigned amount,
    const unsigned*&array, const unsigned*&position);
unsigned int64 Timer(const unsigned variant, const unsigned amount,
    const unsigned*&array, const unsigned*&position);
int Experiment(const unsigned variant, const unsigned number,
    const unsigned elements, const unsigned*&array, const unsigned*&position);
#endif  // INCLUDE_FUNCTION_HPP_
