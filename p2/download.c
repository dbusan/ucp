/* This code is part of Worksheet 2 (for UCP 120). */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  /* <-- Actually part of UNIX rather than C; needed for the sleep() function. */

#include "download_stats.h"

#define MIN_DOWNLOAD_SIZE 0
#define MAX_DOWNLOAD_SIZE 1000000
#define MIN_DOWNLOAD_RATE 50000
#define MAX_DOWNLOAD_RATE 100000

int main(void)
{
    int currentTime, startTime, bytes, totalBytes;

    srand(time(NULL));
    startTime = rand();
    totalBytes = MIN_DOWNLOAD_SIZE + rand() % (MAX_DOWNLOAD_SIZE - MIN_DOWNLOAD_SIZE);

    printf("startTime == %d, totalBytes == %d\n(Press Ctrl-C to exit)\n", startTime, totalBytes);

    currentTime = startTime;
    bytes = 0;
    do
    {
        sleep(1);
        bytes += MIN_DOWNLOAD_RATE + rand() % (MAX_DOWNLOAD_RATE - MIN_DOWNLOAD_RATE);
        if(bytes > totalBytes)
        {
            bytes = totalBytes;
        }
        currentTime++;

	#ifdef ALL_STATS
        printf("\ntime == %d, bytes == %d\n-------------------\n", currentTime, bytes);

        printf("elapsedTime: %d seconds\n", elapsedTime(currentTime, startTime));
        printf("percentComplete: %.2f%%\n", percentComplete((double)bytes, (double)totalBytes));
        printf("downloadSpeed: %.2f bytes/second\n", downloadSpeed(currentTime, startTime, (double)bytes));
        printf("totalTime: %.2f seconds\n", totalTime(currentTime, startTime, (double)bytes, (double)totalBytes));
	#endif
	printf("remainingTime: %.2f seconds\n", remainingTime(currentTime, startTime, (double)bytes, (double)totalBytes));
    }
    while(bytes < totalBytes);

    return 0;
}
