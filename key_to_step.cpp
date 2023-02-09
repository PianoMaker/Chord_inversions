// ВИЗНАЧЕННЯ СТУПЕНЮ (ВІДНОСНО ДО)
// введеної за клавіатури ноти 

#include <iostream>;
using namespace std;
enum NOTES1 { DO, RE, MI, FA, SOL, LA, SI };

int key_to_step(string key, int notation = 1)
{
	string note_as_written(key, 0, 1);
	string n_acc(key, 1, 4);

	int notes;

	if (note_as_written == "c")
	{
		notes = DO;
	}
	else if (note_as_written == "d")
	{
		notes = RE;
	}
	else if (note_as_written == "e")
	{
		notes = MI;
	}
	else if (note_as_written == "f")
	{
		notes = FA;
	}
	else if (note_as_written == "g")
	{
		notes = SOL;
	}
	else if (note_as_written == "a")
	{
		notes = LA;
	}
	else if (note_as_written == "b" && (notation) && n_acc == "is")
	{
		return -100;
	}
	else if (note_as_written == "h" && (notation) && n_acc == "es")
	{
		return -100;
	}
	else if (note_as_written == "b" && (notation))
	{
		notes = SI;
	}
	else if (note_as_written == "b")
	{
		notes = SI;
	}
	else if (note_as_written == "h")
	{
		if (notation)
		{
			notes = SI;
		}
		else
		{
			return -100;
		}
	}
	else
	{
		return -100;
	}

	return notes;
}