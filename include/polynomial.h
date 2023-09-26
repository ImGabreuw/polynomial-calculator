#ifndef POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOMIAL_H_
#define POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOMIAL_H_

#include "polynomial-term.h"

#define MAX_SIZE 100
#define MAX_DEGREE 10

int solve(PolynomialTerm pt[], int x);

void sum(PolynomialTerm pt1[], PolynomialTerm pt2[]);

void subtraction(PolynomialTerm pt1[], PolynomialTerm pt2[]);

void multiplication(PolynomialTerm pt1[], PolynomialTerm pt2[]);

int getHighestDegree(const char polynomial[]);

void print(PolynomialTerm pt[]);

#endif // POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOMIAL_H_
