#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "polynomial-term.h"

#define MAX_SIZE_TERM 10

PolynomialTerm polynomial1[MAX_SIZE_TERM];

PolynomialTerm polynomial2[MAX_SIZE_TERM];

void transform(char polynomial1[], char polynomial2[]);

void transform(char polynomial1[], char polynomial2[])
{
  int startIndex = 0;

  for (int i = 0; i <= strlen(polynomial1); i++)
  {
    if (polynomial1[i] == '+' || polynomial1[i] == '-')
    {
      startIndex = i;
    }

    if (polynomial1[i] == 'x')
    {
      int endIndex = i - 1;
      char tempCoef[20];
      char tempDegree[20];
      strncpy(tempCoef, polynomial1 + startIndex, endIndex - startIndex);
      tempCoef[endIndex - startIndex] = '\0';

      for (int j = i + 1; j <= strlen(polynomial1); j++)
      {
        if (polynomial1[j] == '^')
        {
          startIndex = j + 1;
          continue;
        }

        if (polynomial1[j] == '+' || polynomial1[j] == '-' || polynomial1[j] == '\0')
        {
          endIndex = j - 1;
          printf("%d %d\n", startIndex, endIndex);
          strncpy(tempDegree, polynomial1 + startIndex, endIndex - startIndex);
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