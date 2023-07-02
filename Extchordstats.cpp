#include "Notes.h"
#include <string>
#define Sharp (MeanSharpness(polychords[j], sounds))


void Extchordstats(Polychord* polychords, int& modifications)
{

	string initialnote = "c"; // ручне введення основного тону
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
		Multichord[i].key[0] = initialnote; // назва ноти, string
		Multichord[i].step[0] = Key_to_step(initialnote, notation);  // ступінь від "до", int
		Multichord[i].pitch[0] = Key_to_pitch(initialnote, notation); // висота в півтонах від "до", int
		Multichord[i].name[0] = Key_to_notename(initialnote, notation); // назва ноти, string
	}


	int counter = 1, sound = 0;
	Multichord = Polychord_Add(Multichord, modifications, counter, sound, sounds, 0);


	// фільтрація акордів

	int c = 0, e = 0;
	for (int j = 0; j < modifications; j++)
	{

		for (int i = 0; i < sounds; i++)
		{
			Multichord[j].name[i] = Pitch_to_notename(Multichord[j].step[i], Multichord[j].pitch[i]); // генеруємо назви нот (string)
		}



		if (PitchFilter(Multichord[j].pitch, sounds))
		{

			polychords[c] = Multichord[j];
			for (int i = 0; i < sounds; i++)
				polychords[c].name[i] = Pitch_to_notename(polychords[c].step[i], polychords[c].pitch[i]);
			c++;
		}
		else
		{
			e++;
		}
	}
	delete[] Multichord;

	// РЕЗУЛЬТАТИ НА ЕКРАН

	cout << i << "\t" << sum_steps(polychords[0].step, sounds - 1) + 1 << "\t" << c << endl;
}

Line();


}