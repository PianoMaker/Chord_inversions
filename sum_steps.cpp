#include"Notes.h"
int sum_steps(int step[], int numberofintervals)
{
	int sum = 0;
	for (int i = 0; i < numberofintervals; i++)
		sum += Stepdiff(step[i], step[i + 1]);
	return sum;

}