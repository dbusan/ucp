/**
Filename:   question3.c
Date:       13/08/2015
Author:     Daniel C. Busan

Description:
**/

#include <stdio.h>

int factorial (int);

int main(void)
{
  int n;
  do {
    printf("\nEnter a number:\n> ");
    scanf("%d", &n);
    if (n < 0)
    {
      printf("Number is negative. Please try again\n" );
    }
  } while (n<1);
  printf("\n%d! = %d\n", n, factorial(n));
  return 0;
}

int factorial(int n) // function that computes the factorial of n
{
  int result = 1;
  int i;

  for (i = 1; i <= n; i++)
  {
    result *= i;  // even if n is zero, the returned value
                  // is 1
  }
  return result;
}
