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
