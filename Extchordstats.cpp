#include "Notes.h"
#include"Messages.h"
#include <string>
#define Sharp (MeanSharpness(polychords[j], numberofnotes))


void Extchordstats(Polychord* polychords, long& modifications, int& numberofnotes, bool notation, bool lang)
{
 
	string initialnote = "c"; // ручне введення основного тону

	tablestats(lang);
	Line();

for(int i = 3; i<13; i++)
{

	numberofnotes = i;

	modifications = pow(2, numberofnotes - 1);
	Polychord* Multichord = new Polychord[modifications];

	string header = get_chord_string(modifications, lang);


	for (int i = 0; i < modifications; i++)
	{
		Multichord[i].key[0] = initialnote; // назва ноти, string
		Multichord[i].step[0] = Key_to_step(initialnote, notation);  // ступінь від "до", int
		Multichord[i].pitch[0] = Key_to_pitch(initialnote, notation); // висота в півтонах від "до", int
		Multichord[i].name[0] = Key_to_notename(initialnote, notation); // назва ноти, string
	}


	int counter = 1, sound = 0;
	Multichord = Polychord_Add(Multichord, modifications, counter, sound, numberofnotes, 0);


	// фільтрація акордів

	int c = 0, e = 0;
	for (int j = 0; j < modifications; j++)
	{

		for (int i = 0; i < numberofnotes; i++)
		{
			Multichord[j].name[i] = Pitch_to_notename(Multichord[j].step[i], Multichord[j].pitch[i], lang); // генеруємо назви нот (string)
		}



		if (PitchFilter(Multichord[j].pitch, numberofnotes))
		{

			polychords[c] = Multichord[j];
			for (int i = 0; i < numberofnotes; i++)
				polychords[c].name[i] = Pitch_to_notename(polychords[c].step[i], polychords[c].pitch[i], lang);
			c++;
		}
		else
		{
			e++;
		}
	}
	delete[] Multichord;

	// РЕЗУЛЬТАТИ НА ЕКРАН

	cout << i << "\t" << sum_steps(polychords[0].step, numberofnotes - 1) + 1 << "\t" << c << endl;
}

Line();


}