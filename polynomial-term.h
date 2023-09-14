#include <stdio.h>

typedef struct
{
    int coefficient;
    int power;
} PolynomialTerm;

void sumOne(PolynomialTerm *pt, PolynomialTerm *other)
{
    pt->coefficient = pt->coefficient + other->coefficient;
    pt->power = pt->power + other->power;
}

void subtractionOne(PolynomialTerm *pt, PolynomialTerm *other)
{
    pt->coefficient = pt->coefficient - other->coefficient;
    pt->power = pt->power - other->power;
}

void multiplicationOne(PolynomialTerm *pt, PolynomialTerm other[])
{
    pt->coefficient = pt->coefficient - other->coefficient;
    pt->power = pt->power - other->power;
}

void print(PolynomialTerm *pt)
{
    printf("%dx^%d", pt->coefficient, pt->power);
}