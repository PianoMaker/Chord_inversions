#include "Notes.h"
#include"Messages.h"
#include <string>
#define Sharp (MeanSharpness(polychords[j], numberofnotes))


 string get_chord_string(int sounds, bool lang) {
	return chords_containing(lang) + to_string(sounds) + fsounds(lang);
}

void Chord_inversions1_4(Polychord* polychords, long& modifications, int &numberofnotes, bool notation, bool lang)
{
		string initialnote; // ручне введення основного тону
		
		initialnote = EnterNotes(notation, enter(lang) + root(lang), lang);

		Message(11, enter(lang) + upto12(lang));
		numberofnotes = EnterNum(12, lang);

		modifications = pow (2, numberofnotes -1);
		Polychord *Multichord = new Polychord[modifications];
		cout << "modifications = " << modifications << endl; 

		string header = get_chord_string(numberofnotes, lang);
		

		bool test;
		Message (8,"test regime ? 1 - yes, 0 - no\n");
		cin >> test;


		for (int i =0; i< modifications; i++)
		{
			Multichord[i].key[0] = initialnote; // назва ноти, string
			Multichord[i].step[0] = Key_to_step(initialnote, notation);  // ступінь від "до", int
			Multichord[i].pitch[0] = Key_to_pitch(initialnote, notation); // висота в півтонах від "до", int
			Multichord[i].name[0] = Key_to_notename(initialnote, notation, lang); // назва ноти, string
		}

		if (test)cout << "test base: " << Multichord[0].name[0] << " " << Multichord[0].pitch[0] << endl;
	
		int counter = 1, sound = 0;
		Multichord = Polychord_Add(Multichord, modifications, counter, sound, numberofnotes, test);

		if(test)
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
				Multichord[j].name[i] = Pitch_to_notename(Multichord[j].step[i], Multichord[j].pitch[i], lang); // генеруємо назви нот (string)
				if (test)cout << Multichord[j].name[i] << " ,";
			}
			
		

			if (PitchFilter(Multichord[j].pitch, numberofnotes))
			{

				polychords[c] = Multichord[j];
				for (int i = 0; i < numberofnotes; i++)
				polychords[c].name[i] = Pitch_to_notename(polychords[c].step[i], polychords[c].pitch[i], lang);
			
				c++;
				if(test) cout << ": +\n";
				
			}
			else
			{
				e++;
				if (test) cout << ": -\n";
			}
	
		}
		delete[] Multichord;
		

		if (test) cout << "c = " << c << "; " << "e = " << e;

		Line();


		// РЕЗУЛЬТАТИ НА ЕКРАН

		tableheader(header);

		for (int j = 0; j < c; j++)
		{
			cout << j + 1 << "| ";

			for (int i = 0; i < numberofnotes; i++)
			{
				cout << "\t" << setw(4) << polychords[j].name[i];
			}
			cout << setw(4) << " \t| " << setw(1) << sum_steps(polychords[j].step, numberofnotes - 1) << setw(1) << " ";
			cout << setw(1) << " | " << setw(1) << sum_pitchs(polychords[j].pitch, numberofnotes - 1) << " ";
			cout << setw(1) << " | " << setw(1) << round(Consonans_rate(polychords[j].step, polychords[j].pitch, numberofnotes) * 100) << " % "; // консонантність
			if (Sharp > 0) 	cout << setw(1) << " | " << setw(2) << "+" << Sharp << endl;
			else 			cout << setw(1) << " | " << setw(2) << Sharp << endl;

			

		}
		tablefooter(0, false, c);

		modifications = c;
	
}