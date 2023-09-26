#ifndef POLYNOMIAL_CALCULATOR_INCLUDE_UTILS_H_
#define POLYNOMIAL_CALCULATOR_INCLUDE_UTILS_H_

#include <stdbool.h>

#include "polynomial-term.h"

// ANSI escape code
#define GREEN_COLOR "\033[0;32m"
#define RED_COLOR "\033[0;31m"
#define DEFAULT_COLOR "\033[0m"

void removeSpaces(char *str);

bool isEquals(char str1[], char str2[]);

bool isSignal(char c);

bool isNumber(const char str[]);

#endif // POLYNOMIAL_CALCULATOR_INCLUDE_UTILS_H_