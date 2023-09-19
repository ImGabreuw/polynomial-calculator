#include <stdio.h>
#include "utils.h"
#include "polynomial.h"

int main(int argc, char const *argv[])
{
    char *polynomial = standardization("-2x^2 + 2x");

    printf("%s\n", polynomial);

    PolynomialTerm pt[MAX_DEGREE];
    transform(pt, polynomial);

    printf("%d\n", solve(pt, 2));

    return 0;
}