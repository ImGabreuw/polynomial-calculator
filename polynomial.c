#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "polynomial-term.h"
#include "polynomial.h"

#define MAX_SIZE_TERM 10

void transform(PolynomialTerm pt[], char polynomial[])
{
  int startIndex = 0;

  for (int i = 0; i < MAX_SIZE_TERM; i++)
  {
    pt[i].coefficient = 0;
    pt[i].power = i;
  }

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
      strncpy(tempCoef, polynomial + startIndex, endIndex - startIndex + 1);
      tempCoef[endIndex - startIndex + 1] = '\0';

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
          strncpy(tempDegree, polynomial + startIndex, endIndex - startIndex + 1);
          tempDegree[endIndex - startIndex + 1] = '\0';
          break;
        }
      }

      int degree = atoi(tempDegree);
      pt[degree].coefficient = atoi(tempCoef);
      pt[degree].power = degree;

      startIndex = -1;
    }
  }
}