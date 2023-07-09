#include "Notes.h"

bool ChooseNotation()
{
	Message(11, "\nОберіть нотацію");
	Message(7, "\n1 - класична європейська нотація\n2 - американська нотація");
	return EnterBool("");
	
}


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
	if (numberofnotes>4) cout << "\n1 - Вивести усі " << ChordName(numberofnotes) << "акорди в порядку обернень" <<
		"\n2 - Вивести лише " << ChordName(numberofnotes) << "акорди з " << ChordName(numberofnotes) <<"ою у мелодичному положенні" <<
		"\n3 - вивести лише " << ChordName(numberofnotes) << "акорди з інтервалом " << ChordName(numberofnotes) << "и між крайніми голосами" <<
		"\n4 - Вивести усі " << ChordName(numberofnotes) << "акорди в порядку зростання діапазону" <<
		"\n5 - Вивести " << ChordName(numberofnotes) << "акорди та обернення від заданої ноти" <<
		"\n6 - Вивести " << ChordName(numberofnotes) << "акорди та обернення із заданим мелодичним тоном" << endl;
	else  cout << "\n1- Вивести усі " << ChordName(numberofnotes) << "акорди в порядку обернень" <<
		"\n2 - Вивести усі " << ChordName(numberofnotes) << "акорди в порядку зростання діапазону" <<
		"\n3 - Вивести усі " << ChordName(numberofnotes) << "акорди та обернення від заданої ноти" <<
		"\n4 - Вивести " << ChordName(numberofnotes) << "акорди та обернення із заданим мелодичним тоном" << endl;

	int choice;
	if (numberofnotes > 4) choice = EnterNum(6);
	else choice = EnterNum(4);
	return choice;

}

int Postmenu()
{
	int choice;
	Message(11, "\nОберіть дію\n");
	Message(15, "1 - Зіграти акорди\n2 - Зберегти як текст\n3 - Зберегти як xml)\n4 - спробувати інший акорд\n0 - завершення роботи");
	choice = EnterNum(4);
	system("cls");
	return choice;
}

