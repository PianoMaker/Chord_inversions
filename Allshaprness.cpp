#include "CM.h"

float Allsharpness(float* sharpness, int NoN)
{
	float allsharpness = 0;
	for (int i = 0;i < NoN;i++)
		allsharpness += sharpness[i];
	allsharpness /= NoN;

	return allsharpness;
}