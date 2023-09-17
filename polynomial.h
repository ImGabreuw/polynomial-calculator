#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "polynomial-term.h"

#define MAX_SIZE_TERM 10

PolynomialTerm polynomial1[MAX_SIZE_TERM];

PolynomialTerm polynomial2[MAX_SIZE_TERM];

void transform(PolynomialTerm pt[], char polynomial[]);

void transform(PolynomialTerm pt[], char polynomial[])
{
  int startIndex = 0;

  for (int i = 0; i <= strlen(polynomial); i++)
  {
    if (polynomial[i] == '+' || polynomial[i] == '-')
    {
      startIndex = i;
    }

    if (polynomial[i] == 'x')
    {
      int endIndex = i - 1;
      char tempCoef[20];
      char tempDegree[20];
      strncpy(tempCoef, polynomial + startIndex, endIndex - startIndex);
      tempCoef[endIndex - startIndex] = '\0';

      for (int j = i + 1; j <= strlen(polynomial); j++)
      {
        if (polynomial[j] == '^')
        {
          startIndex = j + 1;
          continue;
        }

        if (polynomial[j] == '+' || polynomial[j] == '-' || polynomial[j] == '\0')
        {
          endIndex = j - 1;
          printf("%d %d\n", startIndex, endIndex);
          strncpy(tempDegree, polynomial + startIndex, endIndex - startIndex);
          tempDegree[endIndex - startIndex] = '\0';
          break;
        }
      }

      int coef = atoi(tempCoef);
      int degree = atoi(tempDegree);

      startIndex = -1;
    }
  }
}