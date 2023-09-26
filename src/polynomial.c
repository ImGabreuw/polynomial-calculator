#include "../include/polynomial.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "../include/polynomial-term.h"
#include "../include/utils.h"
#include "../include/polynomial-utils.h"

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

    if (foundX && polynomial[i] == '^')
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

void print(PolynomialTerm pt[])
{
  int countCoefficient0 = 0;


  for (int i = MAX_DEGREE - 1; i >= 0; i--)
  {
    int coefficient = pt[i].coefficient;

    if (coefficient == 0 && ++countCoefficient0 != MAX_DEGREE)
      continue;

    printOne(&pt[i]);
  }
}