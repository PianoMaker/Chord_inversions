#include"Notes.h"

void InitChordManual(Polychord& initial, string &initialnote, int notation, int numberofnotes)//ручний конструктор
{
	bool repeat = 0;
	string* key = new string[numberofnotes];
	string enteringtext = "Введіть " + std::to_string(numberofnotes) + " звуків";
	{
		for (int i = 0; i < numberofnotes; i++)
			key[i] = EnterNotes(notation, enteringtext);
		for (int i = 0; i < numberofnotes; i++)
		{
			initial.key[i] = key[i]; // назва ноти, string
			initial.step[i] = Key_to_step(key[i], notation);  // ступінь від "до", int
			initial.pitch[i] = Key_to_pitch(key[i], notation); // висота в півтонах від "до", int
			initial.name[i] = Key_to_notename(key[i], notation); // назва ноти, string
		}
		for (int i = 0; i < 4; i++)
			if (Stepdiff(initial.step[i], initial.step[i + 1]) != 2)
			{
				Message(12, "введений акорд не є ундецимакордом. Все одно продовжити? 1 - так, 0 - спробуати знову");
				cin >> repeat;
				break;
			}
			else repeat = 1;
	} while (!repeat);
	initialnote = key[0];
	delete[] key;
}

void InitNote(string& initialnote, int choice, int notation)
{
	string enteringtext;
	if (choice == 6) enteringtext = "Введіть мелодичний тон";
	else enteringtext = "Введіть основний тон";
	initialnote = EnterNotes(notation, enteringtext);
}

void InitChordAuto(Polychord& initial, string initialnote, int notation, int numberofnotes)//напівавтоматичний конструктор
{
	initial.step[0] = Key_to_step(initialnote, notation);
	initial.pitch[0] = Key_to_pitch(initialnote, notation);
	initial.step[1] = addstep(initial.step[0], 2);
	if (numberofnotes > 2)initial.step[2] = addstep(initial.step[1], 2);
	if (numberofnotes > 3)initial.step[3] = addstep(initial.step[2], 2);
	if (numberofnotes > 4)initial.step[4] = addstep(initial.step[3], 2);
	if (numberofnotes > 5)initial.step[5] = addstep(initial.step[4], 2);
	if (numberofnotes > 2)initial.pitch[2] = addpitch(initial.pitch[0], 7);
	if (numberofnotes > 4)initial.pitch[4] = addpitch(initial.pitch[0], 2);
}


/*

Polychord Initial9(string initialnote, int notation)
{
	Polychord initial;

	initial.step[0] = Key_to_step(initialnote, notation);
	initial.pitch[0] = Key_to_pitch(initialnote, notation);
	initial.step[1] = addstep(initial.step[0], 2);
	initial.step[2] = addstep(initial.step[1], 2);
	initial.step[3] = addstep(initial.step[2], 2);
	initial.step[4] = addstep(initial.step[3], 2);
	initial.pitch[2] = addpitch(initial.pitch[0], 7);
	initial.pitch[4] = addpitch(initial.pitch[0], 2);

	return initial;
}

Polychord Initial11(string initialnote, int notation)
{
	Polychord initial;

	initial.step[0] = Key_to_step(initialnote, notation);
	initial.pitch[0] = Key_to_pitch(initialnote, notation);
	initial.step[1] = addstep(initial.step[0], 2);
	initial.step[2] = addstep(initial.step[1], 2);
	initial.step[3] = addstep(initial.step[2], 2);
	initial.step[4] = addstep(initial.step[3], 2);
	initial.step[5] = addstep(initial.step[4], 2);
	initial.pitch[2] = addpitch(initial.pitch[0], 7);
	initial.pitch[4] = addpitch(initial.pitch[0], 2);

	return initial;
}

*/

void Preconstruct(Polychord& initial, int index, int add)
{
	initial.pitch[index] = addpitch(initial.pitch[0], add);
}

void Construct7(Polychord& initial, int model)
{
	switch (model)
	{
	case 1:
		Preconstruct(initial, 1, 4);
		Preconstruct(initial, 2, 7);
		Preconstruct(initial, 3, 11);
		break;

	case 2:
		Preconstruct(initial, 1, 4);
		Preconstruct(initial, 2, 7);
		Preconstruct(initial, 3, 10);
		break;
	case 3:
		Preconstruct(initial, 1, 3);
		Preconstruct(initial, 2, 7);
		Preconstruct(initial, 3, 11);
		break;

	case 4:
		Preconstruct(initial, 1, 3);
		Preconstruct(initial, 2, 7);
		Preconstruct(initial, 3, 10);
		break;
	case 5:
		Preconstruct(initial, 1, 3);
		Preconstruct(initial, 2, 6);
		Preconstruct(initial, 3, 10);
		break;
	}

	for (int i = 0; i < 4; i++)
		initial.key[i] = Note_to_key(initial.step[i], initial.pitch[i]);
}


void Construct9(Polychord& initial, int model)
{
	switch (model)
	{
	case 1:
		Preconstruct(initial, 1, 4);
		Preconstruct(initial, 3, 11);
		break;

	case 2:
		Preconstruct(initial, 1, 4);
		Preconstruct(initial, 3, 10);
		break;
	case 3:
		Preconstruct(initial, 1, 3);
		Preconstruct(initial, 3, 10);
		break;

	case 4:
		initial.pitch[1] = addpitch(initial.pitch[0], 4);
		initial.step[3] = addpitch(initial.step[2], 1);
		initial.pitch[3] = addpitch(initial.pitch[0], 9);
		break;
	case 5:
		initial.pitch[1] = addpitch(initial.pitch[0], 3);
		initial.pitch[2] = addpitch(initial.pitch[0], 6);
		initial.pitch[3] = addpitch(initial.pitch[0], 10);
		initial.pitch[4] = addpitch(initial.pitch[0], 13);
		break;
	}

	for (int i = 0; i < 5; i++)
	{
		initial.key[i] = Note_to_key(initial.step[i], initial.pitch[i]);
	}

}

void Construct11(Polychord& initial, int model)//конструювання інтервалів
{
	switch (model)
	{
	case 1:
	{
		Preconstruct(initial, 1, 4);
		Preconstruct(initial, 3, 11);
		Preconstruct(initial, 5, 18);
		break;
	}
	case 2:
	{
		Preconstruct(initial, 1, 4);
		Preconstruct(initial, 3, 10);
		Preconstruct(initial, 5, 17);
		break;
	}
	case 3:
	{
		Preconstruct(initial, 1, 3);
		Preconstruct(initial, 3, 10);
		Preconstruct(initial, 5, 17);
		break;
	}
	case 4:
	{
		initial.pitch[1] = addpitch(initial.pitch[0], 4);
		initial.step[3] = addpitch(initial.step[2], 1);
		initial.pitch[3] = addpitch(initial.pitch[0], 9);
		initial.pitch[5] = addpitch(initial.pitch[0], 18);
		break;
	}
	case 5:
	{
		initial.pitch[1] = addpitch(initial.pitch[0], 4);
		initial.pitch[2] = addpitch(initial.pitch[0], 8);
		initial.pitch[3] = addpitch(initial.pitch[0], 11);
		initial.pitch[4] = addpitch(initial.pitch[0], 15);
		initial.pitch[5] = addpitch(initial.pitch[0], 18);
		break;
	}
	}
	for (int i = 0; i < 6; i++)
	{

		initial.key[i] = Note_to_key(initial.step[i], initial.pitch[i]);
	}
}

string ChordName(int numberofnotes)
{
	switch (numberofnotes)
	{
	case 4: return "септ";
	case 5: return "нон";
	case 6: return "ундецим";
	case 7: return "терцдецим";
	defalult: return "";
	}
}

int Model(int numberofnotes)
{
	Color(11);
	cout << "\nоберіть вид" << ChordName(numberofnotes) << "акорда: \n";
	Color(7);
	if (numberofnotes == 6)cout << "1 - мажорний, 2 - домінантовий, 3 - мінорний, 4 - мажорний із секстою, 5 - збільшений, 0 - ввести вручну " << endl;
	else if (numberofnotes == 5)cout << "1 - мажорний, 2 - домінантовий, 3 - мінорний, 4 - мажорний із секстою, 5 - зменшений, 0 - ввести вручну " << endl;
	else if (numberofnotes == 4)cout << "1 - великий мажорний, 2 - малий мажорний, 3 - великий мінорний, 4 - малий мінорний, 5 - малий зменшений, 0 - ввести вручну " << endl;
	int model = EnterNum(5);
	return model;
}


string VoiceName(int numberofnotes)
{
	switch (numberofnotes)
	{
	case 4: return "септим";
	case 5: return "нон";
	case 6: return "ундецим";
	case 7: return "терцдецим";
	defalult: return "";
	}
}

void AnalyzeEnteredChord(Polychord &initial, int numberofnotes)
{
	system("cls");
	cout << "\nАкорд введено: ";
	for (int i = 0; i < numberofnotes; i++)
	{
		initial.name[i] = Key_to_notename(initial.key[i]);
		cout << initial.name[i] << " - ";
	}
}

void MultiAnalyze(Polychord* inverted, int numberofnotes, int notation, int numberofcombinations)
{
	for (int j = 0; j < numberofcombinations; j++)
		for (int i = 0; i < numberofnotes; i++)
		{
			inverted[j].pitch[i] = Key_to_pitch(inverted[j].key[i], notation); // висота (int)
			inverted[j].name[i] = Key_to_notename(inverted[j].key[i], notation); // назва (string)
			inverted[j].step[i] = Key_to_step(inverted[j].key[i], notation);  // ступінь від "до" (int)
		}
	;
}

void IntervaslAnalize(Polychord initial, Polychord* inverted, int numberofnotes, int numberofcombinations)
{
for (int j = 0; j < numberofcombinations; j++)
	for (int i = 0; i < numberofnotes; i++)
	{
		if (inverted[j].key[i] == initial.key[0]) inverted[j].prima = i;
		if (inverted[j].key[i] == initial.key[1]) inverted[j].terzia = i;
		if (inverted[j].key[i] == initial.key[2]) inverted[j].quinta = i;
		if (inverted[j].key[i] == initial.key[3]) inverted[j].septyma = i;
		if (inverted[j].key[i] == initial.key[4]) inverted[j].nona = i;
		if (inverted[j].key[i] == initial.key[5]) inverted[j].undecima = i;
		if (inverted[j].key[i] == initial.key[6]) inverted[j].terzdecima = i;
	}
}

void All_11(Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode)
{
	header = "Усі" + ChordName(numberofnotes) + "акорди";
	for (int j = 0; j < numberofcombinations; j++)
	{
		if (ifmode)
		{
			for (int i = 0; i < numberofnotes; i++)
				polychords[sum] = inverted[j];

			sum++;
		}
	}
}

void Chords11v2(Polychord initial, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode)
{
	// нонакорди з ноною на горі.
	int d = 0, e = 0;

	header = ChordName(numberofnotes) + "акорди з" + VoiceName(numberofnotes) + "ою в мелодичному положенні";
	for (int j = 0; j < numberofcombinations; j++)
	{
		if (ifmode)
		{

			if (Stepdiff(initial.step[0], inverted[j].step[5]) == 3)// !!
			{
				for (int i = 0; i < 6; i++)
					polychords[d] = inverted[j];
				d++;
			}
			else e++;
		}
	}
	sum = d;
}

void Chords11v3(Polychord initial, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode)
{
	int d = 0, e = 0;

	header = "з інтервалом" + VoiceName(numberofnotes) + "а між крайніми голосами";
	for (int j = 0; j < numberofcombinations; j++)
	{
		if (ifmode)
		{
			if (Stepdiff(inverted[j].step[0], inverted[j].step[5]) == 3)
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

void Chords11v4(Polychord initial, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode)
{
	header = ChordName(numberofnotes) + "акорди за зростанням діапазону";

	int numberofintervals = numberofnotes - 1;
	for (int k = 1; k < 90; k++)
		for (int j = 0; j < numberofcombinations; j++)
		{
			if (!(mode > 0 && inverted[j].undecima - inverted[j].prima < 2))
			{
				if (ifmode)
				{
					if (sum_steps(inverted[j].step, numberofintervals) == k)
					{
						for (int i = 0; i < numberofnotes; i++)
							polychords[sum] = inverted[j];
						sum++;
					}
				}
			}
		}
	allsum(sum);
}

void Chords11v5(string initialnote, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode)

{
	Polychord* transposed = new Polychord[numberofcombinations];
	string destination = initialnote;
	int numberofintervals = numberofnotes - 1;
	// нонакорди за зростанням діапазону.
	header = ChordName(numberofnotes) + "акроди за зростанням діапазону від заданої ноти";

	transposed[0].step[0] = Key_to_step(destination);
	transposed[0].pitch[0] = Key_to_pitch(destination);


	for (int i = 0; i < numberofcombinations; i++)
	{
		int stepshift = Stepdiff(inverted[i].step[0], transposed[0].step[0]); // зсув про ступенях
		int pitchshift = Pitchdiff(inverted[i].pitch[0], transposed[0].pitch[0]); // зсув по півтонах
		transposed[i].prima = inverted[i].prima;
		transposed[i].terzia = inverted[i].terzia;
		transposed[i].quinta = inverted[i].quinta;
		transposed[i].septyma = inverted[i].septyma;
		transposed[i].nona = inverted[i].nona;
		transposed[i].undecima = inverted[i].undecima;

		for (int j = 0; j < numberofnotes; j++)
		{
			transposed[i].step[j] = addstep(inverted[i].step[j], stepshift);  // транспонування
			transposed[i].pitch[j] = addpitch(inverted[i].pitch[j], pitchshift); // транспонування
			transposed[i].key[j] = Note_to_key(transposed[i].step[j], transposed[i].pitch[j]); // генерування key
		}
	}

	for (int j = 0; j < numberofcombinations; j++)
		for (int i = 0; i < numberofnotes; i++)
		{
			transposed[j].name[i] = Pitch_to_notename(transposed[j].step[i], transposed[j].pitch[i]); // генеруємо назви нот (string)
		}


	for (int k = 1; k < 90; k++)
		for (int j = 0; j < numberofcombinations; j++)
		{
			if (ifmode)
			{
				if (sum_pitchs(transposed[j].pitch, numberofintervals) == k)
				{
					for (int i = 0; i < numberofnotes; i++)
						polychords[sum] = transposed[j];
					sum++;
				}
			}
		}

	allsum(sum);
	delete[] transposed;
}

void Chords11v6(string initialnote, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode)
{

	// нонакорди за зростанням діапазону.
	header = ChordName(numberofnotes) + "акроди за зростанням діапазону із заданим мелодичним тоном";
	Polychord* transposed = new Polychord[numberofcombinations];
	string destination = initialnote; // вводиться 
	int numberofintervals = numberofnotes - 1;
	transposed[0].step[numberofnotes-1] = Key_to_step(destination);
	transposed[0].pitch[numberofnotes - 1] = Key_to_pitch(destination);



	for (int i = 0; i < numberofcombinations; i++)
	{
		int stepshift = Stepdiff(inverted[i].step[numberofnotes - 1], transposed[0].step[numberofnotes - 1]); // зсув про ступенях
		int pitchshift = Pitchdiff(inverted[i].pitch[numberofnotes - 1], transposed[0].pitch[numberofnotes - 1]); // зсув по півтонах
		transposed[i].prima = inverted[i].prima;
		transposed[i].terzia = inverted[i].terzia;
		transposed[i].quinta = inverted[i].quinta;
		transposed[i].septyma = inverted[i].septyma;
		transposed[i].nona = inverted[i].nona;

		for (int j = 0; j < numberofnotes; j++)
		{
			transposed[i].step[j] = addstep(inverted[i].step[j], stepshift);  // транспонування
			transposed[i].pitch[j] = addpitch(inverted[i].pitch[j], pitchshift); // транспонування
		}
	}

	for (int j = 0; j < numberofcombinations; j++)
		for (int i = 0; i < numberofnotes; i++)
		{
			transposed[j].name[i] = Pitch_to_notename(transposed[j].step[i], transposed[j].pitch[i]); // генеруємо назви нот (string)
			transposed[j].key[i] = Note_to_key(transposed[j].step[i], transposed[j].pitch[i]); // генерування key
		}

	for (int k = 1; k < 90; k++)
		for (int j = 0; j < numberofcombinations; j++)
		{
			if (ifmode)
			{
				if (sum_pitchs(transposed[j].pitch, numberofintervals) == k)
				{
					for (int i = 0; i < numberofnotes; i++)
						polychords[sum] = transposed[j];
					sum++;
				}
			}
		}

	allsum(sum);
	delete[] transposed;
}