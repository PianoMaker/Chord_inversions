#include"Notes.h"
// Визначає чи інтервал є консонансом



bool ifconsonans(int steps, int quality)
{
	bool consonans;
	if (quality == PERFECT)
		consonans = 1;//консонанс
	else if (quality > 1 || quality < -1)
		consonans = 0;// дисонанс
	else if (steps == TERZIA || steps == SEKSTA)
		if (quality == 1 || quality == -1)
			consonans = 1;
		else consonans = 0;
	else consonans = 0;
	return consonans;
}