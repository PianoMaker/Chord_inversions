// Chord_inversions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
using std::string;
string longline = "\n_________________\n";
enum NOTES { DO, RE, MI, FA, SOL, LA, SI };




// ВИЗНАЧЕННЯ СТУПЕНЮ (ВІДНОСНО ДО)
// введеної за клавіатури ноти 

int key_to_step(string key, int notation = 1)
{
	string note_as_written(key, 0, 1);
	string n_acc(key, 1, 4);

	int notes;

	if (note_as_written == "c")
	{
		notes = DO;
	}
	else if (note_as_written == "d")
	{
		notes = RE;
	}
	else if (note_as_written == "e")
	{
		notes = MI;
	}
	else if (note_as_written == "f")
	{
		notes = FA;
	}
	else if (note_as_written == "g")
	{
		notes = SOL;
	}
	else if (note_as_written == "a")
	{
		notes = LA;
	}
	else if (note_as_written == "b" && (notation) && n_acc == "is")
	{
		return -100;
	}
	else if (note_as_written == "h" && (notation) && n_acc == "es")
	{
		return -100;
	}
	else if (note_as_written == "b" && (notation))
	{
		notes = SI;
	}
	else if (note_as_written == "b")
	{
		notes = SI;
	}
	else if (note_as_written == "h")
	{
		if (notation)
		{
			notes = SI;
		}
		else
		{
			return -100;
		}
	}
	else
	{
		return -100;
	}

	return notes;
}

/// ВИЗНАЧЕННЯ НАЗВИ НОТИ (СЛОВАМИ)
//string key_to_notename(string key, int notation = 1)
string key_to_notename(string key, int notation = 1)
{
	string note_as_written(key, 0, 1);
	string n_acc(key, 1, 4);
	string notename;
	string noteaccname;

	if (note_as_written == "c")
	{
		notename = "до";
	}
	else if (note_as_written == "d")
	{
		notename = "ре";
	}
	else if (note_as_written == "e")
	{
		notename = "мі";
	}
	else if (note_as_written == "f")
	{
		notename = "фа";
	}
	else if (note_as_written == "g")
	{
		notename = "соль";
	}
	else if (note_as_written == "a")
	{
		notename = "ля";
	}
	else if ((note_as_written == "b" && (notation) && n_acc == "is") || (note_as_written == "b" && (notation) && n_acc == "isis"))
		return "Помилка при введенні ноти\n";

	else if (note_as_written == "h" && (notation) && n_acc == "es")
		return "Помилка при введенні ноти\n";

	else if (note_as_written == "b" && (notation) && n_acc == "es")
		notename = "сі";

	else if (note_as_written == "b" && (notation))
	{
		notename = "сі ь";
	}
	else if (note_as_written == "b" && (!notation))
	{
		notename = "сі";
	}
	else if (note_as_written == "h")
	{
		if (notation)
		{
			notename = "сі";
		}
		else
		{
			return "Помилка при введенні ноти\n";
		}
	}
	else
	{
		return "Помилка при введенні ноти\n";
	}

	if (n_acc == "")
		noteaccname = "";
	else if (n_acc == "isis" && (notation) || n_acc == "##" && (!notation) || n_acc == "x" && (!notation))
	{
		noteaccname = " х";
	}
	else if (n_acc == "eses" && (notation) || n_acc == "ses" && (notation) || n_acc == "bb")
	{
		noteaccname = " ьь";
	}
	else if (n_acc == "is" && (notation) || n_acc == "#" && (!notation))
	{
		noteaccname = " #";
	}
	else if (n_acc == "es" && note_as_written == "b" && (notation))
	{
		noteaccname = " ьь";
	}
	else if (n_acc == "es" && (notation) || n_acc == "s" && (notation) || n_acc == "b" && (!notation))
	{
		noteaccname = " ь";
	}

	else
	{
		return "Помилка при введенні ноти\n";
	}

	string key_to_notename(notename + noteaccname);

	return key_to_notename;
}

/// ВИЗНАЧЕННЯ АБСОЛЮТНОЇ ВИСОТИ ЗВУКА (У ПІВТОНАХ від рівня ДО)

string step_to_notename(int step, int alter)
{
	string notename;
	string noteaccname;
	//cout << "test1 step =" << step << "\n";
	//cout << "test1 alter =" << alter << "\n";
	if (step == -1)
	{
		notename = "--";
	}
	else if (step > 6)
		step -= 7;
	else;
	//cout << "test2 step =" << step << "\n";
	if (step == DO)
	{
		notename = "до";
	}
	else if (step == RE)
	{
		notename = "ре";
	}
	else if (step == MI)
	{
		notename = "мі";
	}
	else if (step == FA)
	{
		notename = "фа";
	}
	else if (step == SOL)
	{
		notename = "соль";
	}
	else if (step == LA)
	{
		notename = "ля";
	}
	else if (step == SI)
	{
		notename = "сі";
	}

	else
	{
		return "Помилка при введенні ноти\n";
	}

	if (alter == 0)
		noteaccname = "";
	else if (alter == 2)
	{
		noteaccname = " х";
	}
	else if (alter == -2)
	{
		noteaccname = " ьь";
	}
	else if (alter == 1)
	{
		noteaccname = " #";
	}
	else if (alter == -1)
	{
		noteaccname = " ь";
	}

	else
	{
		return "Помилка при введенні ноти\n";
	}
	string key_to_notename(notename + noteaccname);

	return key_to_notename;
}

/// ВИЗНАЧЕННЯ НАЗВИ НОТИ (ЗА СТУПІННЮ І ВИСОТОЮ) 

string pitch_to_notename(int step, int pitch)
{
	string notename;
	string noteaccname;
	int alter, standartpitch;
	//cout << "test1 step =" << step << "\n";
	if (step == -1)
	{
		notename = "--";
	}
	else if (step > 6)
		step -= 7;
	else;
	//cout << "test2 step =" << step << "\n";
	if (step == DO)
	{
		notename = "до"; standartpitch = 0;
	}
	else if (step == RE)
	{
		notename = "ре"; standartpitch = 2;
	}
	else if (step == MI)
	{
		notename = "мі"; standartpitch = 4;
	}
	else if (step == FA)
	{
		notename = "фа"; standartpitch = 5;
	}
	else if (step == SOL)
	{
		notename = "соль"; standartpitch = 7;
	}
	else if (step == LA)
	{
		notename = "ля"; standartpitch = 9;
	}
	else if (step == SI)
	{
		notename = "сі"; standartpitch = 11;
	}

	else
	{
		return "Помилка при введенні ноти\n";
	}

	alter = pitch - standartpitch;
	if (alter == 0)
		noteaccname = "";
	else if (alter == 11 && standartpitch == 0)
	{
		alter == -1; noteaccname = " ь";
	}
	else if (pitch == 0 && standartpitch == 11)
	{
		alter == 1; noteaccname = " #";
	}
	else if (alter == 2)
	{
		noteaccname = " х";
	}
	else if (alter == -2)
	{
		noteaccname = " ьь";
	}
	else if (alter == 1)
	{
		noteaccname = " #";
	}
	else if (alter == -1)
	{
		noteaccname = " ь";
	}

	else
	{
		return "Помилка при введенні ноти\n";
	}

	string key_to_notename(notename + noteaccname);

	return key_to_notename;
}


int key_to_pitch(string key, int notation = 1)
{
	string note_as_written(key, 0, 1);
	string n_acc(key, 1, 4);

	int notation_type = notation;
	/*cout << note_as_written << " (тест)\t";*/

	int pitch, alteration;

	if (note_as_written == "c")
	{
		pitch = 0;
	}
	else if (note_as_written == "d")
	{
		pitch = 2;
	}
	else if (note_as_written == "e")
	{
		pitch = 4;
	}
	else if (note_as_written == "f")
	{
		pitch = 5;
	}
	else if (note_as_written == "g")
	{
		pitch = 7;
	}
	else if (note_as_written == "a")
	{
		pitch = 9;

	}
	else if ((note_as_written == "b" && (notation) && n_acc == "is") || (note_as_written == "b" && (notation) && n_acc == "isis"))

		return -100;

	else if (note_as_written == "h" && (notation) && n_acc == "es")

		return -100;

	else if (note_as_written == "b" && (notation_type))
	{
		pitch = 10;
	}
	else if (note_as_written == "b")
	{
		pitch = 11;
	}
	else if (note_as_written == "h")
	{
		if (notation_type)
		{
			pitch = 11;
		}
		else
		{
			return -100;
		}
	}
	else
	{
		return -100;
	}

	if (n_acc == "")
		alteration = 0;
	else if (n_acc == "isis" && (notation) || n_acc == "##" && (!notation) || n_acc == "x" && (!notation))
	{
		alteration = 2;
	}
	else if (n_acc == "eses" && (notation) || n_acc == "ses" && (notation) || n_acc == "bb")
	{
		alteration = -2;
	}
	else if (n_acc == "is" && (notation) || n_acc == "#" && (!notation))
	{
		alteration = 1;
	}
	else if (n_acc == "es" && note_as_written == "b" && (notation))
	{
		alteration = -1;
	}
	else if (n_acc == "es" && (notation) || n_acc == "s" && (notation) || n_acc == "b" && (!notation))
	{
		alteration = -1;
	}
	else alteration = 0;

	return pitch + alteration;
}

/// ВПЛИВ ЗНАКІВ АЛЬТЕРАЦІЇ НА ВИСОТУ ЗВУКА


int pitchchange(string n_acc, string note_as_written, int notation = 1)  // "notation" означає тип нотації - європейський 
{
	int pitchalteration;
	if (n_acc == "")
		pitchalteration = 0;
	else if (n_acc == "isis" && (notation) || n_acc == "##" && (!notation) || n_acc == "x" && (!notation))
	{
		pitchalteration = 2;
	}
	else if (n_acc == "is" && (notation) || n_acc == "#" && (!notation))
	{
		pitchalteration = 1;
	}
	else if (n_acc == "es" && note_as_written == "b" && (notation))
	{
		pitchalteration = -1;
	}
	else if (n_acc == "eses" && (notation) || n_acc == "ses" && (notation) || n_acc == "bb" && (!notation))
	{
		pitchalteration = -2;
	}
	else if (n_acc == "es" && (notation) || n_acc == "s" && (notation) || n_acc == "b" && (!notation))
	{
		pitchalteration = -1;
	}
	else
	{
		return -100;
	}
	return pitchalteration;
}

/* Підрахунок інтервалів між нотами.
Виходимо з того, що кожен наступний голос вищий за попередній,
тому за потреби додаємо до вищого голосу октаву: 7 ступенів або 12 півтонів
*/


int stepdiff(int low_note, int high_note)
{
	if (low_note > high_note) high_note += 7;
	int interval = high_note - low_note;
	return interval;
}

int pitchdiff(int low_pitch, int high_pitch)
{
	if (low_pitch > high_pitch) high_pitch += 12;
	//cout << "\nhigh_pitch - low_pitch: " << high_pitch << " - " << low_pitch;
	int halftones = high_pitch - low_pitch;
	return halftones;
}

int addstep(int step1, int step2)
{
	int step = step1 + step2;
	if (step < 0) step += 7;
	if (step > 6) step -= 7;
	return step;
}

int addpitch(int pitch1, int pitch2)
{
	int pitch = pitch1 + pitch2;
	if (pitch < 0) pitch += 12;
	if (pitch > 11) pitch -= 12;
	return pitch;
}

int sum_steps(int step[5])
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
		sum += stepdiff(step[i], step[i + 1]);
	return sum;

}

int sum_pitchs(int pitch[5])
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
		sum += pitchdiff(pitch[i], pitch[i + 1]);
	return sum;

}


void start()
{
	cout << "Вас вітає програма генерування нонакордів у різних розташуваннях!";

}

string notes = "Для введення нот використовуйте європейську буквенну нотацію \nс - до, \nd - ре, \ne - мі, \nf - фа, \ng - соль, \na - ля\n b - сі - бемоль\n h - сі \nis - дiєз, \n es - бемоль  \n";
// todo: додати американську як опцію


string note_to_key(int step, int pitch)
{
	string notename;
	string noteaccname;
	int alter, standartpitch;
	//cout << "test1 step =" << step << "\n";
	if (step == -1)
	{
		notename = "--";
	}
	else if (step > 6)
		step -= 7;
	else;
	//cout << "test2 step =" << step << "\n";
	if (step == DO)
	{
		notename = "c"; standartpitch = 0;
	}
	else if (step == RE)
	{
		notename = "d"; standartpitch = 2;
	}
	else if (step == MI)
	{
		notename = "e"; standartpitch = 4;
	}
	else if (step == FA)
	{
		notename = "f"; standartpitch = 5;
	}
	else if (step == SOL)
	{
		notename = "g"; standartpitch = 7;
	}
	else if (step == LA)
	{
		notename = "a"; standartpitch = 9;
	}
	else if (step == SI)
	{
		notename = "h"; standartpitch = 11;
	}

	else
	{
		return "Помилка при введенні ноти\n";
	}

	alter = pitch - standartpitch;
	if (alter == 0)
		noteaccname = "";
	else if (step == SI && pitch == 0)
	{
		notename = "h"; noteaccname = "is";
	}

	else if (alter == 2)
	{
		noteaccname = "isis";
	}
	else if (alter == -2)
	{
		noteaccname = "eses";
	}
	else if (alter == 1)
	{
		noteaccname = "is";
	}
	else if (alter == -1)
	{
		noteaccname = "es";
	}

	else
	{
		return "Помилка при введенні ноти\n";
	}

	string key_to_notename(notename + noteaccname);

	if (key_to_notename == "hes") key_to_notename = "b";
	if (key_to_notename == "heses") key_to_notename = "bes";

	return key_to_notename;
}



int main()
{
	fstream myFile;
	myFile.open("ninechords.txt", ios::out);
	if (myFile.is_open())
	{
		myFile << "Побудова нонакордів\n";
		myFile.close();
	}
	start();
	system("pause>0");
	bool oncemore = 1;
	while (oncemore)
	{
		cout << "\nоберіть модель нонакорда: 1 - мажорний, 2 - великий домінантовий, 3 - малий мінорний, 0 - ввести вручну " << endl;
		int model;
		cin >> model;
		if (model > 3 || model < 0) model = 0;
		cout << endl << notes;


		struct Nonchord
		{
			string key[5]; // назва латинкою
			string name[5]; // назва кирилицею
			int step[5]; // ступінь від до=0
			int pitch[5]; // півтони від до=0
			int position[5]; // позиція в акорді
		};

		// основні характеристики для кожного звука
		string initial; // для побудови нонакорду за моделлю
		string key[5]; // ручне введення нонакорду 
		string name[5]; // назва кирилицею
		int pitch[5]; // висота звуку (у півтонах) в кожному з голосів
		int step[5]; // ступінь у кожному з голосів
		string destination; // для транспозиції
		bool notation = 1; //змінна для переключення європейської та американської нотації (поки що не розроблено)

		Nonchord Initial;
		Nonchord Inverted[120];
		Nonchord Transposed[120];

		//ВВЕСТИ АКОРД

		if (model == 0)
		{
			bool repeat = 0;
			do
			{
				cout << "Введіть 5 звуків" << endl;
				for (int i = 0; i < 5; i++)
					cin >> key[i];
				for (int i = 0; i < 5; i++)
				{
					Initial.key[i] = key[i]; // назва ноти, string
					Initial.step[i] = key_to_step(key[i], notation);  // ступінь від "до", int
					Initial.pitch[i] = key_to_pitch(key[i], notation); // висота в півтонах від "до", int
					Initial.name[i] = key_to_notename(key[i], notation); // назва ноти, string
					Initial.position[i] = i;
				}
				for (int i = 0; i < 4; i++)
					if (stepdiff(Initial.step[i], Initial.step[i + 1]) != 2)
					{
						cout << "введений акорд не є нонакордом. Все одно продовжити? 0 - так, 1 - спробуати знову" << endl;
						cin >> repeat;
						break;
					}
					else repeat = 0;
			} while (repeat);
		}

		else
		{
			cout << "Введіть основний тон" << endl;
			cin >> initial;
			Initial.step[0] = key_to_step(initial, notation);
			Initial.pitch[0] = key_to_pitch(initial, notation);
			Initial.step[1] = addstep(Initial.step[0], 2);
			Initial.step[2] = addstep(Initial.step[1], 2);
			Initial.step[3] = addstep(Initial.step[2], 2);
			Initial.step[4] = addstep(Initial.step[3], 2);
			Initial.pitch[2] = addpitch(Initial.pitch[0], 7);
			Initial.pitch[4] = addpitch(Initial.pitch[0], 2);

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
			}
			for (int i = 0; i < 5; i++)
			{
				Initial.position[i] = i;
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

		myFile.open("ninechords.txt", ios::app);
		myFile << "Акорд введено:\n";

		cout << "\nАкорд введено: ";
		for (int i = 0; i < 5; i++)
		{
			cout << Initial.name[i] << " - ";
			myFile << Initial.name[i] << " - ";

		}


	operation:
		cout << "\nОберіть операцію" << endl;
		cout << "\nВивести усі нонакорди в порядку обернень - 1\n Вивести лише нонакорди з ноною у мелодичному положенні -2\n вивести лише акорди з інтервалом нони між крайніми голосами -3\n Вивести усі акорди в порядку зростання діапазону - 4\nвивести нонакорди та обернення від заданої ноти - 5" << endl;
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

		if (choice == 1)
			// вводимо список на екран
		{
			cout << "Усі нонакроди" << endl;
			myFile << "Усі нонакроди" << endl;
			for (int j = 0; j < c; j++)
			{
				for (int i = 0; i < 5; i++)
				{
					cout << Inverted[j].name[i] << "\t";
					myFile << Inverted[j].name[i] << "\t";
				}
				cout << "\tдіапазон (ступенів): " << sum_steps(Inverted[j].step) << endl;
				myFile << "\tдіапазон (ступенів): " << sum_steps(Inverted[j].step) << endl;
			}
			cout << "\nусього: " << c << endl;
		}

		else if (choice == 2)
		{
			// нонакорди з ноною на горі.
			int d = 0, e = 0;

			cout << longline << "нонакроди з ноною в мелодичному положенні" << endl;
			myFile << longline << "нонакроди з ноною в мелодичному положенні" << endl;
			for (int j = 0; j < c; j++)
			{
				if (stepdiff(Initial.step[0], Inverted[j].step[4]) == 1)
				{
					for (int i = 0; i < 5; i++)
						cout << Inverted[j].name[i] << "\t";
					d++;
					cout << "\tдіапазон (ступенів): " << sum_steps(Inverted[j].step) << endl;
					myFile << "\tдіапазон (ступенів): " << sum_steps(Inverted[j].step) << endl;
				}
				else e++;


			}
			cout << "\nнайдено акордів: " << d << endl;
			cout << "\nПроігноровано: " << e << endl;
			myFile << "\nнайдено акордів: " << d << endl;
			myFile << "\nПроігноровано: " << e << endl;
		}

		else if (choice == 3)	// нонакорди з ноною між крайніми голосами.
		{
			int d = 0, e = 0;

			cout << longline << "нонакроди з інтервалом нона між крайніми голосами" << endl;
			for (int j = 0; j < c; j++)
			{
				if (stepdiff(Inverted[j].step[0], Inverted[j].step[4]) == 1)
				{
					for (int i = 0; i < 5; i++)
						cout << Inverted[j].name[i] << "\t";
					d++;
					cout << "\tдіапазон (ступенів): " << sum_steps(Inverted[j].step) << endl;
					myFile << "\tдіапазон (ступенів): " << sum_steps(Inverted[j].step) << endl;
				}
				else e++;


			}
			cout << "\nЗнайдено акордів: " << d << endl;
			cout << "\nПроігноровано: " << e << endl;
			myFile << "\nнайдено акордів: " << d << endl;
			myFile << "\nПроігноровано: " << e << endl;
		}


		else if (choice == 4)
			// нонакорди за зростанням діапазону.
		{
			cout << "\nНонакроди за зростанням діапазону" << endl;
			myFile << "\nНонакроди за зростанням діапазону" << endl;

			for (int k = 6; k < 26; k++)
				for (int j = 0; j < c; j++)

				{
					if (sum_steps(Inverted[j].step) == k)
					{
						for (int i = 0; i < 5; i++)
						{
							cout << Inverted[j].name[i] << "\t";
							myFile << Inverted[j].name[i] << "\t";
						}
						cout << "\tдіапазон акорду: " << sum_steps(Inverted[j].step) << endl;
						myFile << "\tдіапазон акорду: " << sum_steps(Inverted[j].step) << endl;
					}
				}
			cout << "\nусього: " << c << endl;
		}

		else if (choice == 5)

		{

			// нонакорди за зростанням діапазону.
			cout << "\nНонакроди за зростанням діапазону від заданої ноти" << endl;
			myFile << "\nНонакроди за зростанням діапазону від заданої ноти" << endl;
			cout << "введіть основний тон (класична нотація)" << endl;
			cin >> destination; // вводиться 
			Transposed[0].step[0] = key_to_step(destination);
			Transposed[0].pitch[0] = key_to_pitch(destination);


			for (int i = 0; i < 120; i++)
			{
				int stepshift = stepdiff(Inverted[i].step[0], Transposed[0].step[0]); // зсув про ступенях
				int pitchshift = pitchdiff(Inverted[i].pitch[0], Transposed[0].pitch[0]); // зсув по півтонах

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
				}

			for (int k = 6; k < 50; k++)
				for (int j = 0; j < c; j++)

				{
					if (sum_pitchs(Transposed[j].pitch) == k)
					{
						for (int i = 0; i < 5; i++)
						{
							cout << Transposed[j].name[i] << "  \t";
							myFile << Transposed[j].name[i] << "  \t";
						}
						cout << "\tдіапазон (півтонів): " << sum_pitchs(Transposed[j].pitch) << endl;
						myFile << "\tдіапазон (півтонів): " << sum_pitchs(Transposed[j].pitch) << endl;
					}
				}

			cout << "\nусього: " << c << endl;
		}
		else
		{
			cout << "спробуйте ще раз";
			goto operation;
		}
		cout << "Спробуваи ще? 1 - так, 0 - вихід з програми";
		cin >> oncemore;

	}
	cout << longline << "Дякуємо за використання програми!" << endl;
	myFile.close();


}

