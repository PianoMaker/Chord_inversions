#include "Notes.h"
#include"Messages.h"
#include <string>
#define Sharp (MeanSharpness(polychords[j], numberofnotes))


void ExtChordStats(Polychord* polychords, long& modifications, int& numberofnotes, bool notation)
{
 
	string initialnote = "c"; // ручне введення основного тону

	tablestats();
	Line();

for(int i = 3; i<13; i++)

{
	string header = get_chord_string(modifications);

	numberofnotes = i;
	ExtChordsCore(polychords, modifications, initialnote, notation, numberofnotes, false);

	//numberofnotes = i;

	//modifications = pow(2, numberofnotes - 1);
	//Polychord* Multichord = new Polychord[modifications];


	//for (int i = 0; i < modifications; i++)
	//{
	//	Multichord[i].numberofnotes = numberofnotes;
	//	Multichord[i].key[0] = initialnote; // назва ноти, string
	//	Multichord[i].step[0] = Key_to_step(initialnote, notation);  // ступінь від "до", int
	//	Multichord[i].pitch[0] = Key_to_pitch(initialnote, notation); // висота в півтонах від "до", int
	//	Multichord[i].name[0] = Key_to_notename(initialnote, notation); // назва ноти, string
	//}


	//int counter = 1, sound = 0;
	//Multichord = Polychord_Add(Multichord, counter, sound, numberofnotes, 0);


	//// фільтрація акордів

	//int c = 0, e = 0;
	//for (int j = 0; j < modifications; j++)
	//{

	//	if (PitchFilter(Multichord[j].pitch, numberofnotes))
	//	{

	//		polychords[c] = Multichord[j];
	//		c++;
	//	}
	//}

	
	

	// РЕЗУЛЬТАТИ НА ЕКРАН

	int steps = polychords[0].step[i-1] - polychords[0].step[0] + 1;

	cout << i << "\t" << steps << "\t" << modifications << endl;
}


Line();
system("pause");

}