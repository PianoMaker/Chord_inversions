#include"Notes.h"

bool PitchFilter(int* pitch, int sounds)
{
	for (int i = 0; i < sounds; i++)
		for (int j = 0; j < sounds; j++)
			if (i != j && (pitch[i] - pitch[j]) % 12 == 0)
				return false;

			

	return true;

}