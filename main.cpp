#include"Notes.h"
#include"Messages.h"
#define CLS system("cls"); greeting(); clef();


void Chord_inversions1_3(Polychord* polychords, long& modifications, int numberofnotes, bool notation, bool lang);
void Chord_inversions1_4(Polychord* polychords, long& modifications, int& numberofnotes, bool notation, bool lang);
void Extchordstats(Polychord* polychords, long& modifications, int& numberofnotes, bool notation, bool lang);


int main()
{
	CLS;
	int N, numberofnotes;
	long modifications;
	bool lang = ChooseLanguage();//обираємо мову
	CLS;
	bool notation = ChooseNotation(lang);//обираємо вид нотації
	CLS;
	int choice = Menu(numberofnotes, lang);//головне меню
	bool oncemore = false;

	N = PermutationCounter(numberofnotes);
	Polychord*polychord = new Polychord[N];

	switch (choice)
	{
	case 1:/*септакороди*/
	case 2:/*нонакорди*/
	case 3:/*ундецимакорди*/ Chord_inversions1_3(&*polychord, modifications, numberofnotes, notation, lang); break;
	case 4:	/*політерцієві*/ Chord_inversions1_4(&*polychord, modifications, numberofnotes, notation, lang); break;
	case 5: /*статистика*/   Extchordstats(&*polychord, modifications, numberofnotes, notation, lang); break;
	default: cout << "\nincorrect choice";  break;
	};
	// ПІСЛЯ КОНСТРУЮВАННЯ СПИСКУ АКОРДІВ
	if (choice < 5)
	{
		do
		{
			int action = Postmenu(lang);// меню
			NoteRanger(polychord, modifications, numberofnotes);
			bool savetext;

			switch (action)
			{
			case 1: /*звук*/Beeper(polychord, modifications, numberofnotes); 
				savetext = EnterBool(ifsave(lang)); if(!savetext) break;
			case 2: /*txt*/SaveText(polychord, modifications, numberofnotes, lang); break;
			case 3: /*xml*/ cout << "\nmodul is under construction";// -створення xml - зробити!!
			case 4: /*other*/if (choice < 4)Chord_inversions1_3(&*polychord, modifications, numberofnotes, notation, lang);
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

