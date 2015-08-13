//Aidan was here

#include <stdio.h>

int main(void)
{
	int a,b;
	
	printf("Enter 2 integers\n> "); scanf("%d %d", &a, &b);
	
	if (a % b == 0)
	{
		printf("Divisible \n");
	}
	else
		printf("Not divisible \n");
	return 0;
}
