#include "../include/polynomial-term.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int solveOne(const PolynomialTerm *pt, int x)
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
    if (pt->power == other->power)
    {
        pt->coefficient = pt->coefficient - other->coefficient;
    }
}

PolynomialTerm multiplyOne(PolynomialTerm *pt, PolynomialTerm *other)
{
    PolynomialTerm term;

    term.coefficient = pt->coefficient * other->coefficient;
    term.power = pt->power + other->power;

    return term;
}

void printOne(const PolynomialTerm *pt)
{
    if (pt->coefficient >= 0)
    {
        if (pt->power == 0)
        {
            printf(" + %d", pt->coefficient);
            return;
        }
        
        if (pt->power == 1)
        {
            printf(" + %dx", pt->coefficient);
            return;
        }

        printf(" + %dx^%d", pt->coefficient, pt->power);
        return;
    }

    if (pt->power == 0)
    {
        printf(" - %d", abs(pt->coefficient));
        return;
    }

    if (pt->power == 1)
    {
        printf(" - %dx", abs(pt->coefficient));
        return;
    }
    
    printf(" - %dx^%d", abs(pt->coefficient), pt->power);
}
