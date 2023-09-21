#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "polynomial-term.h"

// ANSI escape code
#define GREEN_COLOR "\033[0;32m"
#define RED_COLOR "\033[0;31m"
#define DEFAULT_COLOR "\033[0m"

#define MAX_SIZE 1000

void removeSpaces(char *str);

void polynomialInput(void);

int getHighestDegree(const char polynomial[]);

char *standardization(const char polynomial[]);

void removeSpaces(char *str);

bool isEquals(char str1[], char str2[]);

void init(PolynomialTerm polynomial[], int size);

bool isSignal(char c);