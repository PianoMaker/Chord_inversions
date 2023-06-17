#include "Notes.h"
int alteration_counter(string key, int notation) // нота текстом, система нотації

{
	string note_as_written(key, 0, 1);
	string n_acc(key, 1, 4);
	int alteration;
	int notation_type = notation;
	if (note_as_written == "b" && notation) alteration = -1;
	else alteration = pitchchange(n_acc, note_as_written, notation_type);
	return alteration;
}