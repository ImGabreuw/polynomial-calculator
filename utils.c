#include "utils.h"

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