#include"Notes.h"
#include <windows.h>


double Diffpitch(int pitch, int octavecorrector)
{
	double diffpitch;
	diffpitch = pitch - 9 + 12 * octavecorrector;
	return diffpitch;
}


int Pitch(double diffpitch)
{
	return A4 * pow(2, diffpitch/12);
}

void Play(double pitch, int oct, bool count)
{
	
	if(!count)Beep(Pitch(Diffpitch(pitch, oct)), playspeed+30);//const 
	else Beep(Pitch(Diffpitch(pitch, oct)), playspeed);
}

void Beeper(Polychord* polychord, long modifications, int numberofnotes)
{
	bool count; // перемикач для подовженої першої ноти
	int oct = 0;//  октавна поправка для широких акордів

	for (int i = 0; i < modifications; i++)
	{
		if (polychord[i].pitch[numberofnotes - 1] < 25) oct = 0;
		else if (polychord[i].pitch[numberofnotes - 1] < 37) oct = -1;
		else if (polychord[i].pitch[0] > 5 || polychord[i].pitch[numberofnotes - 1] > 50) oct = -2;
		else oct = -1;
		for (int j = 0; j < numberofnotes; j++)
		{
			cout << polychord[i].name[j] << "  ";
			if (j == 0) count = false;
			else count = true;
			Play(polychord[i].pitch[j], oct, count);
		}
		Sleep(fermata * numberofnotes + 70);
		cout << endl;
	}
}