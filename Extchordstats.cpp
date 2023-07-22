#include "Notes.h"
#include"Messages.h"
#include <string>
#define Sharp (MeanSharpness(polychords[j], numberofnotes))


void ExtChordStats(Polychord* polychords, long& modifications, int& numberofnotes, bool notation)
{
 
	string initialnote = "c"; // ручне введення основного тону

	tablestats();
	Line();

for(int nn = 3; nn<13; nn++)

{
	string header = get_chord_string(modifications);
	numberofnotes = nn;

	modifications = pow(2, numberofnotes - 1);
	Polychord* Multichord = new Polychord[modifications];


	for (int i = 0; i < modifications; i++)
	{
		Multichord[i].numberofnotes = numberofnotes;
		Multichord[i].key[0] = initialnote; // назва ноти, string
		Multichord[i].step[0] = Key_to_step(initialnote, notation);  // ступінь від "до", int
		Multichord[i].pitch[0] = Key_to_pitch(initialnote, notation); // висота в півтонах від "до", int
		Multichord[i].name[0] = Key_to_notename(initialnote, notation); // назва ноти, string
	}


	int counter = 1, sound = 0;
	Multichord = Polychord_Add(Multichord, modifications, counter, sound, numberofnotes, 1);


	// фільтрація акордів

	int c = 0, e = 0;
	for (int j = 0; j < modifications; j++)
	{

		for (int i = 0; i < numberofnotes; i++)
		{
			Multichord[j].name[i] = Pitch_to_notename(Multichord[j].step[i], Multichord[j].pitch[i]); // генеруємо назви нот (string)
		}



		if (PitchFilter(Multichord[j].pitch, numberofnotes))
		{
		
			for (int i = 0; i < numberofnotes; i++)
				Multichord[j].name[i] = Pitch_to_notename(Multichord[c].step[i], Multichord[c].pitch[i]);
			c++;
		}
		else
		{
			e++;
		}
		
	}

	
	

	// РЕЗУЛЬТАТИ НА ЕКРАН

	cout << nn << "\t" << sum_steps(Multichord[0].step, numberofnotes - 1) + 1 << "\t" << c << endl;
	delete[] Multichord;

	//cout << "\nmodifications=" << nn;
}


Line();
system("pause");

}