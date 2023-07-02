#include"Notes.h";
//enum NOTES1 { DO, RE, MI, FA, SOL, LA, SI };

// ВИЗНАЧЕННЯ СТУПЕНЮ (ВІДНОСНО ДО)
// введеної за клавіатури ноти 

int Key_to_step(string key, int notation)
{
	string note_as_written(key, 0, 1);
	string n_acc(key, 1, 4);

	int notes;

	if (note_as_written == "c") notes = DO;
	else if (note_as_written == "d") notes = RE;
	else if (note_as_written == "e") notes = MI;
	else if (note_as_written == "f") notes = FA;
	else if (note_as_written == "g") notes = SOL;
	else if (note_as_written == "a") notes = LA;
	else if (note_as_written == "b" && (notation) && n_acc == "is") return -100;
	else if (note_as_written == "h" && (notation) && n_acc == "es") return -100;
	else if (note_as_written == "b" && (notation)) 	notes = SI;
	else if (note_as_written == "b") notes = SI;
	else if (note_as_written == "h")
	{
		if (notation) notes = SI;
		else return -100;
	}
	else
		return -100;

	return notes;
}

// ВИЗНАЧЕННЯ НАЗВИ НОТИ (українською)
// введеної за клавіатури ноти 

string Key_to_notename(string key, int notation)
{
	string note_as_written(key, 0, 1);
	string n_acc(key, 1, 4);
	string notename;
	string noteaccname;

	if (note_as_written == "c")	notename = "до";
	else if (note_as_written == "d") notename = "ре";
	else if (note_as_written == "e") notename = "мі";
	else if (note_as_written == "f") notename = "фа";
	else if (note_as_written == "g") notename = "соль";
	else if (note_as_written == "a") notename = "ля";
	else if ((note_as_written == "b" && (notation) && n_acc == "is") || (note_as_written == "b" && (notation) && n_acc == "isis"))
		return "Помилка при введенні ноти\n";

	else if (note_as_written == "h" && (notation) && n_acc == "es")
		return "Помилка при введенні ноти\n";

	else if (note_as_written == "b" && (notation) && n_acc == "es") notename = "сі";
	else if (note_as_written == "b" && (notation)) notename = "сі ь";
	else if (note_as_written == "b" && (!notation)) notename = "сі";
	else if (note_as_written == "h")
	{
		if (notation) notename = "сі";

		else
			return "Помилка при введенні ноти\n";
	}
	else
		return "Помилка при введенні ноти\n";


	if (n_acc == "") noteaccname = "";
	else if (n_acc == "isis" && (notation) || n_acc == "##" && (!notation) || n_acc == "x" && (!notation))
		noteaccname = " х";
	else if (n_acc == "eses" && (notation) || n_acc == "ses" && (notation) || n_acc == "bb")
		noteaccname = " ьь";
	else if (n_acc == "is" && (notation) || n_acc == "#" && (!notation))
		noteaccname = " #";
	else if (n_acc == "es" && note_as_written == "b" && (notation))
		noteaccname = " ьь";
	else if (n_acc == "es" && (notation) || n_acc == "s" && (notation) || n_acc == "b" && (!notation))
		noteaccname = " ь";
	else
		return "Помилка при введенні ноти\n";

	string Key_to_notename(notename + noteaccname);

	return Key_to_notename;
}

// ВИЗНАЧЕННЯ ЗВУКОВИСОТНОСТІ
// введеної за клавіатури ноти 

int Key_to_pitch(string key, int notation)
{
	string note_as_written(key, 0, 1);
	string n_acc(key, 1, 4);

	int notation_type = notation;
	/*cout << note_as_written << " (тест)\t";*/

	int pitch, alteration;

	if (note_as_written == "c") pitch = 0;
	else if (note_as_written == "d") pitch = 2;
	else if (note_as_written == "e") pitch = 4;
	else if (note_as_written == "f") pitch = 5;
	else if (note_as_written == "g") pitch = 7;
	else if (note_as_written == "a") pitch = 9;
	else if ((note_as_written == "b" && (notation) && n_acc == "is") || (note_as_written == "b" && (notation) && n_acc == "isis"))
		return -100;
	else if (note_as_written == "h" && (notation) && n_acc == "es")
		return -100;

	else if (note_as_written == "b" && (notation_type)) pitch = 10;
	else if (note_as_written == "b") pitch = 11;

	else if (note_as_written == "h")
	{
		if (notation_type)	pitch = 11;
		else return -100;
	}
	else return -100;


	if (n_acc == "")
		alteration = 0;
	else if (n_acc == "isis" && (notation) || n_acc == "##" && (!notation) || n_acc == "x" && (!notation))
		alteration = 2;
	else if (n_acc == "eses" && (notation) || n_acc == "ses" && (notation) || n_acc == "bb")
		alteration = -2;
	else if (n_acc == "is" && (notation) || n_acc == "#" && (!notation))
		alteration = 1;
	else if (n_acc == "es" && note_as_written == "b" && (notation))
		alteration = -1;
	else if (n_acc == "es" && (notation) || n_acc == "s" && (notation) || n_acc == "b" && (!notation))
		alteration = -1;
	else alteration = 0;
	return pitch + alteration;
}


//  ВВЕДЕННЯ З КЛАВІАТУРИ

string EnterNotes(int notation, string text)
{
	string note;
	Message(11,text);
	Message(7, Textnotation());
	do
	{
	cin >> note;

	if (Key_to_step(note, notation) == -100)
	Message(12, "помилка при введенні ноти, спробуйте ще!");
	} while (Key_to_step(note, notation) == -100);

	return note;
}