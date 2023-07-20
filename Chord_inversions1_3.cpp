#include "Notes.h"
#include"Messages.h"

#define print (cout << setw(3) << inverted[j].name[i] << setw(2) << "\t")



void Chord_inversions1_3(Polychord* polychords, long& modifications, int numberofnotes, bool notation, string &header)
{
	int numberofintervals = numberofnotes - 1;
	long combinations = PermutationCounter(numberofnotes);
	Polychord initial;
	NumberOfNotes(initial, numberofnotes);
	string initialnote; // для побудови нонакорду за моделлю
	bool oncemore = 1;


	//cout << "combinations = " << combinations;


		//ВВЕСТИ АКОРД

	int model = Model(numberofnotes); // інтервальна структура акорда (0 - вручну)
	if (model == 0) InitChordManual(initial, initialnote, notation);// для ручного вводу
	int choice = ChooseOperation(numberofnotes);// опції конструювання і сортування
	if (model != 0) InitNote(initialnote, choice, notation); // ввести основний тон
	else initialnote = InitNote(initial, notation); // для руного режиму
	/* Конструюється вихідний акорд "initial" структури model (автоматичний режим) */

	if (model != 0)
	{
		InitChordAuto(initial, initialnote, notation, numberofnotes);
		if (numberofnotes == 6)Construct11(initial, model, notation);
		else if (numberofnotes == 5)Construct9(initial, model, notation);
		else if (numberofnotes == 4)Construct7(initial, model, notation);
	}

	int mode = Restrictions(numberofnotes);// дозвіл на обернення 8+ інтервалів
	
	int clockstart = clock();
	// ВИХІДНИЙ АКОРД (initial) нотами на екран
	AnalyzeEnteredChord(initial, notation);


operation:
	
	//КОМБІНАТОРИКА
	Polychord* inverted = new Polychord[combinations];
	NumberOfNotes(inverted, numberofnotes, combinations);
	if (numberofnotes == 6)Combine6(initial, inverted);
	if (numberofnotes == 5)Combine5(initial, inverted);
	if (numberofnotes == 4)Combine4(initial, inverted);
	//int numberofcombinations = CombineN(initial, inverted, numberofnotes);

	// записує у структуру значення звуковисотностей
	MultiAnalyze(inverted, notation, combinations);

	// визначення положення інтервалів
	IntervaslAnalize(initial, inverted, combinations);// встановлює позиції звуків акорду

	// СТВОРЕННЯ СПИСКІВ АКОРДІВ (ФІЛЬТРАЦІЯ або СОРТУВАННЯ за choice i mode)
	int sum = 0; // остаточна кількість модифікацій (з урахуванням фільтрів)
	if (numberofnotes > 4)
	{
		switch (choice)
		{
		case 1:/*усі*/All_11(inverted, polychords, sum, header, combinations, numberofnotes, mode); break;
			// ундецима в мелодії.
		case 2:Chords11v2(initial, inverted, polychords, sum, header, combinations, mode); break;
			// ундецима між крайніми голосами.
		case 3:Chords11v3(inverted, polychords, sum, header, combinations, numberofnotes, mode); break;
			// за зростанням діапазону.
		case 4:	Chords11v4(inverted, polychords, sum, header, combinations, numberofnotes, mode); break;
			// задана нота в басу
		case 5:	Chords11v5(initialnote, inverted, polychords, sum, header, combinations, numberofnotes, mode, notation); break;
			// задана нота в мелодії
		case 6: Chords11v6(initialnote, inverted, polychords, sum, header, combinations, numberofnotes, mode, notation); break;
		default: Message(12, trymore());
		}
	}
	else
	{
		switch (choice)
		{
		case 1:/*усі*/All_11(inverted, polychords, sum, header, combinations, numberofnotes, mode); break;
			// ундецима в мелодії.
		case 2:	Chords11v4(inverted, polychords, sum, header, combinations, numberofnotes, mode); break;
			// задана нота в басу
		case 3:	Chords11v5(initialnote, inverted, polychords, sum, header, combinations, numberofnotes, mode, notation); break;
			// задана нота в мелодії
		case 4: Chords11v6(initialnote, inverted, polychords, sum, header, combinations, numberofnotes, mode, notation); break;
		default: Message(12, trymore());
		}
	}

	float consonansrate = Consonans_rate(polychords[0].step, polychords[0].pitch, numberofnotes); // консонантність
	int clockend = clock();

	// РЕЗУЛЬТАТИ НА ЕКРАН

	Show(polychords, sum, header, false);

	cout << "\ntime elapsed: " << clockend - clockstart << " ms";



	modifications = sum;
}

