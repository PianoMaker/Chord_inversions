#include"Notes.h"

float MeanSharpness(Polychord chord, int sounds)
{
	int* sharpness = new int[sounds];
	int* alter = new int[sounds];
	//cout << "alter[i] = ";
	for (int i = 0; i < sounds; i++)
		alter[i] = alter_from_pitch(chord.step[i], chord.pitch[i]);


	for (int i = 0; i < sounds; i++)
		sharpness[i] = Sharpness(chord.step[i], alter[i]);

	float allsharpness = 0;
	for (int i = 0;i < sounds;i++)
		allsharpness += sharpness[i];
	allsharpness /= sounds;

	return allsharpness;

}

