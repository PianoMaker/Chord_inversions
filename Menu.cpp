#include "Notes.h"
#include "Messages.h"

bool ChooseLanguage()
{
	Message(10, "\n1 - Українська");
	Message(10, "\t\t2 - English\n");
	return EnterBool("");
}


bool ChooseNotation(bool lang)
{
	Message(11, choose_notation(lang));
	Message(7, notationtypes(lang));
	return EnterBool("");
}

int Menu(int &numberofnotes, bool lang)
{
	int choice;
	Message(11, choose_program(lang));
	Message(15, choose_chords(lang));
	do
	{
		cin >> choice;

		if (choice < 1 || choice > 5) Message(12, btw1and5(lang));
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

int Restrictions(int numberofnotes, bool lang)
{
	if (numberofnotes < 5) return 0;
	else
	{
		Message(11, choose_model(lang));
		Message(7, all_voicings(lang));
		Message(7, sp_voicings(lang));
		Message(6, above(lang));
		Message(7, aboveroot(lang));

		int mode = EnterNum(1, lang);
		return mode;
	}
}

int ChooseOperation(int numberofnotes, bool lang)
{
	Message(11, choose_action(lang));
	if (numberofnotes > 4) 
		/*усі*/       cout << "\n1 - " << display_all(lang) << ChordName(numberofnotes, lang) << c_chords(lang) << inversions_order(lang) <<
		/*інтервал в мелодії*/"\n2 - " << display_only(lang) << ChordName(numberofnotes, lang) << c_chords(lang) << with_interval(lang) << ChordName(numberofnotes, lang) << in_melody(lang) <<
		/*інтервал між */     "\n3 - " << display_only(lang) << ChordName(numberofnotes, lang) << c_chords(lang) << with_interval(lang) << ChordName(numberofnotes, lang) << between(lang) <<
		/*по діапазону*/      "\n4 - " << display_all(lang) << ChordName(numberofnotes, lang) << c_chords(lang) << range_order(lang) <<
		/*нота в басу*/       "\n5 - " << display(lang) << ChordName(numberofnotes, lang) << c_chords(lang) << inversions_root(lang) <<
		/*нота в мелодії*/    "\n6 - " << display(lang) << ChordName(numberofnotes, lang) << c_chords(lang) << inversions_melody(lang) << endl;
	else  cout << "\n1- " << display_all(lang) << ChordName(numberofnotes, lang) << c_chords(lang) << inversions_order(lang) <<
		"\n2 - " << display_all(lang) << ChordName(numberofnotes, lang) << c_chords(lang) << range_order(lang) <<
		"\n3 - " << display_all(lang) << ChordName(numberofnotes, lang) << c_chords(lang) << inversions_root(lang) <<
		"\n4 - " << display(lang) << ChordName(numberofnotes, lang) << c_chords(lang) << inversions_melody(lang) << endl;

	int choice;
	
	if (numberofnotes > 4) choice = EnterNum(6, lang);
	else choice = EnterNum(4, lang);
	return choice;

}

int Postmenu(bool lang)
{
	int choice;
	Message(11, choose_action(lang));
	Message(15, final_action(lang));
	choice = EnterNum(4, lang);
	system("cls");
	return choice;
}

