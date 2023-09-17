#include <stdio.h>
#include "utils.h"
#include "polynomial.h"

int main(int argc, char const *argv[])
{
    char *polynomial = standardization("-42x^6 + 6x^4 - 28x^2 + 3x + 124");

    int index = 0;
    while (polynomial[index] != '\0')
    {
        printf("%c", polynomial[index]);
        index++;
    }
    
    printf("\n");

    transform(polynomial, NULL);

    return 0;
}

