/// ВИЗНАЧЕННЯ НАЗВИ НОТИ (ЗА СТУПІННЮ І ВИСОТОЮ) 
#include <iostream>
#include "Notes.h"



string Pitch_to_notename(int step, int pitch)
{
	string notename;
	string noteaccname;
	int alter, standartpitch;

	while (step > 6)
		step -= 7;
	while (pitch > 11)
		pitch -= 12;

	//cout << "test1 step =" << step << "\n";
	if (step == -1)
	{
		notename = "--";
	}

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
		alter = -1; noteaccname = " ь";
	}
	else if (alter == 10 && standartpitch == 0)
	{
		alter = -2; noteaccname = " ьь";
	}
	else if (alter == 9 && standartpitch == 0)
	{
		alter = -3; noteaccname = " ььь";
	}
	else if (pitch == 11 && standartpitch == 1)
	{
		alter = -3; noteaccname = " ььь";
	}
	else if (pitch == 0 && standartpitch == 11)
	{
		alter = 1; noteaccname = " #";
	}
	else if (pitch == 1 && standartpitch == 11)
	{
		alter = 2; noteaccname = " x";
	}
	else if (pitch == 2 && standartpitch == 11)
	{
		alter = 3; noteaccname = " x#";
	}
	else if (alter == 2)
	{
		noteaccname = " х";
	}
	else if (alter == 3)
	{
		noteaccname = " х#";
	}
	else if (alter == 4)
	{
		noteaccname = " хх";
	}
	else if (alter == -2)
	{
		noteaccname = " ьь";
	}
	else if (alter == -3)
	{
		noteaccname = " ььь";
	}
	else if (alter == -4)
	{
		noteaccname = " ьььь";
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

	string Key_to_notename(notename + noteaccname);

	return Key_to_notename;
}