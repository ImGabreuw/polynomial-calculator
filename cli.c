#include "cli.h"

int cli(int argc, char const *argv[])
{
    if (!isValidArgs(argc, argv)) {
        help(argv[0]);
    }

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

        free(polynomial);
        return 0;
    }

    char *expectedResult = standardization(argv[2]);

    char *polynomial1 = standardization(argv[3]);
    PolynomialTerm pt1[MAX_DEGREE];
    transform(pt1, polynomial1);

    char *polynomial2 = standardization(argv[4]);
    PolynomialTerm pt2[MAX_DEGREE];
    transform(pt2, polynomial2);

    if (option == 2)
    {
        sum(pt1, pt2);
    }

    if (option == 3)
    {
        subtraction(pt1, pt2);
    }

    if (option == 4)
    {
        multiplication(pt1, pt2);
    }

    char *formatted = format(pt1);

    if (!isEquals(expectedResult, formatted))
    {
        printf("%sTeste não passou. Valor esperado era de %s, mas foi obtido %s.%s\n", RED_COLOR, expectedResult, formatted, DEFAULT_COLOR);
        return 1;
    }

    printf("%sTeste passou. Valor esperado era de %s e foi obtido %s.%s\n", GREEN_COLOR, expectedResult, formatted, DEFAULT_COLOR);

    free(formatted);
    free(polynomial1);
    free(polynomial2);

    return 0;
}

void help(const char programName[])
{
    puts("----------------------------------------- HELP -----------------------------------------");
    printf("Uso: %s [opção] [argumentos] \n", programName);
    printf("- Resolver polinômio               %s 1 [resultado esperado] [valor de X] [polinômio] \n", programName);
    printf("- Soma de polinômios               %s 2 [resultado esperado] [polinômio] [polinômio] \n", programName);
    printf("- Subtração de polinômios          %s 3 [resultado esperado] [polinômio] [polinômio] \n", programName);
    printf("- Multiplicação de polinômios      %s 4 [resultado esperado] [polinômio] [polinômio] \n", programName);
    puts("----------------------------------------------------------------------------------------");
}

bool isValidArgs(int argc, char const *argv[])
{
    if (argc == 5)
        return true;

    if (isdigit(argv[1]) && atoi(argv[1]) > 0 && atoi(argv[1]) <= 4)
        return true;

    return false;
}