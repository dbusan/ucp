/*
Question 1 of Prac2;
Write a C function to calculate powers of 2. Your function should take no parameters.
Each time it is called, the function should return the next power of two in sequence.
Called  once,  your  function  should  return  2.
Called  a  second  time,  your  function should return 4, then 8, then 16, then 32, etc.

Note: Use local variables only, not global variables. Once your function is finished, write a main() function to test it.
*/

#include <stdio.h>

void count();

int main()
{
        int i;
        for (i=0;i<10;i++)
                count();
        return 0;
}

void count(void)
{
        static int counter = 2;
        counter = counter*2;
        printf("%d\n",counter);
}
