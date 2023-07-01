#include "Notes.h"

int Mode()
{
			Title(11, "\n\nОберіть модель");
		cout << "Шукати усі обернення та розташування - 0" << endl;
		cout << "Шукати лише розташування, в яких 9-, 11- і 13- тони";
		Color(6);
		cout << " вищі ";
		Color(7);
		cout << "за основний тон щонайменш на нону - 1\n";

		int mode;
		cin >> mode;
		return mode;
}