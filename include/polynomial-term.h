#ifndef POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOMIAL_TERM_H_
#define POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOMIAL_TERM_H_

typedef struct
{
    int coefficient;
    int power;
} PolynomialTerm;

int solveOne(const PolynomialTerm *pt, int x);

void sumOne(PolynomialTerm *pt, PolynomialTerm *other);

void subtractOne(PolynomialTerm *pt, PolynomialTerm *other);

PolynomialTerm multiplyOne(PolynomialTerm *pt, PolynomialTerm *other);

void printOne(const PolynomialTerm *pt);

#endif // POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOMIAL_TERM_H_
