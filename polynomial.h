#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "polynomial-term.h"

#define MAX_DEGREE 10

void transform(PolynomialTerm pt[], char polynomial[]);

int solve(PolynomialTerm pt[], int x);

#endif // POLYNOMIAL_H
