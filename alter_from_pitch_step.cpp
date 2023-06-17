/// ВИЗНАЧЕННЯ НАЗВИ НОТИ (ЗА СТУПІННЮ І ВИСОТОЮ) 
#include "Notes.h";


int alter_from_pitch(int step, int pitch)
{

	int alter, standartpitch;

	while (step > 6)
		step -= 7;
	while (pitch > 11)
		pitch -= 12;


	if (step == DO)	standartpitch = 0;
	else if (step == RE) standartpitch = 2;
	else if (step == MI) standartpitch = 4;
	else if (step == FA) standartpitch = 5;
	else if (step == SOL) standartpitch = 7;
	else if (step == LA) standartpitch = 9;
	else if (step == SI) standartpitch = 11;

	alter = pitch - standartpitch;

	if (alter == 11 && standartpitch == 0)
		alter = -1;
	else if (alter == -10 && standartpitch == 11)
		alter = 2;
	else if (alter == 10 && standartpitch == 0)
		alter = -2; 
	else if (pitch == 11 && standartpitch == 2)
		alter = -3;

	return alter;
}