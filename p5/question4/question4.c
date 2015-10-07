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

	if (argc < 2)
	{
		printf("Usage: generate [filename] [rows] [columns]\n");
	}
	else
	{
		FILE* out;
		double** data;

		const int rows = argv[2]; 
		const int columns = argv[3];

		int i;
		int j;

		if ( (out = fopen(argv[1], "w") == NULL))
		{
			printf("\nCould not open output file. Check privileges\n");
		}
		else
		{

			/* Allocate memory for the arrays */
			data = (*double)malloc( rows*sizeof(*double));
			if (data == NULL)
				printf("Memory allocation failed\n");
			else
			{
				for ( i = 0; i < rows; i++)
				{
					data[i] = (double)malloc(columns*sizeof(double));
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
							fprintf( out, "%d\n", data[i][j]);
						else
							fprintf( out, "%d ", data[i][j]);
					}
				}

				if (ferror(out))
					printf("Some error was encountered when handling the output file\n");

				

				/* Deallocate memory */
				free(data);
				for ( i = 0; i < rows; i++)
				{
					free(data[i]);
				}
			}
			fclose(out);
		}


	}

	return 0;
}
