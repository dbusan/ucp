#include <stdlib.h>


/** Function definition
 * Blah blah blah
 * Date: {Today}
 *
 */


void convert(char* strings[], int numbers[], int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		numbers[i] = atoi(strings[i]);
	}
}


void print_array(int numbers[], int length)
{
	int i = 0;
	printf("{");
	for (i = 0; i < length; i++)
	{
		printf("%d", numbers[i]);
		if (i == (length-1))
			printf("}");
		else
			printf(", ");
	}



}

