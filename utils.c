#include "utils.h"

void polynomialInput(void)
{
  char polynomial[MAX_SIZE];
  fgets(polynomial, MAX_SIZE, stdin);
}

int getHighestDegree(const char polynomial[])
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

char *standardization(const char polynomial[])
{
  int currentPolynomialDegree = getHighestDegree(polynomial);
  char *stdPolynomial = (char *)malloc((2 * MAX_SIZE + 1) * sizeof(char));
  stdPolynomial[0] = '\0';

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
      int termCoefficient = 1;
      char termCoefficientSignal = (temp[0] == '-') ? '-' : '+';

      // Verifica se há um valor numérico válido para o coeficiente
      if (isdigit(temp[0]) || isdigit(temp[1]))
      {
        termCoefficient = abs(atoi(temp));
      }

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

bool isEquals(char str1[], char str2[])
{
  int minSize = strlen(str1) <= strlen(str2) ? strlen(str1) : strlen(str2);

  for (int i = 0; i < minSize; i++)
  {
    if (str1[i] != str2[i])
    {
      return false;
    }
  }

  return true;
}

void init(PolynomialTerm polynomial[], int size)
{
  for (int i = 0; i < size; i++)
  {
    polynomial[i].coefficient = 0;
    polynomial[i].power = i;
  }
}

bool isSignal(char c)
{
  return c == '+' || c == '-';
}

bool isNumber(const char str[])
{
  for (int i = 0; i < strlen(str); i++)
  {
    if (!isdigit(str[i]))
      return false;
  }

  return true;
}