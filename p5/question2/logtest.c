#include "logtest.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int readlog( char logname[] )
{
	FILE* log;
	
	/** If file can't be opened, print an error and exit the function **/
	if ( (log = fopen( logname, "r" )) == NULL )
	{
		perror("\nError when opening logfile");
		return 0;
	}
	else /** logfile was succesfully opened **/
	{
		const int max_process_string_size = 20;
		const int max_message_string_size = 200;
	
		char month[4];
		int day;
		int time[3] = { 0, 0, 0 };

		char* process_name = (char*)malloc( max_process_string_size * sizeof(char));
		char* message = (char*)malloc ( max_message_string_size * sizeof(char));
		
		int done = 0;


		do { 
			/** Read date and time, and process name **/
			int ch;

			int i = 0;
			fscanf( log, "%s %d %d:%d:%d %s", month, &day, &time[0], &time[1], &time[2], process_name );
			printf("\nRead date n stuff \n");

			/** Read message**/
			do {
				ch = fgetc(log);
				message[i] = (char)ch; /** add character read to the message string **/
				i++;
				/** printf("\ni = %d",i); **/
			} while ((ch != '\n') || (ch != EOF)); /** While line isn't over and/or file still continues **/
			
			printf("\nstrstr\n");
			if ( strstr( message, "fail" ) != NULL)
			{
				int seconds = time[2] + time[1]*60 + time[0] * 60*60;
				printf("\nError happened %d seconds from midnight \n", seconds);

			}

			if (ch == EOF)
			{
				printf("\nEOF\n");
				done = 1;
			}
		} while ( !done );


		/** deallocate all memory, close files **/
		free(process_name);
		free(message);
		fclose(log);
		return 1;

	}
}
