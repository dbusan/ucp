#include "logtest.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int readlog( char logname[] )
{
	FILE* log;
	int c;
	
	/** If file can't be opened, print an error and exit the function **/
	if ( (log = fopen( logname, "r" )) == NULL )
	{
		perror("\nError when opening logfile");
		return 0;
	}
	else /** logfile was succesfully opened **/
	{
		const int max_process_string_size = 60;
		const int max_message_string_size = 600; 
	
		char month[4];
		int day;
		int time[3] = { 0, 0, 0 };

		char* process_name = (char*)malloc( max_process_string_size * sizeof(char));
		char* message = (char*)malloc ( max_message_string_size * sizeof(char));
		

		int done = 0;

		/** 
			Next two loops initialize the heap-allocated arrays to 0;
			These two arrays store the process name and Message that follows		
		**/

		for ( c = 0; c < max_message_string_size; c++)
		{
			message[c] = 0;
		}

		for ( c = 0; c < max_process_string_size; c++)
		{
			process_name[c] = 0;
		}

		do { 
			/** Read date and time, and process name **/
			int ch;

			
			char * temp;

			int row_has_ended = 0;
			int i = 0;
			fscanf( log, "%s %d %d:%d:%d %s", month, &day, &time[0], &time[1], &time[2], process_name );

			/** Read message**/
			do {
				ch = fgetc(log);
				message[i] = (char)ch; /** add character read to the message string **/
				i++;
				
				/** 
					This section could be in the while() statement at the very end 
					but it wouldn't work for some reason so it was moved here
				**/
				if (ch == '\n')
				{
					row_has_ended = 1;
				}

				if (ch == EOF)
				{
					row_has_ended = 1;
					done = 1;
				}
				/** ------------------------------ **/
				
			} while ( !row_has_ended ); /** While line isn't over and/or file still continues **/
			

			if ( (temp=strstr( message, "fail" )) != NULL)
			{
				int seconds = time[2] + time[1]*60 + time[0] * 60*60;
				printf("\nError happened %d seconds from midnight %d %s \n", seconds, day, month );

			}
		} while ( !done );


		/** deallocate all memory, close files **/
		free(process_name);

		free(message);
		fclose(log);
		return 1;

	}
}
