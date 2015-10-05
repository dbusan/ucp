/*
	Program that copies one file to the other
		
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE* fin;
	FILE* fout;

	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");

	if (fin == NULL)
	{
		printf("Cannot open source file.\n");
	}
	else if (fout == NULL)
	{
		printf("Cannot open destination file\n");
		fclose(fin);
	}
	else // both files properly opened.
	{
		int char_buffer;
		
		while ((char_buffer = fgetc(fin)) != EOF)
		{			
			fputc( (char) char_buffer, fout );
		}
	

		fclose(fin);
		fclose(fout);
	}

	return 0;
	
	
}
