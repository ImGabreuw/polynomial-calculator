#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "polynomial-term.h"

#define MAX_SIZE 1000
#define MAX_DEGREE 10

void transform(PolynomialTerm pt[], char polynomial[]);

int solve(PolynomialTerm pt[], int x);

void sum(PolynomialTerm pt1[], PolynomialTerm pt2[]);

void subtraction(PolynomialTerm pt1[], PolynomialTerm pt2[]);

char *format(PolynomialTerm pt[]);

#endif // POLYNOMIAL_H
