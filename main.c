#include <stdio.h>
#include "utils.h"
#include "polynomial.h"

int main(int argc, char const *argv[])
{
    char *polynomial = standardization("-42x^6 + 6x^4 - 28x^2 + 3x + 124");
    PolynomialTerm pt[10];

    transform(pt, polynomial);

    for (int i = 0; i < 10; i++) {
        print(&pt[i]);
    }

    return 0;
}

