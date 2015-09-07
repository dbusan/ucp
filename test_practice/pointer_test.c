#include <stdio.h>

int main(void)
{
	float e = 2.0;
	float f = 0.5;
	float* g = NULL;
	float* h = NULL;
	float* i = NULL;
	float** v = NULL;
	float** w = NULL;

/**	h = &e;
	v = &h;
	w = v;
	i = *w;
	v = &g;
	g = &f;
	*v = h;
	**w = **v * **v;**/
	int j;
	v = &g;
	w = &h;	
	*v = &e;
	*w = &f;
	i = *v;
	
	for(j = 0; j < **w; j++) {
		*i = -*i;
	}
	
	**w = -**v;

	printf("\nE = %f; F = %f; \n", e, f);
	
	return 0;

}

