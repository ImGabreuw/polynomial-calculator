#include <stdio.h>
#include "utils.h"

int main(int argc, char const *argv[])
{
    char *polynomial = standardization("4x^6 + 3x^5 - 6x^3 - 8x^2 + 3x + 4");

    int index = 0;
    while (polynomial[index] != '\0')
    {
        printf("%c", polynomial[index]);
        index++;
    }
    
    printf("\n");

    return 0;
}

