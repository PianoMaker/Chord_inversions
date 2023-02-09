
#include <iostream>
using std::string;

string key_to_notename(string key, int notation = 1)
{
	string note_as_written(key, 0, 1);
	string n_acc(key, 1, 4);
	string notename;
	string noteaccname;

	if (note_as_written == "c")
	{
		notename = "до";
	}
	else if (note_as_written == "d")
	{
		notename = "ре";
	}
	else if (note_as_written == "e")
	{
		notename = "мі";
	}
	else if (note_as_written == "f")
	{
		notename = "фа";
	}
	else if (note_as_written == "g")
	{
		notename = "соль";
	}
	else if (note_as_written == "a")
	{
		notename = "ля";
	}
	else if ((note_as_written == "b" && (notation) && n_acc == "is") || (note_as_written == "b" && (notation) && n_acc == "isis"))
		return "Помилка при введенні ноти\n";

	else if (note_as_written == "h" && (notation) && n_acc == "es")
		return "Помилка при введенні ноти\n";

	else if (note_as_written == "b" && (notation) && n_acc == "es")
		notename = "сі";

	else if (note_as_written == "b" && (notation))
	{
		notename = "сі ь";
	}
	else if (note_as_written == "b" && (!notation))
	{
		notename = "сі";
	}
	else if (note_as_written == "h")
	{
		if (notation)
		{
			notename = "сі";
		}
		else
		{
			return "Помилка при введенні ноти\n";
		}
	}
	else
	{
		return "Помилка при введенні ноти\n";
	}

	if (n_acc == "")
		noteaccname = "";
	else if (n_acc == "isis" && (notation) || n_acc == "##" && (!notation) || n_acc == "x" && (!notation))
	{
		noteaccname = " х";
	}
	else if (n_acc == "eses" && (notation) || n_acc == "ses" && (notation) || n_acc == "bb")
	{
		noteaccname = " ьь";
	}
	else if (n_acc == "is" && (notation) || n_acc == "#" && (!notation))
	{
		noteaccname = " #";
	}
	else if (n_acc == "es" && note_as_written == "b" && (notation))
	{
		noteaccname = " ьь";
	}
	else if (n_acc == "es" && (notation) || n_acc == "s" && (notation) || n_acc == "b" && (!notation))
	{
		noteaccname = " ь";
	}

	else
	{
		return "Помилка при введенні ноти\n";
	}

	string key_to_notename(notename + noteaccname);

	return key_to_notename;
}

/// ВИЗНАЧЕННЯ АБСОЛЮТНОЇ ВИСОТИ ЗВУКА (У ПІВТОНАХ від рівня ДО)