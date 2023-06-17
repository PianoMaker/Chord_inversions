#include "Notes.h"
#include <string>
#define Sharp (MeanSharpness(Polychords[j], sounds))


 string get_chord_string(int sounds) {
	return "Акорди із " + std::to_string(sounds) + " звуків";
}

void Chord_inversions1_4(Polychord* Polychords, int& modifications)
{
	bool oncemore = 1;
	while (oncemore)
	{
			string initial; // ручне введення основного тону
		int notation = 1, sounds;

		title(11, "\nВведіть основний тон");
		initial = EnterNotes(notation);

		title(11, "\nВведіть кількість нот (до 12)");
		sounds = EnterNum(12);

		modifications = pow (2, sounds-1);
		Polychord *Multichord = new Polychord[modifications];
		cout << "modifications = " << modifications << endl; 

		string header = get_chord_string(sounds);
		

		bool test;
		title (8,"test regime ? 1 - yes, 0 - no\n");
		cin >> test;


		for (int i =0; i< modifications; i++)
		{
			Multichord[i].key[0] = initial; // назва ноти, string
			Multichord[i].step[0] = key_to_step(initial, notation);  // ступінь від "до", int
			Multichord[i].pitch[0] = key_to_pitch(initial, notation); // висота в півтонах від "до", int
			Multichord[i].name[0] = key_to_notename(initial, notation); // назва ноти, string
		}

		if (test)cout << "test base: " << Multichord[0].name[0] << " " << Multichord[0].pitch[0] << endl;
	

		int counter = 1, sound = 0;
		Multichord = Polychord_Add(Multichord, modifications, counter, sound, sounds, test);



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

			for (int i = 0; i < sounds; i++)
			{
				if (test)cout << Multichord[j].pitch[i] << " ";
				Multichord[j].name[i] = pitch_to_notename(Multichord[j].step[i], Multichord[j].pitch[i]); // генеруємо назви нот (string)
				if (test)cout << Multichord[j].name[i] << " ,";
			}
			
		

			if (PitchFilter(Multichord[j].pitch, sounds))
			{

				Polychords[c] = Multichord[j];
				for (int i = 0; i < sounds; i++)
				Polychords[c].name[i] = pitch_to_notename(Polychords[c].step[i], Polychords[c].pitch[i]);
			
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

			for (int i = 0; i < sounds; i++)
			{
				cout << setw(3) << Polychords[j].name[i] << setw(1) << " \t";
			}
			cout << setw(1) << " | " << setw(2) << sum_steps(Polychords[j].step, sounds - 1) << setw(1) << " ";
			cout << setw(1) << " | " << setw(2) << sum_pitchs(Polychords[j].pitch, sounds - 1) << " ";
			cout << setw(1) << " | " << setw(2) << round(Consonans_rate(Polychords[j].step, Polychords[j].pitch, sounds) * 100) << " % "; // консонантність
			if (Sharp > 0) 	cout << setw(1) << " | " << setw(2) << "+" << Sharp << endl;
			else 			cout << setw(1) << " | " << setw(2) << Sharp << endl;

			

		}
		tablefooter(0, false, c);
	
	oncemore = Oncemore();
	}


}