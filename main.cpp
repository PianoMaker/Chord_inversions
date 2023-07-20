#include"Notes.h"
#include"Messages.h"

#define CLS system("cls"); greeting(); clef();

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
			int action = Postmenu();// меню
			NoteRanger(polychord, modifications, numberofnotes);
			bool savetext;

			switch (action)
			{
			case 1: /*звук*/Beeper(polychord, modifications, numberofnotes); 
				savetext = EnterBool(ifsave()); if(!savetext) break;
			case 2: /*simplify*/Simplify(polychord, modifications, notation); Show(polychord, modifications, header, diff); break;
			case 3: /*txt*/SaveText(polychord, modifications, numberofnotes); break;
			case 4: /*xml*/ xml(polychord, numberofnotes, modifications); break;
			case 5: /*other*/if (choice < 3)Chord_inversions1_3(&*polychord, modifications, numberofnotes, notation, header);
				  else if (choice == 4)ExtChords(&*polychord, modifications, numberofnotes, notation, header);
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
	Message(11, thank());

	delete[] polychord;
}

