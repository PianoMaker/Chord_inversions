#include "Notes.h"
float Sharpness(int enterstep, int alter) // вводиться step, alter 
{
	float sharpness;

	while (enterstep > 6) enterstep -= 7;
	if (enterstep == FA) sharpness = -3;
	else if (enterstep == DO) sharpness = -2;
	else if (enterstep == SOL) sharpness = -1;
	else if (enterstep == RE) sharpness = 0;
	else if (enterstep == LA) sharpness = 1;
	else if (enterstep == MI) sharpness = 2;
	else if (enterstep == SI) sharpness = 3;
	else sharpness = 0;

	if (alter) sharpness += alter * 7;

	return sharpness;

}