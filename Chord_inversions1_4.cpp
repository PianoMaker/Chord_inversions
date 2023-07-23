#include "Notes.h"
#include"Messages.h"
#include <string>
#define Sharp (MeanSharpness(polychords[j], numberofnotes))


 string get_chord_string(int sounds) {
	return chords_containing() + to_string(sounds) + fsounds();
}

void ExtChords(Polychord* polychords, long& modifications, int &numberofnotes, bool notation, string &header)
{
		// ручне введення основного тону
		
		string initialnote = EnterNotes(notation, enter() + root(), true);

		Message(11, enter() + upto12() );
		numberofnotes = EnterNum(12);
		header = get_chord_string(numberofnotes);

		bool test/* = 0*/;
		Message(8, "test regime ? 1 - yes, 0 - no\n");
		cin >> test;/*глючить без тест-режиму у режимі release*/

		ExtChordsCore(polychords, modifications, initialnote, notation, numberofnotes, test);

		// РЕЗУЛЬТАТИ НА ЕКРАН

	//	Show(polychords, modifications, header, true);
}