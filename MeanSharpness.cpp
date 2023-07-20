#include"Notes.h"

float MeanSharpness(Polychord chord)
{
	int* sharpness = new int[chord.numberofnotes];
	int* alter = new int[chord.numberofnotes];
	//cout << "alter[i] = ";
	for (int i = 0; i < chord.numberofnotes; i++)
		alter[i] = alter_from_pitch(chord.step[i], chord.pitch[i]);


	for (int i = 0; i < chord.numberofnotes; i++)
		sharpness[i] = Sharpness(chord.step[i], alter[i]);

	float allsharpness = 0;
	for (int i = 0;i < chord.numberofnotes;i++)
		allsharpness += sharpness[i];
	allsharpness /= chord.numberofnotes;

	return allsharpness;

}

