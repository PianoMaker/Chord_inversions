#include"Notes.h"
#include"Messages.h"
#define CLS system("cls"); greeting(); clef();
using std::cin;
using std::ios;
using std::fstream;
using std::setw;

void Chord_inversions1_3(Polychord* polychords, long& modifications, int numberofnotes, bool notation, bool lang);
void Chord_inversions1_4(Polychord* polychords, long& modifications, int& numberofnotes, bool notation, bool lang);
void Extchordstats(Polychord* polychords, long& modifications, int& numberofnotes, bool notation, bool lang);


int main()
{
	CLS;
	int N, numberofnotes;
	long modifications;
	bool lang = ChooseLanguage();
	CLS;
	bool notation = ChooseNotation(lang);
	CLS;
	int choice = Menu(numberofnotes, lang);
	bool oncemore = false;

	N = PermutationCounter(numberofnotes);
	Polychord*polychord = new Polychord[N];

	switch (choice)
	{
	case 1:
	case 2:
	case 3: Chord_inversions1_3(&*polychord, modifications, numberofnotes, notation, lang); break;
	case 4:	Chord_inversions1_4(&*polychord, modifications, numberofnotes, notation, lang); break;
	case 5: Extchordstats(&*polychord, modifications, numberofnotes, notation, lang); break;
	default: cout << "\nincorrect choice";  break;
	};
	if (choice < 5)
	{
		do
		{
			int action = Postmenu(lang);
			NoteRanger(polychord, modifications, numberofnotes);

			switch (action)
			{
			case 1: Beeper(polychord, modifications, numberofnotes); break;
			case 2: SaveText(polychord, modifications, numberofnotes, lang); break;
			case 4: if (choice < 3)Chord_inversions1_3(&*polychord, modifications, numberofnotes, notation, lang);
				  else if (choice == 4)Chord_inversions1_4(&*polychord, modifications, numberofnotes, notation, lang);
				oncemore = true;
				break;
			default:
				Longline();
				clef();
				oncemore = false;
			}
		} while (oncemore);
	}
	else;
	Message(11, thank(lang));

	delete[] polychord;
}

