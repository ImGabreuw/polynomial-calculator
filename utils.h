#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 1000

void removeSpaces(char *str);

void polynomialInput(void);

int getHighestDegree(char polynomial[]);

int countSpaces(char str[]);

char *standardization(char polynomial[]);

void removeSpaces(char *str);

void polynomialInput(void)
{
  char polynomial[MAX_SIZE];
  fgets(polynomial, MAX_SIZE, stdin);
}

int getHighestDegree(char polynomial[])
{
  char highestDegree[20];

  for (int i = 0; i < strlen(polynomial); i++)
  {
    if (polynomial[i] != '^')
      continue;

    int degreeStartIndex = i + 1;
    int degreeLastIndex = 0;

    for (int j = degreeStartIndex; j < strlen(polynomial); j++)
    {
      if (!isspace(polynomial[j]))
        continue;

      degreeLastIndex = j;
      break;
    }

    strncpy(highestDegree, polynomial + degreeStartIndex, degreeLastIndex - degreeStartIndex);
    highestDegree[degreeLastIndex - degreeStartIndex] = '\0';

    return atoi(highestDegree);
  }

  return 0;
}

int countSpaces(char str[])
{
  int count = 0;

  for (int i = 0; i < strlen(str); i++)
  {
    if (isspace(str[i]))
    {
      ++count;
    }
  }

  return count;
}

char *standardization(char polynomial[])
{
  int index = 0;
  char *stdPolynomial = (char *)malloc(2 * MAX_SIZE * sizeof(char));
  int currentPolynomialDegree = getHighestDegree(polynomial);

  bool toSplit = true;
  int startIndex = -1;

  for (int i = 0; i <= strlen(polynomial); i++)
  {
    if (startIndex == -1)
    {
      startIndex = i;
    }

    if (!isspace(polynomial[i]) && polynomial[i] != '\0')
      continue;

    if (toSplit)
    {
      char temp[20];
      strncpy(temp, polynomial + startIndex, i - startIndex);
      temp[i - startIndex] = '\0';
      removeSpaces(temp);

      if (getHighestDegree(temp) != currentPolynomialDegree)
      {
        for (int j = getHighestDegree(temp) + 1; j <= currentPolynomialDegree; j++)
        {
          char tempBuffer[20];
          snprintf(tempBuffer, sizeof(tempBuffer), "+0x^%d", j);
          strcat(stdPolynomial, tempBuffer);
          --currentPolynomialDegree;
        }
      }

      strcat(stdPolynomial, temp);
      --currentPolynomialDegree;

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