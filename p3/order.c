#include "order.h"

static void ascending2(int *a, int *b)
{
	int temp = *a;
	if (*a > *b)
	{
		*a = *b;
		*b = temp;
	}
}

static void descending2(int *a, int *b)
{
	int temp = *a;
	if (*a < *b)
	{
		*a = *b;
		*b = temp;
	}
}



void ascending3(int *a, int *b, int *c)
{
	
	ascending2(a, b);
	ascending2(a, c);
	ascending2(b, c);
}

void descending3(int *a, int *b, int *c)
{
	descending2(a, b);
	descending2(a, c);
	descending2(b, c);

}


