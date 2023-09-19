#include <stdio.h>
#include <math.h>

#include "polynomial-term.h"

int resolveOne(PolynomialTerm *pt, int x)
{
    return (int) pow(pt->coefficient * x, pt->power);
}

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
    if (pt->coefficient >= 0)
    {
        printf("+%dx^%d", pt->coefficient, pt->power);
        return;
    }

    printf("%dx^%d", pt->coefficient, pt->power);
}
