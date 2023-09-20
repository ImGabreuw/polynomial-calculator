#include <stdio.h>
#include <math.h>

#include "polynomial-term.h"

int solveOne(PolynomialTerm *pt, int x)
{
    if (pt->coefficient == 0)
    {
        return 0;
    }

    return pt->coefficient * pow(x, pt->power);
}

void sumOne(PolynomialTerm *pt, PolynomialTerm *other)
{
    if (pt->power == other->power)
    {
        pt->coefficient = pt->coefficient + other->coefficient;
    }
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
