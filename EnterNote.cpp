#include"Notes.h";

string EnterNotes(int notation)
{
	string initial;
	do
	{
	cin >> initial;

	if (key_to_step(initial, notation) == -100)
	Title(12, "помилка при введенні ноти, спробуйте ще!");
	} while (key_to_step(initial, notation) == -100);

	return initial;

}