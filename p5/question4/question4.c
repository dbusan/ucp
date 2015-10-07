/*
   Accepts 3 parameters: filename, 2 ints representing rows and cols
   allocate 2d array of req. size
   pass array to randomarray() 
   write array to file
   implement error handling, memory cleaning */

#include <stdio.h>
#include <stdlib.h>
#include "randomarray.h"

int main(int argc, char* argv[])
{

	if (argc < 3)
	{
		printf("Usage: generate [filename] [rows] [columns]\n");
	}
	else
	{
		FILE* out;
		double **data;

		int rows = atoi(argv[2]); 
		int columns = atoi(argv[3]);

		const char* filename = argv[1];

		int i;
		int j;

		if ( (out = fopen(filename, "w")) == NULL)
		{
			printf("\nCould not open output file. Check privileges\n");
		}
		else
		{
			/* Allocate memory for the arrays */
			data = (double**)malloc( rows*sizeof(double*));
			if (data == NULL)
				printf("Memory allocation failed\n");
			else
			{
				for ( i = 0; i < rows; i++)
				{
					data[i] = (double*)malloc(columns*sizeof(double));
				}

				randomArray(data, rows, columns, 5);

				fprintf(out, "%d %d\n", rows, columns);
				
				for (i = 0; i < rows; i++)
				{
					for ( j = 0; j < columns; j++)
					{
						/* Checks if it's the last element in the row. If so, adds the newline character in the file 
						 Could also be done after the loop ends, but then I'd have to handle the spacing differently */
						if (j == columns-1)
							fprintf( out, "%f\n", data[i][j]);
						else
							fprintf( out, "%f ", data[i][j]);
					}
				}

				if (ferror(out))
					printf("Some error was encountered when handling the output file\n");

				

				/* Deallocate memory */
				for ( i = 0; i < rows; i++)
				{
					free(data[i]);
				}

				free(data);
			}
			fclose(out);
		}


	}

	return 0;
}
