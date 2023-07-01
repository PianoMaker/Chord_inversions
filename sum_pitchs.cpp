#include"Notes.h"
int sum_pitchs(int pitch[], int NoI)
{
	int sum = 0;
	for (int i = 0; i < NoI; i++)
		sum += Pitchdiff(pitch[i], pitch[i + 1]);
	return sum;

}