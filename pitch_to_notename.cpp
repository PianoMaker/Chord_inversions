/// ВИЗНАЧЕННЯ НАЗВИ НОТИ (ЗА СТУПІННЮ І ВИСОТОЮ) 
#include <iostream>;
using namespace std;
enum NOTES3 { DO, RE, MI, FA, SOL, LA, SI };

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
		alter = -1; noteaccname = " ь";
	}
	else if (pitch == 0 && standartpitch == 11)
	{
		alter = 1; noteaccname = " #";
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