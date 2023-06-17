#include"Notes.h"
void tablefooter(float consonansrate, bool rate, int amount)
{
color(14);
cout << "\nусього = ";
color(14);
cout << amount;
if (rate)
{
	color(11);
	cout << "\nconsonans_rate = ";
	color(14);
	cout << consonansrate * 100 << " %" << endl;
	color(7);
}
}