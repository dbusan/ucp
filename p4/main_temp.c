#include <stdio.h>
#include <stdlib.h>
#include "array_op.h"
#include "str_conv.h"


#define LENGTH 5

int main(void)
{
/**	int sum_result; int nMax;
	int my_array[LENGTH] = {0, 5, 2, 3, 10};

	int i;

	sum_result = sum(my_array,LENGTH);
	nMax = max(my_array, LENGTH);

	printf("\nInitial array: ");
	for (i=0;i < LENGTH; i++)
	{
		printf("%d ",my_array[i]);
	}
	
	printf("\nSum: %d", sum_result);

	printf("\nMax: %d", nMax);

	reverse(my_array,LENGTH);
	printf("\nReversed array: ");
	for (i=0;i< LENGTH; i++)
	{
		printf("%d ",my_array[i]);
	}

	printf("\n"); **/

	/** Question 2
	*/
	
	int my_array[LENGTH];

	char* array[5] = { "15", "10", "12", "2", "1" };

	convert(array, my_array, LENGTH);

	int i;
	for (i = 0; i < LENGTH; i++)
	{
		printf("%d ", my_array[i]);
	}
	printf("\n");
	
	return 0;
}
