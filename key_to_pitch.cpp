/// ВИЗНАЧЕННЯ НАЗВИ НОТИ (ЗА ЛАТИСНКЬИМ ПОЗНАЧЕННЯМ) #include <iostream>;
#include <iostream>;
using namespace std;
enum NOTES4 { DO, RE, MI, FA, SOL, LA, SI };

int key_to_pitch(string key, int notation = 1)
{
	string note_as_written(key, 0, 1);
	string n_acc(key, 1, 4);

	int notation_type = notation;
	/*cout << note_as_written << " (тест)\t";*/

	int pitch, alteration;

	if (note_as_written == "c")
	{
		pitch = 0;
	}
	else if (note_as_written == "d")
	{
		pitch = 2;
	}
	else if (note_as_written == "e")
	{
		pitch = 4;
	}
	else if (note_as_written == "f")
	{
		pitch = 5;
	}
	else if (note_as_written == "g")
	{
		pitch = 7;
	}
	else if (note_as_written == "a")
	{
		pitch = 9;

	}
	else if ((note_as_written == "b" && (notation) && n_acc == "is") || (note_as_written == "b" && (notation) && n_acc == "isis"))

		return -100;

	else if (note_as_written == "h" && (notation) && n_acc == "es")

		return -100;

	else if (note_as_written == "b" && (notation_type))
	{
		pitch = 10;
	}
	else if (note_as_written == "b")
	{
		pitch = 11;
	}
	else if (note_as_written == "h")
	{
		if (notation_type)
		{
			pitch = 11;
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

	if (n_acc == "")
		alteration = 0;
	else if (n_acc == "isis" && (notation) || n_acc == "##" && (!notation) || n_acc == "x" && (!notation))
	{
		alteration = 2;
	}
	else if (n_acc == "eses" && (notation) || n_acc == "ses" && (notation) || n_acc == "bb")
	{
		alteration = -2;
	}
	else if (n_acc == "is" && (notation) || n_acc == "#" && (!notation))
	{
		alteration = 1;
	}
	else if (n_acc == "es" && note_as_written == "b" && (notation))
	{
		alteration = -1;
	}
	else if (n_acc == "es" && (notation) || n_acc == "s" && (notation) || n_acc == "b" && (!notation))
	{
		alteration = -1;
	}
	else alteration = 0;

	return pitch + alteration;
}