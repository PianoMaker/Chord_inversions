#include"Notes.h"

Polychord nonchord_from_keys(string key[], int notation)
{
	
	Polychord Initial;
	for (int i = 0; i < 5; i++)
	{
		
		Initial.key[i] = key[i]; // назва ноти, string
		Initial.step[i] = key_to_step(key[i], notation);  // ступінь від "до", int
		Initial.pitch[i] = key_to_pitch(key[i], notation); // висота в півтонах від "до", int
		Initial.name[i] = key_to_notename(key[i], notation); // назва ноти, string
	}
	return Initial;
}
