#include "Notes.h"

void all_sharpness(float* sharpness, int NoN)
{
	float allsharpness = 0;
	for (int i = 0;i < NoN;i++)
		allsharpness += sharpness[i];
	allsharpness /= NoN;
	
	
	if (allsharpness>0)  cout << "Середнє положення на квінтовому колі: +" << allsharpness <<endl;
	else  cout << "Середнє положення на квінтовому колі: " << allsharpness << endl;
}