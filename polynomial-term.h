#ifndef POLYNOMIAL_TERM_H
#define POLYNOMIAL_TERM_H

#include <stdio.h>

typedef struct
{
    int coefficient;
    int power;
} PolynomialTerm;

void sumOne(PolynomialTerm *pt, PolynomialTerm *other);

void subtractOne(PolynomialTerm *pt, PolynomialTerm *other);

void multiplyOne(PolynomialTerm *pt, PolynomialTerm *other);

void print(PolynomialTerm *pt);

#endif // POLYNOMIAL_TERM_H
