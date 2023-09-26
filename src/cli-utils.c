#include "../include/cli-utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils.h"

void menu()
{
  puts("------------------------------- MENU -------------------------------");
  puts("1 - Resolver polinômio");
  puts("2 - Somar polinômios");
  puts("3 - Subtrair polinômios");
  puts("4 - Multiplicar polinômios");
  puts("5 - Sair");
  puts("--------------------------------------------------------------------");
}

int inputInt(const char message[])
{
  char raw[10];

  if (message != NULL)
  {
    fputs(message, stdout);
  }

  fgets(raw, 10 * sizeof(char), stdin);
  return atoi(raw);
}

void inputPolynomial(char *polynomial, int length, const char message[])
{

  if (message != NULL)
  {
    printf(message, stdout);
  }

  fgets(polynomial, length * sizeof(char), stdin);
  polynomial[strlen(polynomial) - 1] = '\0'; // remove new line
}

bool isValidArgs(int argc, char const *argv[])
{
  if (argc != 5)
    return false;

  if (!isNumber(argv[1]))
    return false;

  if (atoi(argv[1]) <= 0 || atoi(argv[1]) > 4)
    return false;

  return true;
}