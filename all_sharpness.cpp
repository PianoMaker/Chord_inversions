#include "Notes.h"

void all_sharpness(float* sharpness, int numberofnotes)
{
	float allsharpness = 0;
	for (int i = 0;i < numberofnotes;i++)
		allsharpness += sharpness[i];
	allsharpness /= numberofnotes;
	
	
	if (allsharpness>0)  cout << "Середнє положення на квінтовому колі: +" << allsharpness <<endl;
	else  cout << "Середнє положення на квінтовому колі: " << allsharpness << endl;
}