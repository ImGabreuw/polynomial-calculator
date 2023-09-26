#include "../include/cli.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../include/utils.h"
#include "../include/cli-utils.h"
#include "../include/polynomial-utils.h"
#include "../include/polynomial.h"

void cli(int argc, char const *argv[])
{
    char polynomial1[MAX_SIZE], polynomial2[MAX_SIZE];
    PolynomialTerm pt1[MAX_DEGREE], pt2[MAX_DEGREE];
    int option, x;
    bool exit = false;

    do
    {
        menu();
        option = inputInt("Selecione uma opção: ");

        if (option == 5)
            continue;

        if (option > 5 || option <= 0)
        {
            puts("Opção inválida.");
            continue;
        }

        inputPolynomial(polynomial1, MAX_SIZE, "Digite o polinômio P(x): ");
        char *stdPolynomial1 = standardization(polynomial1);
        transform(pt1, stdPolynomial1);

        if (option == 1)
        {
            x = inputInt("Digite o valor de x: ");

            int result = solve(pt1, x);

            printf("O resultado de %s para x = %d é %d.\n", polynomial1, x, result);
            continue;
        }

        char operation;
        inputPolynomial(polynomial2, MAX_SIZE, "Digite o polinômio Q(x): ");
        char *stdPolynomial2 = standardization(polynomial2);
        transform(pt2, stdPolynomial2);

        if (option == 2)
        {
            operation = '+';
            sum(pt1, pt2);
        }

        if (option == 3)
        {
            operation = '-';
            subtraction(pt1, pt2);
        }

        if (option == 4)
        {
            operation = '*';
            multiplication(pt1, pt2);
        }

        printf("O resultado de (%s) %c (%s) é", polynomial1, operation, polynomial2);
        print(pt1);
        printf(".\n");

        free(stdPolynomial1);
        free(stdPolynomial2);
    } while (option != 5);

    puts("Encerrando programa...");
}

void test(int argc, char const *argv[])
{
    if (!isValidArgs(argc, argv))
    {
        help(argv[0]);
        return;
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
            return;
        }

        printf("%sTeste passou. Valor esperado era de %d e foi obtido %d.%s\n", GREEN_COLOR, expectedResult, result, DEFAULT_COLOR);

        free(polynomial);
        return;
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
        return;
    }

    printf("%sTeste passou. Valor esperado era de %s e foi obtido %s.%s\n", GREEN_COLOR, expectedResult, formatted, DEFAULT_COLOR);

    free(formatted);
    free(polynomial1);
    free(polynomial2);

    return;
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