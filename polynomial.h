#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "polynomial-term.h"

#define MAX_SIZE 100
#define MAX_DEGREE 10

int getHighestDegree(const char polynomial[]);

char *standardization(const char polynomial[]);

void transform(PolynomialTerm pt[], char polynomial[]);

int solve(PolynomialTerm pt[], int x);

void sum(PolynomialTerm pt1[], PolynomialTerm pt2[]);

void subtraction(PolynomialTerm pt1[], PolynomialTerm pt2[]);

void multiplication(PolynomialTerm pt1[], PolynomialTerm pt2[]);

char *format(PolynomialTerm pt[]);

void print(PolynomialTerm pt[]);

#endif // POLYNOMIAL_H
