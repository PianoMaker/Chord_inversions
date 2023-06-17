#include"Notes.h"
bool Oncemore()
{
	int oncemore;
	color(7);
	cout << "\nСпробувати інші акорди? 1 - так, 0 - завершення роботи\n";
		cin >> oncemore;
		if (oncemore) return true;
		else return false;
}