#ifndef POLYNOMIAL_CALCULATOR_INCLUDE_CLI_UTILS_H_
#define POLYNOMIAL_CALCULATOR_INCLUDE_CLI_UTILS_H_

#include <stdbool.h>

void menu();

int inputInt(const char message[]);

void inputPolynomial(char *polynomial, int size, const char message[]);

bool isValidArgs(int argc, char const *argv[]);
#endif // POLYNOMIAL_CALCULATOR_INCLUDE_CLI_UTILS_H_