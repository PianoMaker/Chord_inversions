/// ВИЗНАЧЕННЯ АБСОЛЮТНОЇ ВИСОТИ ЗВУКА (У ПІВТОНАХ від рівня ДО)

enum NOTES2 { DO, RE, MI, FA, SOL, LA, SI };
#include <iostream>;
using namespace std;

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