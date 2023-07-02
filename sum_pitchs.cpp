#include"Notes.h"
int sum_pitchs(int pitch[], int numberofintervals)
{
	int sum = 0;
	for (int i = 0; i < numberofintervals; i++)
		sum += Pitchdiff(pitch[i], pitch[i + 1]);
	return sum;

}