#include "Notes.h"
#include "Messages.h"
#define CHORD ChordName(numberofnotes) << c_chords() <<

bool ChooseLanguage()
{
	Message(10, "\n1 - Українська");
	Message(10, "\t\t2 - English\n");
	return EnterBool("");
}


bool ChooseNotation()
{
	Message(11, choose_notation());
	Message(7, notationtypes());
	return EnterBool("");
}

int Menu(int &numberofnotes)
{
	int choice;
	Message(11, choose_program());
	Message(15, choose_chords());
	do
	{
		cin >> choice;

		if (choice < 1 || choice > 5) Message(12, btw1and5());
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
		Message(11, choose_model());
		Message(7, all_voicings());
		Message(7, sp_voicings());
		Message(6, above());
		Message(7, aboveroot());

		int mode = EnterNum(1);
		return mode;
	}
}

int ChooseOperation(int numberofnotes)
{
	Message(11, choose_action());
	if (numberofnotes > 4) 
		/*усі*/       cout << "\n1 - " << display_all() << CHORD inversions_order() <<
		/*інтервал в мелодії*/"\n2 - " << display_only() << CHORD with_interval() << ChordName(numberofnotes) << in_melody() <<
		/*інтервал між */     "\n3 - " << display_only() << CHORD with_interval() << ChordName(numberofnotes) << between() <<
		/*сорт. по діапазону*/"\n4 - " << display_all() << CHORD range_order() <<
		/*задано бас */       "\n5 - " << display() << CHORD inversions_root() <<
		/*задано мелодію*/    "\n6 - " << display() << CHORD inversions_melody() << endl;
	else  cout << "\n1- " << display_all() << CHORD inversions_order() <<
		"\n2 - " << display_all() << CHORD range_order() <<
		"\n3 - " << display_all() << CHORD inversions_root() <<
		"\n4 - " << display() << CHORD inversions_melody() << endl;

	int choice;
	
	if (numberofnotes > 4) choice = EnterNum(6);
	else choice = EnterNum(4);
	return choice;

}

int Postmenu()
{
	int choice;
	Message(11, choose_action());
	Message(15, final_action());
	choice = EnterNum(5);
	system("cls");
	return choice;
}

