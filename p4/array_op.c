#include "array_op.h"
#include "stdlib.h"

int sum(int array[], int length)
{
	int i;
	int result=0;
	for(i=0;i<length;i++)
	{
		result += array[i];
	}

	return result;
}

int max(int array[], int length)
{
	int max_no = array[0];
	int i;
	for (i=1;i<length;i++)
	{
		if (max_no < array[i])
			max_no = array[i];
	}

	return max_no;
}

void reverse(int array[], int length)
{	
	int i;
	int *temp_array = malloc(length*sizeof(int));

	for (i = 0; i < length ; i++)
	{
		temp_array[i] = array[i];
	}

	for (i = 0 ; i < length ; i++)
	{
		array[i] = temp_array[length-i-1];
	}	
}


