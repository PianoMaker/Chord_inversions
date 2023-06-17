#include "Notes.h"
#include <string>
#define Sharp (MeanSharpness(Polychords[j], sounds))


void Extchordstats(Polychord* Polychords, int& modifications)
{

	string initial = "c"; // ручне введення основного тону
	int notation = 1, sounds;

	cout << "\nsounds \t" << "steps \t" << "chords possible \t";
	Line();

for(int i = 3; i<13; i++)
{

	sounds = i;

	modifications = pow(2, sounds - 1);
	Polychord* Multichord = new Polychord[modifications];

	string header = get_chord_string(sounds);


	for (int i = 0; i < modifications; i++)
	{
		Multichord[i].key[0] = initial; // назва ноти, string
		Multichord[i].step[0] = key_to_step(initial, notation);  // ступінь від "до", int
		Multichord[i].pitch[0] = key_to_pitch(initial, notation); // висота в півтонах від "до", int
		Multichord[i].name[0] = key_to_notename(initial, notation); // назва ноти, string
	}


	int counter = 1, sound = 0;
	Multichord = Polychord_Add(Multichord, modifications, counter, sound, sounds, 0);


	// фільтрація акордів

	int c = 0, e = 0;
	for (int j = 0; j < modifications; j++)
	{

		for (int i = 0; i < sounds; i++)
		{
			Multichord[j].name[i] = pitch_to_notename(Multichord[j].step[i], Multichord[j].pitch[i]); // генеруємо назви нот (string)
		}



		if (PitchFilter(Multichord[j].pitch, sounds))
		{

			Polychords[c] = Multichord[j];
			for (int i = 0; i < sounds; i++)
				Polychords[c].name[i] = pitch_to_notename(Polychords[c].step[i], Polychords[c].pitch[i]);
			c++;
		}
		else
		{
			e++;
		}
	}
	delete[] Multichord;

	// РЕЗУЛЬТАТИ НА ЕКРАН

	cout << i << "\t" << sum_steps(Polychords[0].step, sounds - 1) + 1 << "\t" << c << endl;
}

Line();


}