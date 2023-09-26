#ifndef POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOMIAL_UTILS_H_
#define POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOMIAL_UTILS_H_

#include "polynomial-term.h"

char *standardization(const char polynomial[]);

void transform(PolynomialTerm pt[], char polynomial[]);

void init(PolynomialTerm polynomial[], int size);

char *format(PolynomialTerm pt[]);

#endif // POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOMIAL_UTILS_H_