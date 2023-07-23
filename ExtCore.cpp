#include "Notes.h"
#include"Messages.h"
#include <string>

void ExtChordsCore(Polychord* polychords, long& modifications, string initialnote, bool notation, int numberofnotes, bool test)
{
	modifications = pow(2, numberofnotes - 1);
	Polychord* Multichord = new Polychord[modifications];
	//cout << "modifications = " << modifications << endl;

	for (int i = 0; i < modifications; i++)
	{
		Multichord[i].key[0] = initialnote; // назва ноти, string
		Multichord[i].step[0] = Key_to_step(initialnote, notation);  // ступінь від "до", int
		Multichord[i].pitch[0] = Key_to_pitch(initialnote, notation); // висота в півтонах від "до", int
		Multichord[i].name[0] = Key_to_notename(initialnote, notation); // назва ноти, string
		Multichord[i].numberofnotes = numberofnotes;

	}

	if (test)cout << "test base: " << Multichord[0].name[0] << " " << Multichord[0].pitch[0] << endl;

	int counter = 1, sound = 0;
	Multichord = Polychord_Add(Multichord, counter, sound, numberofnotes, test);

	if (test)
	{
		cout << "\nVerifying chords after process:\n " << endl;
		cout << "modifications = " << modifications << endl;
		for (int i = 0; i < modifications; i++)
		{
			cout << i << ": ";
			for (int k = 0; k <= sound; k++)
			{
				cout << Multichord[i].pitch[k] << " (";
				cout << Multichord[i].step[k] << "), ";
			}
			cout << endl;
		}

		system("pause");
	}

	// фільтрація акордів

	int c = 0, e = 0;
	for (int j = 0; j < modifications; j++)
	{
		if (test)cout << "j = " << " " << j << ":";

		for (int i = 0; i < numberofnotes; i++)
		{
			if (test)cout << Multichord[j].pitch[i] << " ";
			Multichord[j].name[i] = Pitch_to_notename(Multichord[j].step[i], Multichord[j].pitch[i]); // генеруємо назви нот (string)
			if (test)cout << Multichord[j].name[i] << " ,";
		}



		if (PitchFilter(Multichord[j].pitch, numberofnotes))
		{

			polychords[c] = Multichord[j];
			polychords[c].numberofnotes = numberofnotes;
			for (int i = 0; i < numberofnotes; i++)
				polychords[c].name[i] = Pitch_to_notename(polychords[c].step[i], polychords[c].pitch[i]);

			c++;
			if (test) cout << ": +\n";

		}
		else
		{
			e++;
			if (test) cout << ": -\n";
		}

	}
	delete[] Multichord;


	if (test) cout << "c = " << c << "; " << "e = " << e;
	modifications = c;
		
}