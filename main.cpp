#include"Notes.h"
#include"Messages.h"

#define CLS system("cls"); greeting(); clef();
#define REPEAT oncemore = true; break;

// МОДЕЛІ ПРОГРАМИ
void Chord_inversions1_3(Polychord* polychords, long& modifications, int numberofnotes, bool notation, string &header);
void ExtChords(Polychord* polychords, long& modifications, int& numberofnotes, bool notation, string& header);
void ExtChordStats(Polychord* polychords, long& modifications, int& numberofnotes, bool notation);
extern bool lng = false;


int main()
{
	SetConsoleOutputCP(65001);
	CLS;
	int N, numberofnotes;
	long modifications;
	lng = ChooseLanguage();//обираємо мову
	CLS;
	bool notation = ChooseNotation;//обираємо вид нотації
	CLS;
	int choice = Menu(numberofnotes);//головне меню
	bool oncemore = false;
	string header;
	bool diff;
	N = PermutationCounter(numberofnotes);
	Polychord*polychord = new Polychord[N];
	for (int i = 0; i < N; i++)
		NumberOfNotes(polychord[i], numberofnotes);//прописуємо значення кількість нот
	

	switch (choice)
	{
	case 1:/*септакороди*/
	case 2:/*нонакорди*/
	case 3:/*ундецимакорди*/ Chord_inversions1_3(&*polychord, modifications, numberofnotes, notation, header); diff = false;  break;
	case 4:	/*політерцієві*/ ExtChords(&*polychord, modifications, numberofnotes, notation, header); diff = true; break;
	case 5: /*статистика*/   ExtChordStats(&*polychord, modifications, numberofnotes, notation); break;
	default: cout << "\nincorrect choice";  break;
	};

	// ПІСЛЯ КОНСТРУЮВАННЯ СПИСКУ АКОРДІВ
	if (choice < 5)
	{
		do
		{
			Show(polychord, modifications, header, diff);
			int action = Postmenu();// меню
			NoteRanger(polychord, modifications, numberofnotes);
			bool savetext;

			switch (action)
			{
			case 0: Longline(); clef(); oncemore = false; break;
			case 1: /* зіграти  */Beeper(polychord, modifications, numberofnotes); REPEAT;
			case 2: /*спростити*/Simplify(polychord, modifications, notation); REPEAT;
			case 3: /* дієзи   */Sharpize(polychord, modifications, notation); REPEAT;
			case 4: /* бемолі */Flatize(polychord, modifications, notation); REPEAT;
			case 5: /*переальтерація*/Alterize(polychord, modifications, notation); REPEAT;
			case 6: /*txt*/SaveText(polychord, modifications, numberofnotes); break;
			case 7: /*xml*/ xml(polychord, numberofnotes, modifications); break;
			case 8: /*other chord*/if (choice < 3)Chord_inversions1_3(&*polychord, modifications, numberofnotes, notation, header);
				  else if (choice == 4)ExtChords(&*polychord, modifications, numberofnotes, notation, header);
				oncemore = true;
				break;
			
			default:
				Longline();
				clef();
				oncemore = false;
				break;
			}
		} while (oncemore);
	}
	else;
	Message(11, thank());

	delete[] polychord;
}

