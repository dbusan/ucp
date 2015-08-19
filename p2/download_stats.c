#include <stdio.h>


int elapsedTime(int time, int startTime)
{
	return (time-startTime);
}

double percentComplete(double bytes, double totalBytes)
{
	return (bytes/totalBytes*100);
}

double downloadSpeed(int time, int startTime, double bytes)
{
	int mtime = elapsedTime(time, startTime);
	double result = bytes/mtime;

	return result;
}

double totalTime(int time, int startTime, double bytes, double totalBytes)
{
	return (totalBytes/(downloadSpeed(time, startTime, bytes)));
}

double remainingTime(int time, int startTime, double bytes, double totalBytes)
{
	return (totalTime(time, startTime, bytes, totalBytes)-elapsedTime(time, startTime));
}
