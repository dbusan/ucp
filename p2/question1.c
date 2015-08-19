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


