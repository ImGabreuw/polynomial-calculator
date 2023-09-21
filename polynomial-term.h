#ifndef POLYNOMIAL_TERM_H
#define POLYNOMIAL_TERM_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int coefficient;
    int power;
} PolynomialTerm;

int solveOne(PolynomialTerm *pt, int x);

void sumOne(PolynomialTerm *pt, PolynomialTerm *other);

void subtractOne(PolynomialTerm *pt, PolynomialTerm *other);

PolynomialTerm multiplyOne(PolynomialTerm *pt, PolynomialTerm *other);

void printOne(PolynomialTerm *pt);

#endif // POLYNOMIAL_TERM_H
