#include"Notes.h"
bool Oncemore()
{
	int oncemore;
	Color(7);
	cout << "\nСпробувати інший акорд? 1 - так, 0 - продовжити роботу з цим акордом\n";
		cin >> oncemore;
		if (oncemore) return true;
		else return false;
}