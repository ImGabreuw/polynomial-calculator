#include <stdio.h>
#include "polynomial-term.h"

void sumOne(PolynomialTerm *pt, PolynomialTerm *other)
{
    pt->coefficient = pt->coefficient + other->coefficient;
    pt->power = pt->power + other->power;
}

void subtractOne(PolynomialTerm *pt, PolynomialTerm *other)
{
    pt->coefficient = pt->coefficient - other->coefficient;
    pt->power = pt->power - other->power;
}

void multiplyOne(PolynomialTerm *pt, PolynomialTerm *other)
{
    pt->coefficient = pt->coefficient * other->coefficient;
    pt->power = pt->power + other->power;
}

void print(PolynomialTerm *pt)
{
    if (pt->coefficient > 0)
    {
        printf("+%dx^%d", pt->coefficient, pt->power);
        return;
    }

    printf("%dx^%d", pt->coefficient, pt->power);
}
