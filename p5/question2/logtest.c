#include "logtest.h"
#include <string.h>


int readlog( char[] logname )
{
	*FILE log;
	
	/** If file can't be opened, spit out an error **/
	if ( log = fopen( logname, "r" ) == NULL )
	{
		printf("\nError when opening logfile\n");
		return 0;
	}
	else
	{


		return 1;

	}
}
