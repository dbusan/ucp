/**
	Date: 5th of October 2015
	Author: Daniel C. Busan
	
	Prac5: Question2: logfile reader

**/

#include <stdio.h>
#include "logreader.h"
#include "logtest.h"

int main(int argc, char* argv[])
{
	
	if (argc < 2)
	{
		printf("\nNo logfile name specified\n");
	}
	else
	{
		readlog(argv[1]);
	}
	return 0;
}




