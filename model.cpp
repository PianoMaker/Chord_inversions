#include "Notes.h"
int Menu(int &numberofnotes)
{
	int choice;
	Message(11, "\nОберіть програму\n");
	Message(15, "1 - Септакорди\n2 - Нонакорди\n3 - Ундецимакорди \n4 - Політерцієві із заданою кількістю звуків \n5 - статистика");
	do
	{
		cin >> choice;

		if (choice < 1 || choice > 5) Message(12, "Оберіть від 1 до 5\n");
	} while (choice < 1 || choice > 5);
	system("cls");

	switch (choice)
	{
	case 1:numberofnotes = 4; break;
	case 2:numberofnotes = 5; break;
	case 3:numberofnotes = 6; break;
	default:numberofnotes = 7; break;
	}
	return choice;
}

int Restrictions(int numberofnotes)
{
	if (numberofnotes < 5) return 0;
	else
	{
		Message(11, "\n\nОберіть модель");
		cout << "Шукати усі обернення та розташування - 0" << endl;
		cout << "Шукати лише розташування, в яких 9-, 11- і 13- тони";
		Color(6);
		cout << " вищі ";
		Color(7);
		cout << "за основний тон щонайменш на нону - 1\n";

		int mode = EnterNum(1);
		return mode;
	}
}

int ChooseOperation(int numberofnotes)
{
	Message(11, "\nОберіть операцію");
	if (numberofnotes>4) cout << "\nВивести усі акорди в порядку обернень - 1\nВивести лише нонакорди з ноною у мелодичному положенні -2\nвивести лише акорди з інтервалом ундецими між крайніми голосами -3\nВивести усі акорди в порядку зростання діапазону - 4\nВивести нонакорди та обернення від заданої ноти - 5\nВивести нонакорди та обернення із заданим мелодичним тоном - 6 " << endl;
	else  cout << "\nВивести усі акорди в порядку обернень - 1\n3 - Вивести усі акорди в порядку зростання діапазону - 2\nВивести усі акорди та обернення від заданої ноти - 3\nВивести нонакорди та обернення із заданим мелодичним тоном - 4 " << endl;

	int choice;
	if (numberofnotes > 4) choice = EnterNum(6);
	else choice = EnterNum(4);
	return choice;

}