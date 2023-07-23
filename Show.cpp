#include"Notes.h"
#define Sharp (MeanSharpness(polychords[j]))
void Show(Polychord* polychords, long sum, string header, bool diff)
{
	tableheader(header);
	float consonansrate = Consonans_rate(polychords[0].step, polychords[0].pitch, polychords[0].numberofnotes); // консонантність

	for (int j = 0; j < sum; j++)
	{
		for (int i = 0; i < polychords[j].numberofnotes; i++)
		{
			cout << left << setw(5) << /*ноти*/polychords[j].name[i] << /*setw(1) << */"\t";
		}
		cout << setw(1) << " \t| " << right << setw(3) << sum_steps(polychords[j].step, polychords[j].numberofnotes - 1) << setw(1) << " ";
		cout << setw(1) << " | " << right << setw(3) << sum_pitchs(polychords[j].pitch, polychords[j].numberofnotes - 1) << " ";
		if (Sharp > 0) 	cout << setw(1) << " | " << setw(2) << "+" << Sharp;
		else 			cout << setw(1) << " | " << setw(2) << Sharp;
		if (diff)
		{
			cout << " | " << setw(4) << round(Consonans_rate(polychords[j].step, polychords[j].pitch, polychords[j].numberofnotes) * 100) << " % "; // консонантність
		}
		cout << endl;
	}
	Line();
	if (diff)tablefooter(0, false, sum);
	else tablefooter(consonansrate, true, sum);
}