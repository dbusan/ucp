#include <stdio.h>
#include "order.h"
#include "user_input.h"

int main(void)
{
/*	int a = 3, b = 5, c = 10; */
	int a,b,c;
	char e;
	readInts(&a,&b,&c,&e );
	/*
	printf("\nInitially: a = %d, b = %d, c = %d",a, b, c);
	
	ascending3( &a , &b, &c);
	printf("\nAfter running ascending: a = %d, b = %d, c = %d", a, b, c);

	descending3( &a, &b, &c);
	*/

	printf("\nAfter running ascending3: a = %d, b = %d, c = %d\n", a, b, c);

	return 0;

}
