#include "Notes.h"


string Note_to_key(int step, int pitch);


void Chord_inversions1_2(Polychord* polychords, int& modifications)
{
	int const numberofnotes = 5;
	int numberofintervals = numberofnotes - 1;
	Polychord initial;
	Polychord inverted[120];
	Polychord Transposed[120];
	string notes = Textnotation();
	string longline = Longline();
	int model;
	int sum;


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
		string initialnote; // для побудови нонакорду за моделлю
		string key[numberofnotes]; // ручне введення нонакорду 
		string name[numberofnotes]; // назва кирилицею
		int pitch[numberofnotes]; // висота звуку (у півтонах) в кожному з голосів
		int step[numberofnotes]; // ступінь у кожному з голосів
		string destination; // для транспозиції
		bool notation = 1; //змінна для переключення європейської та американської нотації (поки що не розроблено)



		//ВВЕСТИ АКОРД

		if (model == 0)
		{
			bool repeat = 0;

			{
				for (int i = 0; i < numberofnotes; i++)
					key[i] = EnterNotes(notation, "Введіть 5 звуків");
				for (int i = 0; i < numberofnotes; i++)
				{
					initial.key[i] = key[i]; // назва ноти, string
					initial.step[i] = Key_to_step(key[i], notation);  // ступінь від "до", int
					initial.pitch[i] = Key_to_pitch(key[i], notation); // висота в півтонах від "до", int
					initial.name[i] = Key_to_notename(key[i], notation); // назва ноти, string
				}
				for (int i = 0; i < numberofintervals; i++)
					if (Stepdiff(initial.step[i], initial.step[i + 1]) != 2)
					{
						Message(12, "введений акорд не є нонакордом. Все одно продовжити? 1 - так, 0 - спробуати знову");
						cin >> repeat;
						break;
					}
					else repeat = 1;
			} while (!repeat);
			initialnote = key[0];
		}

		else
		{
			string text;
			if (model == 6) text = "Введіть мелодичний тон";
			else text ="Введіть основний тон";

			initialnote = EnterNotes(notation, text);

			initial = Initial9(initialnote, notation);

			switch (model)
			{
			case 1:
			{
				initial.pitch[1] = addpitch(initial.pitch[0], 4);
				initial.pitch[3] = addpitch(initial.pitch[0], 11);
				break;
			}
			case 2:
			{
				initial.pitch[1] = addpitch(initial.pitch[0], 4);
				initial.pitch[3] = addpitch(initial.pitch[0], 10);
				break;
			}
			case 3:
			{
				initial.pitch[1] = addpitch(initial.pitch[0], 3);
				initial.pitch[3] = addpitch(initial.pitch[0], 10);
				break;
			}
			case 4:
			{
				initial.pitch[1] = addpitch(initial.pitch[0], 4);
				initial.step[3] = addpitch(initial.step[2], 1);
				initial.pitch[3] = addpitch(initial.pitch[0], 9);
				break;
			}
			case 5:
			{
				initial.pitch[1] = addpitch(initial.pitch[0], 3);
				initial.pitch[2] = addpitch(initial.pitch[0], 6);
				initial.pitch[3] = addpitch(initial.pitch[0], 10);
				initial.pitch[4] = addpitch(initial.pitch[0], 13);
				break;
			}
			}
			for (int i = 0; i < 5; i++)
			{

				initial.key[i] = Note_to_key(initial.step[i], initial.pitch[i]);
			}

		}
		if (model != 0)
			for (int i = 0; i < 5; i++)
			{
				initial.name[i] = Pitch_to_notename(initial.step[i], initial.pitch[i]); // генеруємо назви нот (string)
			}


		// АНАЛІЗ

		system("cls");


		cout << "\nАкорд введено: ";
		for (int i = 0; i < numberofnotes; i++)
			cout << initial.name[i] << " - ";


	operation:
		int mode = Mode();

		Message(11, "\nОберіть операцію");
		cout << "\nВивести усі нонакорди в порядку обернень - 1\nВивести лише нонакорди з ноною у мелодичному положенні -2\nвивести лише акорди з інтервалом нони між крайніми голосами -3\nВивести усі акорди в порядку зростання діапазону - 4\nВивести нонакорди та обернення від заданої ноти - 5\nВивести нонакорди та обернення із заданим мелодичним тоном - 6 " << endl;
		int choice;
		cin >> choice;

		inverted[0] = initial;


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
								inverted[c].key[0] = initial.key[i]; //cout << initial.key[i];
								inverted[c].key[1] = initial.key[j]; //cout << initial.key[j];
								inverted[c].key[2] = initial.key[k]; //cout << initial.key[k];
								inverted[c].key[3] = initial.key[l]; //cout << initial.key[l];
								inverted[c].key[4] = initial.key[m]; //cout << initial.key[m] << endl;

								c++;
							}
						}

		for (int j = 0; j < c; j++)
			for (int i = 0; i < numberofnotes; i++)
			{
				inverted[j].pitch[i] = Key_to_pitch(inverted[j].key[i], notation); // висота (int)
				inverted[j].name[i] = Key_to_notename(inverted[j].key[i], notation); // назва (string)
				inverted[j].step[i] = Key_to_step(inverted[j].key[i], notation);  // ступінь від "до" (int)
			}
		;

		// визначення положення інтервалів
		for (int j = 0; j < c; j++)
			for (int i = 0; i < 5; i++)
			{
				if (inverted[j].key[i] == initial.key[0]) inverted[j].prima = i;
				if (inverted[j].key[i] == initial.key[1]) inverted[j].terzia = i;
				if (inverted[j].key[i] == initial.key[2]) inverted[j].quinta = i;
				if (inverted[j].key[i] == initial.key[3]) inverted[j].septyma = i;
				if (inverted[j].key[i] == initial.key[4]) inverted[j].nona = i;
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
				if (!(mode > 0 && inverted[j].nona - inverted[j].prima < 2))
				{
					for (int i = 0; i < numberofnotes; i++)
						polychords[sum] = inverted[j];

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
				if (!(mode > 0 && inverted[j].nona - inverted[j].prima < 2))
				{

					if (Stepdiff(initial.step[0], inverted[j].step[numberofnotes-1]) == 1)// !!
					{
						for (int i = 0; i < numberofnotes; i++)
							polychords[d] = inverted[j];
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
				if (!(mode > 0 && inverted[j].nona - inverted[j].prima < 2))
				{
					if (Stepdiff(inverted[j].step[0], inverted[j].step[numberofnotes-1]) == 1)
					{
						for (int i = 0; i < numberofnotes; i++)
							polychords[d] = inverted[j];
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
					if (!(mode > 0 && inverted[j].nona - inverted[j].prima < 2))
					{
						if (sum_steps(inverted[j].step, numberofintervals) == k)
						{
							for (int i = 0; i < numberofnotes; i++)
								polychords[sum] = inverted[j];
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
			destination = initialnote;
			Transposed[0].step[0] = Key_to_step(destination);
			Transposed[0].pitch[0] = Key_to_pitch(destination);



			for (int i = 0; i < 120; i++)
			{
				int stepshift = Stepdiff(inverted[i].step[0], Transposed[0].step[0]); // зсув про ступенях
				int pitchshift = Pitchdiff(inverted[i].pitch[0], Transposed[0].pitch[0]); // зсув по півтонах
				Transposed[i].prima = inverted[i].prima;
				Transposed[i].terzia = inverted[i].terzia;
				Transposed[i].quinta = inverted[i].quinta;
				Transposed[i].septyma = inverted[i].septyma;
				Transposed[i].nona = inverted[i].nona;

				for (int j = 0; j < 5; j++)
				{
					Transposed[i].step[j] = addstep(inverted[i].step[j], stepshift);  // транспонування
					Transposed[i].pitch[j] = addpitch(inverted[i].pitch[j], pitchshift); // транспонування
					Transposed[i].key[j] = Note_to_key(Transposed[i].step[j], Transposed[i].pitch[j]); // генерування key

				}
			}

			for (int j = 0; j < c; j++)
				for (int i = 0; i < 5; i++)
				{
					Transposed[j].name[i] = Pitch_to_notename(Transposed[j].step[i], Transposed[j].pitch[i]); // генеруємо назви нот (string)
				}


			for (int k = 6; k < 50; k++)
				for (int j = 0; j < c; j++)
				{
					if (!(mode > 0 && Transposed[j].nona - Transposed[j].prima < 2))
					{
						if (sum_pitchs(Transposed[j].pitch, numberofintervals) == k)
						{
							for (int i = 0; i < 5; i++)
								polychords[sum] = Transposed[j]; // записуємо значеня у множину акордів, які передаються у main
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
			destination = initialnote; // вводиться 
			Transposed[0].step[4] = Key_to_step(destination);
			Transposed[0].pitch[4] = Key_to_pitch(destination);


			for (int i = 0; i < 120; i++)
			{
				int stepshift = Stepdiff(inverted[i].step[4], Transposed[0].step[4]); // зсув про ступенях
				int pitchshift = Pitchdiff(inverted[i].pitch[4], Transposed[0].pitch[4]); // зсув по півтонах
				Transposed[i].prima = inverted[i].prima;
				Transposed[i].terzia = inverted[i].terzia;
				Transposed[i].quinta = inverted[i].quinta;
				Transposed[i].septyma = inverted[i].septyma;
				Transposed[i].nona = inverted[i].nona;

				for (int j = 0; j < 5; j++)
				{
					Transposed[i].step[j] = addstep(inverted[i].step[j], stepshift);  // транспонування
					Transposed[i].pitch[j] = addpitch(inverted[i].pitch[j], pitchshift); // транспонування
				}
			}

			for (int j = 0; j < c; j++)
				for (int i = 0; i < 5; i++)
				{
					Transposed[j].name[i] = Pitch_to_notename(Transposed[j].step[i], Transposed[j].pitch[i]); // генеруємо назви нот (string)
					Transposed[j].key[i] = Note_to_key(Transposed[j].step[i], Transposed[j].pitch[i]); // генерування key
				}

			for (int k = 6; k < 50; k++)
				for (int j = 0; j < c; j++)
				{
					if (!(mode > 0 && Transposed[j].nona - Transposed[j].prima < 2))
					{
						if (sum_pitchs(Transposed[j].pitch, numberofintervals) == k)
						{
							for (int i = 0; i < 5; i++)
								polychords[sum] = Transposed[j];
							sum++;
						}
					}
				}

			allsum(sum);
		}
		else
		{
			Message(12, "спробуйте ще раз");
			goto operation;
		}

		float consonansrate = Consonans_rate(polychords[0].step, polychords[0].pitch, 5); // консонантність

		// РЕЗУЛЬТАТИ НА ЕКРАН

		tableheader(header);

		for (int j = 0; j < sum; j++)
		{
			for (int i = 0; i < numberofnotes; i++)
			{
				cout << setw(3) << polychords[j].name[i] << setw(1) << " \t";
			}
			cout << setw(1) << " | " << setw(2) << sum_steps(polychords[j].step, numberofintervals) << setw(1) << " ";
			cout << setw(1) << " | " << setw(2) << sum_pitchs(polychords[j].pitch, numberofintervals) << endl;
		}

		tablefooter(consonansrate, true, sum);

		oncemore = Oncemore();

	}

	modifications = sum;
}

