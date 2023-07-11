#include "Notes.h"
#include "Messages.h"
bool Oncemore(bool lang)
{
	int oncemore;
	Color(7);
	cout << another(lang);
		cin >> oncemore;
		if (oncemore) return true;
		else return false;
}