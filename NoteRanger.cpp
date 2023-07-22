#include "Notes.h"

void NoteRanger(Polychord* polychord, long modifications, int numberofnotes)
{
	for (int i = 0; i < modifications; i++)
		for (int j = 0; j < numberofnotes - 1; j++)
			while (polychord[i].pitch[j + 1] < polychord[i].pitch[j])
				polychord[i].pitch[j + 1] += 12;

}