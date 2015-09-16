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

