#include"Notes.h"
using std::cin;
using std::ios;
using std::fstream;
using std::setw;


void Chord_inversions1_3(Polychord* polychords, long& modifications, int numberofnotes);
void Chord_inversions1_4(Polychord* polychords, long& modifications, int& numberofnotes);
void Extchordstats(Polychord* polychords, long& modifications, int& numberofnotes);


int main()
{
	time_t now = time(0);
	cout << now;
	greeting();
	clef();

	int N, numberofnotes;
	long modifications;
	int notation = 1;
	int choice = Menu(numberofnotes);
	bool oncemore = false;

	N = PermutationCounter(numberofnotes);
	Polychord*polychord = new Polychord[N];

	switch (choice)
	{
	case 1:
	case 2:
	case 3: Chord_inversions1_3(&*polychord, modifications, numberofnotes); break;
	case 4:	Chord_inversions1_4(&*polychord, modifications, numberofnotes); break;
	case 5: Extchordstats(&*polychord, modifications, numberofnotes); break;
	default: cout << "\nincorrect choice";  break;
	};
	if (choice < 5)
	{
		do
		{
			int action = Postmenu();
			NoteRanger(polychord, modifications, numberofnotes);

			switch (action)
			{
			case 1: Beeper(polychord, modifications, numberofnotes); break;
			case 2: SaveText(polychord, modifications, numberofnotes); break;
			case 4: if (choice < 3)Chord_inversions1_3(&*polychord, modifications, numberofnotes);
				  else if (choice == 4)Chord_inversions1_4(&*polychord, modifications, numberofnotes);
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
	Message(11, "Дякуємо за використання програми!");

	delete[] polychord;
}

