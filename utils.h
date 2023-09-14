#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE_EACH_TERM 6
#define MAX_SIZE (SIZE_EACH_TERM * 10)

void polynomialInput(void)
{
  char polynomial[MAX_SIZE];
  fgets(polynomial, MAX_SIZE, stdin);
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

char *split(char str[], char delimiters[])
{
  int size = SIZE_EACH_TERM * countSpaces(str);
  char *splitted = (char *)malloc(size * sizeof(char));
  
  bool toSplit = true;

  for (int i = 0; i < strlen(str); i++)
  {
    if (!isspace(str[i]))
      continue;

    if (toSplit)
    {


      toSplit = false;
      continue;
    }

    toSplit = true;
  }

  return 
}
