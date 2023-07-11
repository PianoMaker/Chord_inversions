#include"Notes.h"
void tablefooter(float consonansrate, bool rate, int amount)
{
Color(14);
cout << "\nусього = ";
Color(14);
cout << amount;
if (rate)
{
	Color(11);
	cout << "\nconsonans_rate = ";
	Color(14);
	cout << consonansrate * 100 << " %" << endl;
	Color(7);
}
}