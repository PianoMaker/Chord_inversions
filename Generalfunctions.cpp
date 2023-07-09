#include"Notes.h"
#include <windows.h>

void Color(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);

}

void Message(int c, string title)
{

	Color(c);
	cout << title << endl;
     Color(7);
}

int EnterNum(int max)
{
	int initialnote;
	do
	{
		cin >> initialnote;

		if (initialnote > max)
			Message(12, "завелике число, спробуйте ще!");
	} while (initialnote > max);

	return initialnote;
}


bool EnterBool(string text) // захист від випадково невірно введенних символів для змінної bool
{
	char choice[3];
	cout << text;
	while (true)
	{
		if (cin.rdbuf()->in_avail() > 0) { cin.clear(); cin.ignore(INT_MAX, '\n'); }
		cin.getline(choice, 3);
		if (strcmp(choice, "1") == 0) return true;
		else if (strcmp(choice, "2") == 0) return false;
		else cout << "try once more!1 or 2!\n";
	}
}
