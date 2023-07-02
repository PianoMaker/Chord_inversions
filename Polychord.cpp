#include"Notes.h"

Polychord numberofnoteschord_from_keys(string key[], int notation)
{
	
	Polychord initial;
	for (int i = 0; i < 5; i++)
	{
		
		initial.key[i] = key[i]; // назва ноти, string
		initial.step[i] = Key_to_step(key[i], notation);  // ступінь від "до", int
		initial.pitch[i] = Key_to_pitch(key[i], notation); // висота в півтонах від "до", int
		initial.name[i] = Key_to_notename(key[i], notation); // назва ноти, string
	}
	return initial;
}
