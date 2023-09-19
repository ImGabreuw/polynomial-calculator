#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 1000

void removeSpaces(char *str);

void polynomialInput(void);

int getHighestDegree(char polynomial[]);

char *standardization(char polynomial[]);

void removeSpaces(char *str);

void polynomialInput(void)
{
  char polynomial[MAX_SIZE];
  fgets(polynomial, MAX_SIZE, stdin);
}

int getHighestDegree(char polynomial[])
{
  int degree = 0;
  int currentDegree = 0;
  int length = strlen(polynomial);
  bool foundX = false;

  for (int i = 0; i < length; i++)
  {
    if (polynomial[i] == 'x' || polynomial[i] == 'X')
    {
      foundX = true;
    }
    else if (foundX && polynomial[i] == '^')
    {
      int j = i + 1;

      while (j < length && isdigit(polynomial[j]))
      {
        currentDegree = currentDegree * 10 + (polynomial[j] - '0');
        j++;
      }

      if (currentDegree > degree)
      {
        degree = currentDegree;
      }
      foundX = false;
      currentDegree = 0;
    }
  }

  if (degree == 0 && foundX)
  {
    return 1;
  }

  return degree;
}

char *standardization(char polynomial[])
{
  int currentPolynomialDegree = getHighestDegree(polynomial);
  char *stdPolynomial = (char *)malloc((2 * MAX_SIZE + 1) * sizeof(char));

  bool toSplit = true;
  int startIndex = -1;

  for (int i = 0; i <= strlen(polynomial); i++)
  {
    if (startIndex == -1)
    {
      startIndex = i;
    }

    if (!isspace(polynomial[i]) && polynomial[i] != '\0')
    {
      continue;
    }

    if (toSplit)
    {
      char temp[20];
      strncpy(temp, polynomial + startIndex, i - startIndex);
      temp[i - startIndex] = '\0';
      removeSpaces(temp);

      int termDegree = getHighestDegree(temp);
      int termCoefficient = atoi(temp) < 0 ? -atoi(temp) : atoi(temp);
      int termCoefficientSignal = isdigit(temp[0]) ? '+' : temp[0];

      char tempBuffer[20];
      snprintf(tempBuffer, sizeof(tempBuffer), "%c%dx^%d", termCoefficientSignal, termCoefficient, termDegree);
      strcat(stdPolynomial, tempBuffer);

      toSplit = false;
      startIndex = -1;
      continue;
    }

    toSplit = true;
  }

  return stdPolynomial;
}

void removeSpaces(char *str)
{
  int len = strlen(str);
  int i, j = 0;

  for (i = 0; i < len; i++)
  {
    if (str[i] != ' ')
    {
      str[j] = str[i];
      j++;
    }
  }

  str[j] = '\0';
}