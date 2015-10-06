#include "logtest.h"
#include <string.h>


int readlog( char[] logname )
{
	*FILE log;
	
	/** If file can't be opened, print an error and exit the function **/
	if ( log = fopen( logname, "r" ) == NULL )
	{
		printf("\nError when opening logfile\n");
		return 0;
	}
	else /** logfile was succesfully opened **/
	{



		return 1;

	}
}
