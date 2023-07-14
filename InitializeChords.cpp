#include"Notes.h"
#include"Messages.h"

//bool Lng::lng;

void InitChordManual(Polychord& initial, string &initialnote, bool notation, int numberofnotes)//ручний конструктор
{
	bool repeat = 0;
	string* key = new string[numberofnotes];
	string enteringtext = enter() + to_string(numberofnotes) + fsounds();
	do 
	{
		Message(11, enteringtext);
		Textnotation(notation);
		for (int i = 0; i < numberofnotes; i++)
			key[i] = EnterNotes(notation, sound() + to_string(i + 1) + " ");
		cin.ignore(INT_FAST16_MAX, '\n');  // Очистити зайві символи

		initialnote = key[0];
		for (int i = 0; i < numberofnotes; i++)
		{
			initial.key[i] = key[i]; // назва ноти, string
			initial.step[i] = Key_to_step(key[i], notation);  // ступінь від "до", int
			initial.pitch[i] = Key_to_pitch(key[i], notation); // висота в півтонах від "до", int
			initial.name[i] = Key_to_notename(key[i], notation); // назва ноти, string
		}
		for (int i = 0; i < numberofnotes - 1; i++)
			if (Stepdiff(initial.step[i], initial.step[i + 1]) != 2)
			{
				Message(12, noentered() + ChordName(numberofnotes) + anyway());
				repeat = EnterBool(try_or_more());
				break;
			}
			else repeat = 1;
	} while (!repeat);
	initialnote = key[0];
	
	delete[] key;
}

void InitNote(string& initialnote, int choice, bool notation)
{
	string enteringtext;
	if (choice == 6) enteringtext = enter() +  melody();
	else enteringtext = enter() + root();
	;
	
	initialnote = EnterNotes(notation, enteringtext);
}

void InitChordAuto(Polychord& initial, string initialnote, bool notation, int numberofnotes)//напівавтоматичний конструктор
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


void Preconstruct(Polychord& initial, int index, int add)
{
	initial.pitch[index] = addpitch(initial.pitch[0], add);
}

void Construct7(Polychord& initial, int model, bool notation)
{
	switch (model)
	{
	case 1://в.маж.
		Preconstruct(initial, 1, 4);
		Preconstruct(initial, 2, 7);
		Preconstruct(initial, 3, 11);
		break;

	case 2://м. маж.
		Preconstruct(initial, 1, 4);
		Preconstruct(initial, 2, 7);
		Preconstruct(initial, 3, 10);
		break;
	case 3://в. мін.
		Preconstruct(initial, 1, 3);
		Preconstruct(initial, 2, 7);
		Preconstruct(initial, 3, 11);
		break;

	case 4://м. мін. 
		Preconstruct(initial, 1, 3);
		Preconstruct(initial, 2, 7);
		Preconstruct(initial, 3, 10);
		break;
	case 5://м. зм.
		Preconstruct(initial, 1, 3);
		Preconstruct(initial, 2, 6);
		Preconstruct(initial, 3, 10);
		break;
	}

	for (int i = 0; i < 4; i++)
		initial.key[i] = Note_to_key(initial.step[i], initial.pitch[i], notation);
}


void Construct9(Polychord& initial, int model, bool notation)
{
	switch (model)
	{
	case 1:// маж.
		Preconstruct(initial, 1, 4);
		Preconstruct(initial, 3, 11);
		break;

	case 2:// дом.
		Preconstruct(initial, 1, 4);
		Preconstruct(initial, 3, 10);
		break;
	case 3:// мін.
		Preconstruct(initial, 1, 3);
		Preconstruct(initial, 3, 10);
		break;

	case 4:// 6/9
		Preconstruct(initial, 1, 4);
		initial.step[3] = addpitch(initial.step[2], 1);
		Preconstruct(initial, 3, 9);
		break;
	case 5:// зм.
		Preconstruct(initial, 1, 3);
		Preconstruct(initial, 2, 6);
		Preconstruct(initial, 3, 10);
		Preconstruct(initial, 4, 13);
		break;
	}

	for (int i = 0; i < 5; i++)
	{
		initial.key[i] = Note_to_key(initial.step[i], initial.pitch[i], notation);
	}

}

void Construct11(Polychord& initial, int model, bool notation)//конструювання акорду за інтервалами
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
		Preconstruct(initial, 1, 4);
		initial.step[3] = addpitch(initial.step[2], 1);
		initial.pitch[3] = addpitch(initial.pitch[0], 9);
		initial.pitch[5] = addpitch(initial.pitch[0], 18);
		break;
	}
	case 5:
	{
		Preconstruct(initial, 1, 4);
		Preconstruct(initial, 2, 8);
		Preconstruct(initial, 3, 11);
		Preconstruct(initial, 4, 15);
		Preconstruct(initial, 5, 18);
		break;
	}
	}
	for (int i = 0; i < 6; i++)
	{

		initial.key[i] = Note_to_key(initial.step[i], initial.pitch[i], notation);
	}
}

string ChordName(int numberofnotes)
{
	switch (numberofnotes)
	{
	case 4: return c7th();
	case 5: return c9th();
	case 6: return c11th();
	case 7: return c13th();
	defalult: return "";
	}
}

int Model(int numberofnotes)// вибір інтервальної структури акорда 
{
	Color(11);
	cout << chord_choose() << ChordName(numberofnotes) << chord_structure();
	Color(7);
	if (numberofnotes == 6)cout << chord_structure1() << endl;
	else if (numberofnotes == 5)cout << chord_structure2() << endl;
	else if (numberofnotes == 4)cout << chord_structure3() << endl;
	int model = EnterNum(5);
	return model;
}


string VoiceName(int numberofnotes)
{
	switch (numberofnotes)
	{
	case 4: return i7th();
	case 5: return c9th();
	case 6: return c11th();
	case 7: return c13th();
	defalult: return "";
	}
}

// виводить на екран вихіний акорд (initial)
void AnalyzeEnteredChord(Polychord &initial, int numberofnotes, bool notation)
{
	system("cls");
	cout << chord_entered();
	for (int i = 0; i < numberofnotes; i++)
	{
		initial.name[i] = Key_to_notename(initial.key[i], notation);
		cout << initial.name[i];
			if (i < numberofnotes - 1) cout << " - ";
	}
	cout << endl;
}

void MultiAnalyze(Polychord* inverted, int numberofnotes, bool notation, int numberofcombinations)
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
	header = c_all() + ChordName(numberofnotes) + c_chords();
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
	// нонакорди з ноною нагорі.
	int d = 0, e = 0;

	header = ChordName(numberofnotes) + c_chordsw() + VoiceName(numberofnotes) + in_melody();
	for (int j = 0; j < numberofcombinations; j++)
	{
		if (ifmode)
		{

			if (Stepdiff(initial.step[0], inverted[j].step[numberofnotes - 1]) == (numberofnotes * 2 - 2)%7)// !!
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

void Chords11v3(Polychord initial, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode)
{
	int d = 0, e = 0;

	header = c_chordsw() + VoiceName(numberofnotes) + between();
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
	header = ChordName(numberofnotes) + increase_range();

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

void Chords11v5(string initialnote, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode, bool notation)

{
	Polychord* transposed = new Polychord[numberofcombinations];
	string destination = initialnote;
	int numberofintervals = numberofnotes - 1;
	// нонакорди за зростанням діапазону.
	header = ChordName(numberofnotes) + increase_range_root();

	transposed[0].step[0] = Key_to_step(destination, notation);
	transposed[0].pitch[0] = Key_to_pitch(destination, notation);


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
			transposed[i].key[j] = Note_to_key(transposed[i].step[j], transposed[i].pitch[j], notation); // генерування key
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

void Chords11v6(string initialnote, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode, bool notation)
{

	// нонакорди за зростанням діапазону.
	header = ChordName(numberofnotes) + increase_range();
	Polychord* transposed = new Polychord[numberofcombinations];
	string destination = initialnote; // вводиться 
	int numberofintervals = numberofnotes - 1;
	transposed[0].step[numberofnotes-1] = Key_to_step(destination, notation);
	transposed[0].pitch[numberofnotes - 1] = Key_to_pitch(destination, notation);



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
			transposed[j].key[i] = Note_to_key(transposed[j].step[i], transposed[j].pitch[i], notation); // генерування key
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