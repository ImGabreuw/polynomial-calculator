#include <stdio.h>
#include "utils.h"
#include "polynomial.h"

int cli(int argc, char const *argv[]);

int main(int argc, char const *argv[])
{
    if (argc > 0)
    {
        cli(argc, argv);
    }

    return 0;
}

int cli(int argc, char const *argv[])
{
    int option = atoi(argv[1]);

    if (option == 1)
    {
        int expectedResult = atoi(argv[2]);
        int x = atoi(argv[3]);
        char *polynomial = standardization(argv[4]);
        PolynomialTerm pt[MAX_DEGREE];
        transform(pt, polynomial);
        int result = solve(pt, x);

        if (expectedResult != result)
        {
            printf("%sTeste não passou. Valor esperado era de %d, mas foi obtido %d.%s\n", RED_COLOR, expectedResult, result, DEFAULT_COLOR);
            return 1;
        }

        printf("%sTeste passou. Valor esperado era de %d e foi obtido %d.%s\n", GREEN_COLOR, expectedResult, result, DEFAULT_COLOR);
        return 0;
    }

    return 0;
}