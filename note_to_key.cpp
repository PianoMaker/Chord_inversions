//Визначає латинську назву за ступенем і висотою
#include"Notes.h"


string Note_to_key(int step, int pitch)
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

	string Key_to_notename(notename + noteaccname);

	if (Key_to_notename == "hes") Key_to_notename = "b";
	if (Key_to_notename == "heses") Key_to_notename = "bes";
	if (Key_to_notename == "aes") Key_to_notename = "as";
	if (Key_to_notename == "ees") Key_to_notename = "es";

	return Key_to_notename;
}