// Chord_inversions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Notes.h"

string Note_to_key(int step, int pitch);


void Chord_inversions1_1(Polychord* polychords, int& modifications)
{
	fstream myFile;
	int numberofintervals = 4;
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
		cout << "1 - мажорний, 2 - домінантовий, 3 - мінорний, 4 - мажорний із секстою, 0 - ввести вручну " << endl;
		cin >> model;
		if (model > 4 || model < 0) model = 0;
		cout << endl << notes;


		// основні характеристики для кожного звука
		string initialnote; // для побудови нонакорду за моделлю
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
				Message(11, "Введіть 5 звуків");

				for (int i = 0; i < 5; i++)
					cin >> key[i];
				for (int i = 0; i < 5; i++)
				{
					initial.key[i] = key[i]; // назва ноти, string
					initial.step[i] = Key_to_step(key[i], notation);  // ступінь від "до", int
					initial.pitch[i] = Key_to_pitch(key[i], notation); // висота в півтонах від "до", int
					initial.name[i] = Key_to_notename(key[i], notation); // назва ноти, string
				}
				for (int i = 0; i < 4; i++)
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
			if (model == 6) Message(11, "Введіть мелодичний тон");
			else Message(11, "Введіть основний тон");

			do
			{
				cin >> initialnote;

				if (Key_to_step(initialnote, notation) == -100)
					Message(12, "помилка при введенні ноти, спробуйте ще!");
			} while (Key_to_step(initialnote, notation) == -100);

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
		myFile.open("ninechords.txt", ios::out);
		myFile << "Акорд введено:\n";

		cout << "\nАкорд введено: ";
		for (int i = 0; i < 5; i++)
		{
			cout << initial.name[i] << " - ";
			myFile << initial.name[i] << " - ";

		}


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
			for (int i = 0; i < 5; i++)
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

		if (choice == 1)
			// вводимо список на екран
		{
			Message(11, "Усі нонакроди");
			Line();
			Message(11, "Акорди\t\t| діапазон (ступенів)");
			myFile << "Усі нонакроди" << endl;
			for (int j = 0; j < c; j++)
			{
				if (!(mode > 0 && inverted[j].nona - inverted[j].prima < 2))
				{
					for (int i = 0; i < 5; i++)
					{

						{
							cout << inverted[j].name[i] << "\t";
							myFile << inverted[j].name[i] << "\t";

						}
					}

					cout << "| " << sum_steps(inverted[j].step, numberofintervals) << endl;
					myFile << "| " << sum_steps(inverted[j].step, numberofintervals) << endl;
					sum++;
				}
			}
			allsum(sum);
		}

		else if (choice == 2)
		{
			// нонакорди з ноною на горі.
			int d = 0, e = 0;

			Message(11, "нонакроди з ноною в мелодичному положенні");
			myFile << longline << "нонакроди з ноною в мелодичному положенні" << endl;
			for (int j = 0; j < c; j++)
			{
				if (!(mode > 0 && inverted[j].nona - inverted[j].prima < 2))
				{

					if (Stepdiff(initial.step[0], inverted[j].step[4]) == 1)// !!
					{
						for (int i = 0; i < 5; i++)
						{
							cout << setw(3) << inverted[j].name[i] << setw(1) << "\t";
							myFile << setw(3) << inverted[j].name[i] << setw(1) << "\t";
						}

						d++;
						cout << "\tдіапазон (ступенів): " << sum_steps(inverted[j].step, numberofintervals) << endl;
						myFile << "\tдіапазон (ступенів): " << sum_steps(inverted[j].step, numberofintervals) << endl;
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
				if (!(mode > 0 && inverted[j].nona - inverted[j].prima < 2))
				{
					if (Stepdiff(inverted[j].step[0], inverted[j].step[4]) == 1)
					{
						for (int i = 0; i < 5; i++)
							cout << inverted[j].name[i] << "\t";
						d++;
						cout << "\tдіапазон (ступенів): " << sum_steps(inverted[j].step, numberofintervals) << endl;
						myFile << "\tдіапазон (ступенів): " << sum_steps(inverted[j].step, numberofintervals) << endl;
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
					if (!(mode > 0 && inverted[j].nona - inverted[j].prima < 2))
					{
						if (sum_steps(inverted[j].step, numberofintervals) == k)
						{
							for (int i = 0; i < 5; i++)
							{
								cout << inverted[j].name[i] << "\t";
								//Polychord[n] = inverted[j]
								n++;
								myFile << inverted[j].name[i] << "\t";
							}
							cout << "\tдіапазон акорду: " << sum_steps(inverted[j].step, numberofintervals) << endl;
							myFile << "\tдіапазон акорду: " << sum_steps(inverted[j].step, numberofintervals) << endl;
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
							{
								cout << setw(3) << Transposed[j].name[i] << setw(1) << " \t";
								myFile << setw(3) << Transposed[j].name[i] << setw(1) << " \t";
							}
							cout << "\tдіапазон (півтонів): " << sum_pitchs(Transposed[j].pitch, numberofintervals) << endl;
							myFile << "\tдіапазон (півтонів): " << sum_pitchs(Transposed[j].pitch, numberofintervals) << endl;
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
							{
								cout << setw(3) << Transposed[j].name[i] << setw(1) << " \t";
								myFile << setw(3) << Transposed[j].name[i] << setw(1) << " \t";
							}

							cout << "\tдіапазон (півтонів): " << sum_pitchs(Transposed[j].pitch, numberofintervals) << endl;
							myFile << "\tдіапазон (півтонів): " << sum_pitchs(Transposed[j].pitch, numberofintervals) << endl;
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
		cout << "Спробувати ще? 1 - так, 0 - вихід з програми";
		cin >> oncemore;

	}
	cout << longline;
	Message(11, "Дякуємо за використання програми!");
	myFile.close();

	for (int j = 0; j < 120; j++)
		for (int i = 0; i < 5; i++)
		{
			if (model >= 5) polychords[j] = Transposed[j];
			if (model < 5) polychords[j] = inverted[j];
		}

	modifications = sum;

}

