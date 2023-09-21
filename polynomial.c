#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "polynomial-term.h"
#include "polynomial.h"
#include "utils.h"

void transform(PolynomialTerm pt[], char polynomial[])
{
  init(pt, MAX_DEGREE);
  int startIndex = 0;

  for (int i = 0; i <= strlen(polynomial); i++)
  {
    if (isSignal(polynomial[i]))
    {
      startIndex = i;
    }

    if (polynomial[i] == 'x')
    {
      int endIndex = i - 1;
      char tempCoefficient[20];
      char tempDegree[20];
      strncpy(tempCoefficient, polynomial + startIndex, endIndex - startIndex + 1);
      tempCoefficient[endIndex - startIndex + 1] = '\0';

      for (int j = i + 1; j <= strlen(polynomial); j++)
      {
        if (polynomial[j] == '^')
        {
          startIndex = j + 1;
          continue;
        }

        if (isSignal(polynomial[j]) || polynomial[j] == '\0')
        {
          endIndex = j - 1;
          strncpy(tempDegree, polynomial + startIndex, endIndex - startIndex + 1);
          tempDegree[endIndex - startIndex + 1] = '\0';
          break;
        }
      }

      int degree = atoi(tempDegree);
      pt[degree].coefficient = atoi(tempCoefficient);
      pt[degree].power = degree;

      startIndex = -1;
    }
  }
}

int solve(PolynomialTerm pt[], int x)
{
  int result = 0;

  for (int i = 0; i < MAX_DEGREE; i++)
  {
    result += solveOne(&pt[i], x);
  }

  return result;
}

void sum(PolynomialTerm pt1[], PolynomialTerm pt2[])
{
  for (int i = 0; i < MAX_DEGREE; i++)
  {
    sumOne(&pt1[i], &pt2[i]);
  }
}

void subtraction(PolynomialTerm pt1[], PolynomialTerm pt2[])
{
  for (int i = 0; i < MAX_DEGREE; i++)
  {
    subtractOne(&pt1[i], &pt2[i]);
  }
}

void multiplication(PolynomialTerm pt1[], PolynomialTerm pt2[])
{
  PolynomialTerm result[MAX_DEGREE];
  init(result, MAX_DEGREE);

  for (int i = 0; i < MAX_DEGREE; i++)
  {
    for (int j = 0; j < MAX_DEGREE; j++)
    {
      PolynomialTerm term = multiplyOne(&pt1[i], &pt2[j]);
      sumOne(&result[term.power], &term);
    }
  }

  for (int i = 0; i < MAX_DEGREE; i++)
  {
    pt1[i] = result[i];
  }
}

char *format(PolynomialTerm pt[])
{
  char *formatted = (char *)malloc(MAX_SIZE + 1);

  for (int i = MAX_DEGREE - 1; i >= 0; i--)
  {
    int coefficient = pt[i].coefficient;
    int power = pt[i].power;

    if (coefficient == 0 && power != 0)
      continue;

    char temp[20];
    temp[19] = '\0';
    snprintf(temp, sizeof(temp), "%+dx^%d", coefficient, power);
    strcat(formatted, temp);
  }

  formatted[MAX_SIZE] = '\0';
  return formatted;
}