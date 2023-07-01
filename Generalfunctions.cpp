#include"Notes.h"
#include <windows.h>

void Color(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);

}

void Title(int c, string title)
{

	Color(c);
	cout << title << endl;
     Color(7);
}

int EnterNum(int max)
{
	int initial;
	do
	{
		cin >> initial;

		if (initial > max)
			Title(12, "завелике число, спробуйте ще!");
	} while (initial > max);

	return initial;

}
