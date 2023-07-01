#include <iostream>

int Stepdiff(int low_note, int high_note)
{
	if (low_note > high_note) high_note += 7;
	int interval = high_note - low_note;
	if (interval >= 7) interval-= 7;
	else if (interval <= -7) interval+= 7;
	return interval;
}