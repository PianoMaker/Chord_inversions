#include"Notes.h"
using std::cin;
using std::ios;
using std::fstream;
using std::setw;


void Chord_inversions1_3(Polychord* polychords, int& modifications, int numberofnotes);
void Chord_inversions1_4(Polychord* polychords, int& modifications);
void Extchordstats(Polychord* polychords, int& modifications); 


int main()
{
	time_t now = time(0);
	cout << now;
	clef();

	int N, numberofnotes, modifications;
	int notation = 1;
	int choice = Menu(numberofnotes);

	N = PermutationCounter(numberofnotes);
	Polychord*polychord = new Polychord[N];

	switch (choice)
	{
	case 1:
	case 2:
	case 3: Chord_inversions1_3(&*polychord, modifications, numberofnotes); break;
	case 4:	Chord_inversions1_4(&*polychord, modifications); break;
	case 5: Extchordstats(&*polychord, modifications); break;
	default: cout << "\nincorrect choice";  break;
	};
	
	int action = Postmenu();
	NoteRanger(polychord, modifications, numberofnotes);
		
	switch (action)
	{
	case 1: Beeper(polychord, modifications, numberofnotes); break;
	case 2: SaveText(polychord, modifications, numberofnotes); break;
	case 4: Chord_inversions1_3(&*polychord, modifications, numberofnotes); break;
	default:
		Longline();
		Message(11, "Дякуємо за використання програми!");
	}




	delete[] polychord;
}

