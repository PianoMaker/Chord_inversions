/// ВИЗНАЧЕННЯ АБСОЛЮТНОЇ ВИСОТИ ЗВУКА (У ПІВТОНАХ від рівня ДО)
#include <iostream>
#include"Messages.h"
#include "Notes.h"
using namespace std;

string Step_to_notename(int step, int alter, bool lang)
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
		notename = ndo(lang);
	}
	else if (step == RE)
	{
		notename = nre(lang);
	}
	else if (step == MI)
	{
		notename = nmi(lang);
	}
	else if (step == FA)
	{
		notename = nfa(lang);
	}
	else if (step == SOL)
	{
		notename = nsol(lang);
	}
	else if (step == LA)
	{
		notename = nla(lang);
	}
	else if (step == SI)
	{
		notename = nsi(lang);
	}

	else
	{
		return note_error(lang);
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
		return note_error(lang);
	}
	string Key_to_notename(notename + noteaccname);

	return Key_to_notename;
}