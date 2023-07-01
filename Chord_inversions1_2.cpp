#include "Notes.h"
 
using std::string;

string note_to_key(int step, int pitch);


void Chord_inversions1_2(Polychord* Polychords, int& modifications)
{
	Polychord Initial;
	Polychord Inverted[120];
	Polychord Transposed[120];
	string notes = pnotes();
	string longline = Longline();
	int model;
	int sum;
	int NoI = 4;


	bool oncemore = 1;
	while (oncemore)
	{
		Color(11);
		cout << "\nоберіть модель нонакорда: \n";
		Color(7);
		cout << "1 - мажорний, 2 - домінантовий, 3 - мінорний, 4 - мажорний із секстою, 5 - зменшений, 0 - ввести вручну " << endl;
		model = EnterNum(5);
		cout << endl << notes;


		// основні характеристики для кожного звука
		string initial; // для побудови нонакорду за моделлю
		string key[5]; // ручне введення нонакорду 
		string name[5]; // назва кирилицею
		int pitch[5]; // висота звуку (у півтонах) в кожному з голосів
		int step[5]; // ступінь у кожному з голосів
		string destination; // для транспозиції
		bool notation = 1; //змінна для переключення європейської та американської нотації (поки що не розроблено)



		//ВВЕСТИ АКОРД

		if (model == 0)
		{
			bool repeat = 0;

			{
				Title(11, "Введіть 5 звуків");

				for (int i = 0; i < 5; i++)
					key[i] = EnterNotes(notation);
				for (int i = 0; i < 5; i++)
				{
					Initial.key[i] = key[i]; // назва ноти, string
					Initial.step[i] = key_to_step(key[i], notation);  // ступінь від "до", int
					Initial.pitch[i] = key_to_pitch(key[i], notation); // висота в півтонах від "до", int
					Initial.name[i] = key_to_notename(key[i], notation); // назва ноти, string
				}
				for (int i = 0; i < 4; i++)
					if (Stepdiff(Initial.step[i], Initial.step[i + 1]) != 2)
					{
						Title(12, "введений акорд не є нонакордом. Все одно продовжити? 1 - так, 0 - спробуати знову");
						cin >> repeat;
						break;
					}
					else repeat = 1;
			} while (!repeat);
			initial = key[0];
		}

		else
		{
			if (model == 6) Title(11, "Введіть мелодичний тон");
			else Title(11, "Введіть основний тон");

			initial = EnterNotes(notation);

			Initial = Initial9(initial, notation);

			switch (model)
			{
			case 1:
			{
				Initial.pitch[1] = addpitch(Initial.pitch[0], 4);
				Initial.pitch[3] = addpitch(Initial.pitch[0], 11);
				break;
			}
			case 2:
			{
				Initial.pitch[1] = addpitch(Initial.pitch[0], 4);
				Initial.pitch[3] = addpitch(Initial.pitch[0], 10);
				break;
			}
			case 3:
			{
				Initial.pitch[1] = addpitch(Initial.pitch[0], 3);
				Initial.pitch[3] = addpitch(Initial.pitch[0], 10);
				break;
			}
			case 4:
			{
				Initial.pitch[1] = addpitch(Initial.pitch[0], 4);
				Initial.step[3] = addpitch(Initial.step[2], 1);
				Initial.pitch[3] = addpitch(Initial.pitch[0], 9);
				break;
			}
			case 5:
			{
				Initial.pitch[1] = addpitch(Initial.pitch[0], 3);
				Initial.pitch[2] = addpitch(Initial.pitch[0], 6);
				Initial.pitch[3] = addpitch(Initial.pitch[0], 10);
				Initial.pitch[4] = addpitch(Initial.pitch[0], 13);
				break;
			}
			}
			for (int i = 0; i < 5; i++)
			{

				Initial.key[i] = note_to_key(Initial.step[i], Initial.pitch[i]);
			}

		}
		if (model != 0)
			for (int i = 0; i < 5; i++)
			{
				Initial.name[i] = pitch_to_notename(Initial.step[i], Initial.pitch[i]); // генеруємо назви нот (string)
			}


		// АНАЛІЗ

		system("cls");


		cout << "\nАкорд введено: ";
		for (int i = 0; i < 5; i++)
			cout << Initial.name[i] << " - ";


	operation:
		int mode = Mode();

		Title(11, "\nОберіть операцію");
		cout << "\nВивести усі нонакорди в порядку обернень - 1\nВивести лише нонакорди з ноною у мелодичному положенні -2\nвивести лише акорди з інтервалом нони між крайніми голосами -3\nВивести усі акорди в порядку зростання діапазону - 4\nВивести нонакорди та обернення від заданої ноти - 5\nВивести нонакорди та обернення із заданим мелодичним тоном - 6 " << endl;
		int choice;
		cin >> choice;

		Inverted[0] = Initial;


		int c = 0;//рахує кількість модифікацій

		//КОМБІНАТОРИКА

		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++)
					for (int l = 0; l < 5; l++)
						for (int m = 0; m < 5; m++)
						{
							if (i != j && i != k && i != l && i != m && // умова для уникнення однакових нот
								j != k && j != l && j != m
								&& k != l && k != m
								&& l != m)
							{

								/*cout << c << ": ";*/
								Inverted[c].key[0] = Initial.key[i]; //cout << Initial.key[i];
								Inverted[c].key[1] = Initial.key[j]; //cout << Initial.key[j];
								Inverted[c].key[2] = Initial.key[k]; //cout << Initial.key[k];
								Inverted[c].key[3] = Initial.key[l]; //cout << Initial.key[l];
								Inverted[c].key[4] = Initial.key[m]; //cout << Initial.key[m] << endl;

								c++;
							}
						}

		for (int j = 0; j < c; j++)
			for (int i = 0; i < 5; i++)
			{
				Inverted[j].pitch[i] = key_to_pitch(Inverted[j].key[i], notation); // висота (int)
				Inverted[j].name[i] = key_to_notename(Inverted[j].key[i], notation); // назва (string)
				Inverted[j].step[i] = key_to_step(Inverted[j].key[i], notation);  // ступінь від "до" (int)
			}
		;

		// визначення положення інтервалів
		for (int j = 0; j < c; j++)
			for (int i = 0; i < 5; i++)
			{
				if (Inverted[j].key[i] == Initial.key[0]) Inverted[j].prima = i;
				if (Inverted[j].key[i] == Initial.key[1]) Inverted[j].terzia = i;
				if (Inverted[j].key[i] == Initial.key[2]) Inverted[j].quinta = i;
				if (Inverted[j].key[i] == Initial.key[3]) Inverted[j].septyma = i;
				if (Inverted[j].key[i] == Initial.key[4]) Inverted[j].nona = i;
			}
		;

		sum = 0;
		string header;

		// СТВОРЕННЯ СПИСКІВ АКОРДІВ

		if (choice == 1)
		{
			header = "Усі нонакроди";
			for (int j = 0; j < c; j++)
			{
				if (!(mode > 0 && Inverted[j].nona - Inverted[j].prima < 2))
				{
					for (int i = 0; i < 5; i++)
						Polychords[sum] = Inverted[j];

					sum++;
				}
			}
			allsum(sum);

		}

		else if (choice == 2)
		{
			// нонакорди з ноною на горі.
			int d = 0, e = 0;


			header = "нонакроди з ноною в мелодичному положенні";
			for (int j = 0; j < c; j++)
			{
				if (!(mode > 0 && Inverted[j].nona - Inverted[j].prima < 2))
				{

					if (Stepdiff(Initial.step[0], Inverted[j].step[4]) == 1)// !!
					{
						for (int i = 0; i < 5; i++)
							Polychords[d] = Inverted[j];
						d++;
					}
					else e++;
				}
			}
			sum = d;
		}

		else if (choice == 3)	// нонакорди з ноною між крайніми голосами.
		{
			int d = 0, e = 0;


			header = "нонакроди з інтервалом нона між крайніми голосами";
			for (int j = 0; j < c; j++)
			{
				if (!(mode > 0 && Inverted[j].nona - Inverted[j].prima < 2))
				{
					if (Stepdiff(Inverted[j].step[0], Inverted[j].step[4]) == 1)
					{
						for (int i = 0; i < 5; i++)
							Polychords[d] = Inverted[j];
						d++;
					}
					else e++;
				}
			}
			//cout << "\nЗнайдено акордів: " << d << endl;
			//cout << "\nПроігноровано: " << e << endl;

			sum = d;
		}


		else if (choice == 4)
			// нонакорди за зростанням діапазону.
		{
			header = "Нонакроди за зростанням діапазону";
			sum = 0;

			for (int k = 6; k < 26; k++)
				for (int j = 0; j < c; j++)
				{
					if (!(mode > 0 && Inverted[j].nona - Inverted[j].prima < 2))
					{
						if (sum_steps(Inverted[j].step, NoI) == k)
						{
							for (int i = 0; i < 5; i++)
								Polychords[sum] = Inverted[j];
							sum++;
						}
					}
				}
			allsum(sum);
		}

		else if (choice == 5)

		{

			// нонакорди за зростанням діапазону.
			header = "\nНонакроди за зростанням діапазону від заданої ноти";
			sum = 0;
			destination = initial;
			Transposed[0].step[0] = key_to_step(destination);
			Transposed[0].pitch[0] = key_to_pitch(destination);



			for (int i = 0; i < 120; i++)
			{
				int stepshift = Stepdiff(Inverted[i].step[0], Transposed[0].step[0]); // зсув про ступенях
				int pitchshift = Pitchdiff(Inverted[i].pitch[0], Transposed[0].pitch[0]); // зсув по півтонах
				Transposed[i].prima = Inverted[i].prima;
				Transposed[i].terzia = Inverted[i].terzia;
				Transposed[i].quinta = Inverted[i].quinta;
				Transposed[i].septyma = Inverted[i].septyma;
				Transposed[i].nona = Inverted[i].nona;

				for (int j = 0; j < 5; j++)
				{
					Transposed[i].step[j] = addstep(Inverted[i].step[j], stepshift);  // транспонування
					Transposed[i].pitch[j] = addpitch(Inverted[i].pitch[j], pitchshift); // транспонування
					Transposed[i].key[j] = note_to_key(Transposed[i].step[j], Transposed[i].pitch[j]); // генерування key

				}
			}

			for (int j = 0; j < c; j++)
				for (int i = 0; i < 5; i++)
				{
					Transposed[j].name[i] = pitch_to_notename(Transposed[j].step[i], Transposed[j].pitch[i]); // генеруємо назви нот (string)
				}


			for (int k = 6; k < 50; k++)
				for (int j = 0; j < c; j++)
				{
					if (!(mode > 0 && Transposed[j].nona - Transposed[j].prima < 2))
					{
						if (sum_pitchs(Transposed[j].pitch, NoI) == k)
						{
							for (int i = 0; i < 5; i++)
								Polychords[sum] = Transposed[j]; // записуємо значеня у множину акордів, які передаються у main
							sum++;
						}
					}
				}

			allsum(sum);
		}
		else if (choice == 6)

		{

			// нонакорди за зростанням діапазону.
			header = "Нонакроди за зростанням діапазону із заданим мелодичним тоном";
			sum = 0;
			destination = initial; // вводиться 
			Transposed[0].step[4] = key_to_step(destination);
			Transposed[0].pitch[4] = key_to_pitch(destination);


			for (int i = 0; i < 120; i++)
			{
				int stepshift = Stepdiff(Inverted[i].step[4], Transposed[0].step[4]); // зсув про ступенях
				int pitchshift = Pitchdiff(Inverted[i].pitch[4], Transposed[0].pitch[4]); // зсув по півтонах
				Transposed[i].prima = Inverted[i].prima;
				Transposed[i].terzia = Inverted[i].terzia;
				Transposed[i].quinta = Inverted[i].quinta;
				Transposed[i].septyma = Inverted[i].septyma;
				Transposed[i].nona = Inverted[i].nona;

				for (int j = 0; j < 5; j++)
				{
					Transposed[i].step[j] = addstep(Inverted[i].step[j], stepshift);  // транспонування
					Transposed[i].pitch[j] = addpitch(Inverted[i].pitch[j], pitchshift); // транспонування
				}
			}

			for (int j = 0; j < c; j++)
				for (int i = 0; i < 5; i++)
				{
					Transposed[j].name[i] = pitch_to_notename(Transposed[j].step[i], Transposed[j].pitch[i]); // генеруємо назви нот (string)
					Transposed[j].key[i] = note_to_key(Transposed[j].step[i], Transposed[j].pitch[i]); // генерування key
				}

			for (int k = 6; k < 50; k++)
				for (int j = 0; j < c; j++)
				{
					if (!(mode > 0 && Transposed[j].nona - Transposed[j].prima < 2))
					{
						if (sum_pitchs(Transposed[j].pitch, NoI) == k)
						{
							for (int i = 0; i < 5; i++)
								Polychords[sum] = Transposed[j];
							sum++;
						}
					}
				}

			allsum(sum);
		}
		else
		{
			Title(12, "спробуйте ще раз");
			goto operation;
		}

		float consonansrate = Consonans_rate(Polychords[0].step, Polychords[0].pitch, 5); // консонантність

		// РЕЗУЛЬТАТИ НА ЕКРАН

		tableheader(header);

		for (int j = 0; j < sum; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				cout << setw(3) << Polychords[j].name[i] << setw(1) << " \t";
			}
			cout << setw(1) << " | " << setw(2) << sum_steps(Polychords[j].step, NoI) << setw(1) << " ";
			cout << setw(1) << " | " << setw(2) << sum_pitchs(Polychords[j].pitch, NoI) << endl;
		}

		tablefooter(consonansrate, true, sum);

		oncemore = Oncemore();

	}

	modifications = sum;
}

