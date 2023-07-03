#include "Notes.h"

long long Factorial_counter(int amount)
{
	long long factorial = 1.0;

	if (amount < 0)
		cout << "Error! Factorial of a negative number doesn't exist.";
	else {
		for (int i = 1; i <= amount; ++i) {
			factorial *= i;
		}
	}
	//cout << factorial << endl;
	return factorial;
}

bool Ifconsonans(int steps, int quality)
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

long PermutationCounter(int numberofnotes)
{
	int combinations = 1;
	for (int i = 0; i < numberofnotes; i++)
	{
		combinations *= (numberofnotes - i);
	}

	return combinations;
}


long long CombinationsCounter(int numberofnotes, int sounds = 2) // параметр за замовчуванням для інтервалів
{
	if (numberofnotes < sounds)
		return 0;
	long long diff, combinations;
	diff = numberofnotes - sounds;
	combinations = Factorial_counter(numberofnotes) / (Factorial_counter(sounds) * Factorial_counter(diff));
	return combinations;
}

float Consonans_rate(int* step, int* pitch, int numberofnotes)
{

	long multiN = PermutationCounter(numberofnotes);
	int numberofintervals = numberofnotes - 1;

	int* allhalftones = new int[multiN]; // усі можливі інтервали мід голосами у півтонах (октава = 12)
	int* allsteps = new int[multiN]; // усі можливі інтервали мід голосами у ступінях (секунда = 1, терція = 2 і т.д.)
	int* allqualities = new int[multiN]; // якості інтервалів (чисті, малі, великі і т.д.)
	int n_steps = 0;

	for (int i = 0;i < numberofnotes;i++)
		for (int k = i + 1;k < numberofnotes;k++)
		{
			allsteps[n_steps] = Stepdiff(step[i], step[k]); // усі можливі інтервали мід голосами
			n_steps++;
		}

	int n_htones = 0;

	for (int i = 0;i < numberofnotes; i++)
		for (int k = i + 1;k < numberofnotes;k++)
		{
			allhalftones[n_htones] = Pitchdiff(pitch[i], pitch[k]); // півтонів між голосами
			n_htones++;
		}

	for (int nq = 0;nq < multiN; nq++)
	{
		allqualities[nq] = Int_quality(allsteps[nq], allhalftones[nq]); // якості інтервалів між голосами

	}

	//allconsonans:
	float* ifc = new float[multiN];
	for (int i = 0; i < multiN; i++)
	{
		ifc[i] = Ifconsonans(allsteps[i], allqualities[i]); // якості інтервалів між голосами
		
	}

	//consonans_rate:
	float consonans_rate, sum_ifc = 0;


	for (int i = 0; i < multiN; i++)
	{
		sum_ifc += ifc[i];
	}

	consonans_rate = sum_ifc / multiN;
	
	return consonans_rate;

}