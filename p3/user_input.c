#include "order.h"
#include "user_input.h"

void readInts(int* a, int* b, int* c, char *letter)
{
	printf("\nEnter 3 numbers and A or D for ascending or descending:\n > ");
	scanf("%d %d %d %c",a,b,c,letter);

	order(*letter);
}

