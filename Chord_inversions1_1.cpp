// Chord_inversions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Notes.h"




using namespace std;
using std::string;

string note_to_key(int step, int pitch);


void Chord_inversions1_1(Polychord* Polychords, int& modifications)
{
	fstream myFile;
	int NoI = 4;
	Polychord Initial;
	Polychord Inverted[120];
	Polychord Transposed[120];
	string notes = pnotes();
	string longline = Longline();
	int model;
	int sum;


	bool oncemore = 1;
	while (oncemore)
	{
		color(11);
		cout << "\nоберіть модель нонакорда: \n";
		color(7);
		cout << "1 - мажорний, 2 - домінантовий, 3 - мінорний, 4 - мажорний із секстою, 0 - ввести вручну " << endl;
		cin >> model;
		if (model > 4 || model < 0) model = 0;
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
				title(11, "Введіть 5 звуків");

				for (int i = 0; i < 5; i++)
					cin >> key[i];
				for (int i = 0; i < 5; i++)
				{
					Initial.key[i] = key[i]; // назва ноти, string
					Initial.step[i] = key_to_step(key[i], notation);  // ступінь від "до", int
					Initial.pitch[i] = key_to_pitch(key[i], notation); // висота в півтонах від "до", int
					Initial.name[i] = key_to_notename(key[i], notation); // назва ноти, string
				}
				for (int i = 0; i < 4; i++)
					if (stepdiff(Initial.step[i], Initial.step[i + 1]) != 2)
					{
						title(12, "введений акорд не є нонакордом. Все одно продовжити? 1 - так, 0 - спробуати знову");
						cin >> repeat;
						break;
					}
					else repeat = 1;
			} while (!repeat);
			initial = key[0];
		}

		else
		{
			if (model == 6) title(11, "Введіть мелодичний тон");
			else title(11, "Введіть основний тон");

			do
			{
				cin >> initial;

				if (key_to_step(initial, notation) == -100)
					title(12, "помилка при введенні ноти, спробуйте ще!");
			} while (key_to_step(initial, notation) == -100);

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
		myFile.open("ninechords.txt", ios::out);
		myFile << "Акорд введено:\n";

		cout << "\nАкорд введено: ";
		for (int i = 0; i < 5; i++)
		{
			cout << Initial.name[i] << " - ";
			myFile << Initial.name[i] << " - ";

		}


	operation:
		int mode = Mode();

		title(11, "\nОберіть операцію");
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

		if (choice == 1)
			// вводимо список на екран
		{
			title(11, "Усі нонакроди");
			Line();
			title(11, "Акорди\t\t| діапазон (ступенів)");
			myFile << "Усі нонакроди" << endl;
			for (int j = 0; j < c; j++)
			{
				if (!(mode > 0 && Inverted[j].nona - Inverted[j].prima < 2))
				{
					for (int i = 0; i < 5; i++)
					{

						{
							cout << Inverted[j].name[i] << "\t";
							myFile << Inverted[j].name[i] << "\t";

						}
					}

					cout << "| " << sum_steps(Inverted[j].step, NoI) << endl;
					myFile << "| " << sum_steps(Inverted[j].step, NoI) << endl;
					sum++;
				}
			}
			allsum(sum);
		}

		else if (choice == 2)
		{
			// нонакорди з ноною на горі.
			int d = 0, e = 0;

			title(11, "нонакроди з ноною в мелодичному положенні");
			myFile << longline << "нонакроди з ноною в мелодичному положенні" << endl;
			for (int j = 0; j < c; j++)
			{
				if (!(mode > 0 && Inverted[j].nona - Inverted[j].prima < 2))
				{

					if (stepdiff(Initial.step[0], Inverted[j].step[4]) == 1)// !!
					{
						for (int i = 0; i < 5; i++)
						{
							cout << setw(3) << Inverted[j].name[i] << setw(1) << "\t";
							myFile << setw(3) << Inverted[j].name[i] << setw(1) << "\t";
						}

						d++;
						cout << "\tдіапазон (ступенів): " << sum_steps(Inverted[j].step, NoI) << endl;
						myFile << "\tдіапазон (ступенів): " << sum_steps(Inverted[j].step, NoI) << endl;
					}
					else e++;
				}


			}
			cout << "\nнайдено акордів: " << d << endl;
			cout << "\nПроігноровано: " << e << endl;
			myFile << "\nнайдено акордів: " << d << endl;
			myFile << "\nПроігноровано: " << e << endl;
			sum = d;
		}

		else if (choice == 3)	// нонакорди з ноною між крайніми голосами.
		{
			int d = 0, e = 0;

			cout << longline << "нонакроди з інтервалом нона між крайніми голосами" << endl;
			for (int j = 0; j < c; j++)
			{
				if (!(mode > 0 && Inverted[j].nona - Inverted[j].prima < 2))
				{
					if (stepdiff(Inverted[j].step[0], Inverted[j].step[4]) == 1)
					{
						for (int i = 0; i < 5; i++)
							cout << Inverted[j].name[i] << "\t";
						d++;
						cout << "\tдіапазон (ступенів): " << sum_steps(Inverted[j].step, NoI) << endl;
						myFile << "\tдіапазон (ступенів): " << sum_steps(Inverted[j].step, NoI) << endl;
					}
					else e++;
				}


			}
			cout << "\nЗнайдено акордів: " << d << endl;
			cout << "\nПроігноровано: " << e << endl;
			myFile << "\nнайдено акордів: " << d << endl;
			myFile << "\nПроігноровано: " << e << endl;
			sum = d;
		}


		else if (choice == 4)
			// нонакорди за зростанням діапазону.
		{
			cout << "\nНонакроди за зростанням діапазону" << endl;
			myFile << "\nНонакроди за зростанням діапазону" << endl;
			int n = 0;

			for (int k = 6; k < 26; k++)
				for (int j = 0; j < c; j++)
				{
					if (!(mode > 0 && Inverted[j].nona - Inverted[j].prima < 2))
					{
						if (sum_steps(Inverted[j].step, NoI) == k)
						{
							for (int i = 0; i < 5; i++)
							{
								cout << Inverted[j].name[i] << "\t";
								//Polychord[n] = Inverted[j]
								n++;
								myFile << Inverted[j].name[i] << "\t";
							}
							cout << "\tдіапазон акорду: " << sum_steps(Inverted[j].step, NoI) << endl;
							myFile << "\tдіапазон акорду: " << sum_steps(Inverted[j].step, NoI) << endl;
							sum++;
						}
					}
				}
			allsum(sum);
		}

		else if (choice == 5)

		{

			// нонакорди за зростанням діапазону.
			cout << "\nНонакроди за зростанням діапазону від заданої ноти" << endl;
			myFile << "\nНонакроди за зростанням діапазону від заданої ноти" << endl;

			destination = initial;
			Transposed[0].step[0] = key_to_step(destination);
			Transposed[0].pitch[0] = key_to_pitch(destination);



			for (int i = 0; i < 120; i++)
			{
				int stepshift = stepdiff(Inverted[i].step[0], Transposed[0].step[0]); // зсув про ступенях
				int pitchshift = pitchdiff(Inverted[i].pitch[0], Transposed[0].pitch[0]); // зсув по півтонах
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
							{
								cout << setw(3) << Transposed[j].name[i] << setw(1) << " \t";
								myFile << setw(3) << Transposed[j].name[i] << setw(1) << " \t";
							}
							cout << "\tдіапазон (півтонів): " << sum_pitchs(Transposed[j].pitch, NoI) << endl;
							myFile << "\tдіапазон (півтонів): " << sum_pitchs(Transposed[j].pitch, NoI) << endl;
							sum++;
						}
					}

				}

			allsum(sum);
		}
		else if (choice == 6)

		{

			// нонакорди за зростанням діапазону.
			cout << "\nНонакроди за зростанням діапазону із заданим мелодичним тоном" << endl;

			destination = initial; // вводиться 
			Transposed[0].step[4] = key_to_step(destination);
			Transposed[0].pitch[4] = key_to_pitch(destination);


			for (int i = 0; i < 120; i++)
			{
				int stepshift = stepdiff(Inverted[i].step[4], Transposed[0].step[4]); // зсув про ступенях
				int pitchshift = pitchdiff(Inverted[i].pitch[4], Transposed[0].pitch[4]); // зсув по півтонах
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
							{
								cout << setw(3) << Transposed[j].name[i] << setw(1) << " \t";
								myFile << setw(3) << Transposed[j].name[i] << setw(1) << " \t";
							}

							cout << "\tдіапазон (півтонів): " << sum_pitchs(Transposed[j].pitch, NoI) << endl;
							myFile << "\tдіапазон (півтонів): " << sum_pitchs(Transposed[j].pitch, NoI) << endl;
							sum++;
						}
					}
				}

			allsum(sum);
		}

		else
		{
			title(12, "спробуйте ще раз");
			goto operation;
		}
		cout << "Спробувати ще? 1 - так, 0 - вихід з програми";
		cin >> oncemore;

	}
	cout << longline;
	title(11, "Дякуємо за використання програми!");
	myFile.close();

	for (int j = 0; j < 120; j++)
		for (int i = 0; i < 5; i++)
		{
			if (model >= 5) Polychords[j] = Transposed[j];
			if (model < 5) Polychords[j] = Inverted[j];
		}

	modifications = sum;

}

