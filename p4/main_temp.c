#include <stdio.h>

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
		array[i] = temp_array[length-i];
	}	
}



int main(void)
{
	int sum_result; int nMax;
	int length = 5;
	int my_array[length] = {0, 5, 2, 3, 10}

	sum_result = sum(my_array, length);
	nMax = max(my_array, length);

	for (i=0;i < length; i++)
	{
		
	}
	
	
	
	return 0;
}
