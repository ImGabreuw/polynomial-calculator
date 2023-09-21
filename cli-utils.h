#include <stdio.h>
#include <stdbool.h>

void menu();

int inputInt(const char message[]);

void inputPolynomial(char *polynomial, int size, const char message[]);

bool isValidArgs(int argc, char const *argv[]);