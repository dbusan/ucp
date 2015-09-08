#include "order.h"
#include <sdtlib.h>

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

/** order() function
	Takes single char as parameter, returns function pointer;
	A is passed -> pointer to ascending3(), D is passed, returned descending3();
	Else NULL;
	t_ordering	
**/

t_ordering order(char order_type)
{
	if (order_type == 'A' || order_type == 'a')
	{
		return &ascending3;
	}
	else if (order_type == 'D' || order_type == 'd')
		return &descending3;
	else
		return NULL;

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


