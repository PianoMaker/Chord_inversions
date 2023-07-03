#include "Notes.h"
#define print (cout << setw(3) << inverted[j].name[i] << setw(2) << "\t")


string Note_to_key(int step, int pitch);


void Chord_inversions1_3(Polychord* polychords, int& modifications, int numberofnotes)
{
	int numberofintervals = numberofnotes - 1;
	long combinations = PermutationCounter(numberofnotes);
	cout << "combinations = " << combinations;
	Polychord initial;
	Polychord *inverted = new Polychord[combinations];
	Polychord *transposed = new Polychord[combinations];
	int model, sum;
	string initialnote; // для побудови нонакорду за моделлю
	string destination; // для транспозиції
	bool notation = 1; //змінна для переключення європейської та американської нотації (поки що не розроблено)
	bool oncemore = 1;

	
	//cout << "combinations = " << combinations;

	while (oncemore)
	{
		//ВВЕСТИ АКОРД
		string enteringtext;
		model = Model(numberofnotes); // вибір вид акорду
		int mode = Restrictions(numberofnotes);// обираємо модель конструювання обернень (9-акорд і вище)
		int choice = ChooseOperation(numberofnotes);// модель конструювання
		if (model==0) InitChordManual(initial, initialnote, notation, numberofnotes);
		else
		{
			InitNote(initialnote, choice, notation);
			InitChordAuto(initial, initialnote, notation, numberofnotes);
			if(numberofnotes == 6)Construct11(initial, model);
			else if(numberofnotes == 5)Construct9(initial, model);
			else if (numberofnotes == 4)Construct7(initial, model);
		}

		// АНАЛІЗ

		AnalyzeEnteredChord(initial, numberofnotes);


	operation:

		//КОМБІНАТОРИКА
		int numberofcombinations;
		//int c = Combine6(initial, inverted);// заповнює масив inverted поля key комбінаціями звуків
		if (numberofnotes == 6)numberofcombinations = Combine6(initial, inverted);
		if (numberofnotes == 5)numberofcombinations = Combine5(initial, inverted);
		if (numberofnotes == 4)numberofcombinations = Combine4(initial, inverted);
		//int numberofcombinations = CombineN(initial, inverted, numberofnotes);
		cout << "combinations = " << combinations;


		// записує у структуру значення звуковисотностей
		MultiAnalyze(inverted, numberofnotes, notation, numberofcombinations); 
		
		// визначення положення інтервалів
		IntervaslAnalize(initial, inverted, numberofnotes, numberofcombinations);// встановлює позиції звуків акорду

		// СТВОРЕННЯ СПИСКІВ АКОРДІВ
		sum = 0;
		string header;
		if (numberofnotes>4)
		{
			switch (choice)
			{
			case 1:/*усі*/All_11(inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode); break;
				// ундецима в мелодії.
			case 2:Chords11v2(initial, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode); break;
				// ундецима між крайніми голосами.
			case 3:Chords11v3(initial, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode); break;
				// за зростанням діапазону.
			case 4:	Chords11v4(initial, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode); break;
				// задана нота в басу
			case 5:	Chords11v5(initialnote, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode); break;
				// задана нота в мелодії
			case 6: Chords11v6(initialnote, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode); break;
			default: Message(12, "спробуйте ще раз");
			}
		}
		else
		{
			switch (choice)
			{
			case 1:/*усі*/All_11(inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode); break;
				// ундецима в мелодії.
			case 2:	Chords11v4(initial, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode); break;
				// задана нота в басу
			case 3:	Chords11v5(initialnote, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode); break;
				// задана нота в мелодії
			case 4: Chords11v6(initialnote, inverted, polychords, sum, header, numberofcombinations, numberofnotes, mode); break;
			default: Message(12, "спробуйте ще раз");
			}
		}

		float consonansrate = Consonans_rate(polychords[0].step, polychords[0].pitch, 6); // консонантність
		

		// РЕЗУЛЬТАТИ НА ЕКРАН

		tableheader(header);

		for (int j = 0; j < sum; j++)
		{
			for (int i = 0; i < numberofnotes; i++)
			{
				cout << setw(3) << polychords[j].name[i] << setw(1) << " \t";
			}
			cout << setw(1) << " | " << setw(2) << sum_steps(polychords[j].step, numberofintervals) << setw(1) << " ";
			cout << setw(1) << " | " << setw(2) << sum_pitchs(polychords[j].pitch, numberofintervals) << endl;
		}

		tablefooter(consonansrate, true, sum);

		oncemore = Oncemore();
	}

	modifications = sum;
}

