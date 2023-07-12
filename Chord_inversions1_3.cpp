#include "Notes.h"
#include"Messages.h"

#define print (cout << setw(3) << inverted[j].name[i] << setw(2) << "\t")





void Chord_inversions1_3(Polychord* polychords, long& modifications, int numberofnotes, bool notation, bool lang)
{
	int numberofintervals = numberofnotes - 1;
	long combinations = PermutationCounter(numberofnotes);
	Polychord initial;
	Polychord* inverted = new Polychord[combinations];
	Polychord* transposed = new Polychord[combinations];
	int model, sum;
	string initialnote; // для побудови нонакорду за моделлю
	string destination; // для транспозиції
	bool oncemore = 1;


	//cout << "combinations = " << combinations;


		//ВВЕСТИ АКОРД
	string enteringtext;
	model = Model(numberofnotes, lang); // інтервальна структура акорда (0 - вручну)
	if (model == 0) InitChordManual(initial, initialnote, notation, numberofnotes, lang);// для ручного вводу
	int choice = ChooseOperation(numberofnotes, lang);// опції конструювання і сортування
	if (model != 0) InitNote(initialnote, choice, notation, lang); // ввести основний тон
	else initialnote = initial.key[0];
	int mode = Restrictions(numberofnotes, lang);// дозвіл на обернення 8+ інтервалів

	/* Конструюється вихідний акорд "initial" структури model */


	InitChordAuto(initial, initialnote, notation, numberofnotes);
	if (numberofnotes == 6)Construct11(initial, model, notation, lang);
	else if (numberofnotes == 5)Construct9(initial, model, notation, lang);
	else if (numberofnotes == 4)Construct7(initial, model, notation, lang);
	

	// ВИХІДНИЙ АКОРД (initial) нотами на екран
	AnalyzeEnteredChord(initial, numberofnotes, notation, lang);


operation:

	//КОМБІНАТОРИКА
	int numberofcombinations;
	if (numberofnotes == 6)numberofcombinations = Combine6(initial, inverted);
	if (numberofnotes == 5)numberofcombinations = Combine5(initial, inverted);
	if (numberofnotes == 4)numberofcombinations = Combine4(initial, inverted);
	//int numberofcombinations = CombineN(initial, inverted, numberofnotes);



	// записує у структуру значення звуковисотностей
	MultiAnalyze(inverted, numberofnotes, notation, numberofcombinations, lang);

	// визначення положення інтервалів
	IntervaslAnalize(initial, inverted, numberofnotes, numberofcombinations);// встановлює позиції звуків акорду

	// СТВОРЕННЯ СПИСКІВ АКОРДІВ (ФІЛЬТРАЦІЯ або СОРТУВАННЯ за choice i mode)
	sum = 0;
	string header;
	if (numberofnotes > 4)
	{
		switch (choice)
		{
		case 1:/*усі*/All_11(inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode, lang); break;
			// ундецима в мелодії.
		case 2:Chords11v2(initial, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode, lang); break;
			// ундецима між крайніми голосами.
		case 3:Chords11v3(initial, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode, lang); break;
			// за зростанням діапазону.
		case 4:	Chords11v4(initial, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode, lang); break;
			// задана нота в басу
		case 5:	Chords11v5(initialnote, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode, notation, lang); break;
			// задана нота в мелодії
		case 6: Chords11v6(initialnote, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode, notation, lang); break;
		default: Message(12, trymore(lang));
		}
	}
	else
	{
		switch (choice)
		{
		case 1:/*усі*/All_11(inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode, lang); break;
			// ундецима в мелодії.
		case 2:	Chords11v4(initial, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode, lang); break;
			// задана нота в басу
		case 3:	Chords11v5(initialnote, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode, notation, lang); break;
			// задана нота в мелодії
		case 4: Chords11v6(initialnote, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode, notation, lang); break;
		default: Message(12, trymore(lang));
		}
	}

	float consonansrate = Consonans_rate(polychords[0].step, polychords[0].pitch, 6); // консонантність


	// РЕЗУЛЬТАТИ НА ЕКРАН

	tableheader(header, lang);

	for (int j = 0; j < sum; j++)
	{
		for (int i = 0; i < numberofnotes; i++)
		{
			cout << left << setw(3) << /*ноти*/polychords[j].name[i] << setw(1) << " \t";
		}
		cout << setw(1) << " | " << setw(2) << sum_steps(polychords[j].step, numberofintervals) << setw(1) << " ";
		cout << setw(1) << " | " << setw(2) << sum_pitchs(polychords[j].pitch, numberofintervals) << endl;
	}

	tablefooter(consonansrate, true, sum);



	modifications = sum;
}

