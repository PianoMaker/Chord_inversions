#include "Notes.h"

long long combination_counter(int NoN, int sounds = 2) // параметр за замовчуванням для інтервалів
{
	if (NoN < sounds)
		return 0;
	long long diff, combinations;
	diff = NoN - sounds;
	combinations = factorial_counter(NoN) / (factorial_counter(sounds) * factorial_counter(diff));
	return combinations;
}

float Consonans_rate(int* step, int* pitch, int NoN)
{

	long multiN = combination_counter(NoN);
	int NoI = NoN - 1;

	int* allhalftones = new int[multiN]; // усі можливі інтервали мід голосами у півтонах (октава = 12)
	int* allsteps = new int[multiN]; // усі можливі інтервали мід голосами у ступінях (секунда = 1, терція = 2 і т.д.)
	int* allqualities = new int[multiN]; // якості інтервалів (чисті, малі, великі і т.д.)
	int n_steps = 0;

	for (int i = 0;i < NoN;i++)
		for (int k = i + 1;k < NoN;k++)
		{
			allsteps[n_steps] = stepdiff(step[i], step[k]); // усі можливі інтервали мід голосами
			n_steps++;
		}

	int n_htones = 0;

	for (int i = 0;i < NoN; i++)
		for (int k = i + 1;k < NoN;k++)
		{
			allhalftones[n_htones] = pitchdiff(pitch[i], pitch[k]); // півтонів між голосами
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
		ifc[i] = ifconsonans(allsteps[i], allqualities[i]); // якості інтервалів між голосами
		
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