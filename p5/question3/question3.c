/**
 *	Question 3: Read a 2d Array
 *	reads data from text file into 2d array;
 *	passes array to plot() function (already declared in plot.h). 

 *	
 *	Input file: 
 *		first line 2 ints: separate by space; No. rows and columns in array;
 		each subsequent line  =1 row; space separate list of real numbers, one for each column;
 		
 *	
 	a) accept filename as commandline parameter
 	b) after reading the first line allocate  a 2d array of req. size
 	c) read in all values and fill in the array;
 	d) pass the array, row count and column count to the plot function;
 	e) perform approppriate error checking and cleaning up;
**/

#include <stdio.h>
#include <stdlib.h>

#include "plot.h"


int main(int argc, char* argv[])
{
	
	/* Checks if filename has been passsed as argument */
	if (argc < 2) 
	{
		printf("Usage: ./display filename\n");
	}
	else
	{
		FILE *in;

		double **data;
		int rows, columns;
		int i,j;

		if ( (in = fopen(argv[1],"r")) == NULL)
		{
			printf("Could not open file.\n");
		}
		else
		{	

			fscanf(in, "%d %d", &rows, &columns);
			

			/* Allocate memory on the heap for the 2d array */
			data = (double**)malloc(rows*sizeof(double*));
			for ( i=0; i < rows; i++)
			{
				data[i] = (double*)malloc(columns*sizeof(double));
			}
			if (data == NULL) /* could not allocate memory */
			{
				printf("Could not allocate memory for data array\n");
			}
			else
			{
				/* Read from the file, row by row*/
				for( i = 0; i < rows; i++)
				{
					for( j = 0; j < columns; j++)
					{
						/* This checks if it's the last element in the row, then it doesn't need the space separator. */
						if (j == columns-1)
							fscanf(in, "%lf\n", &data[i][j]); 
						else
							fscanf(in, "%lf", &data[i][j]);
					}
				}
			}

			if (ferror(in))
			{
				printf("\nAn error occurred while file was read\n");

			}

			plot(data, rows, columns);


			/** Deallocate memory **/
			for (i = 0; i < rows; i++)
			{
				free(data[i]);
			}
			free(data);

			fclose(in);
			
		}
		

	}


	
	return 0;
}
