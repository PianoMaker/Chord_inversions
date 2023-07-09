/// ВПЛИВ ЗНАКІВ АЛЬТЕРАЦІЇ НА ВИСОТУ ЗВУКА

#include <iostream>;
using namespace std;
enum NOTES5 { DO, RE, MI, FA, SOL, LA, SI };

int pitchchange(string n_acc, string note_as_written, bool notation = 1)  // "notation" означає тип нотації - європейський 
{
	int pitchalteration;
	if (n_acc == "")
		pitchalteration = 0;
	else if (n_acc == "isis" && (notation) || n_acc == "##" && (!notation) || n_acc == "x" && (!notation))
	{
		pitchalteration = 2;
	}
	else if (n_acc == "is" && (notation) || n_acc == "#" && (!notation))
	{
		pitchalteration = 1;
	}
	else if (n_acc == "es" && note_as_written == "b" && (notation))
	{
		pitchalteration = -1;
	}
	else if (n_acc == "eses" && (notation) || n_acc == "ses" && (notation) || n_acc == "bb" && (!notation))
	{
		pitchalteration = -2;
	}
	else if (n_acc == "es" && (notation) || n_acc == "s" && (notation) || n_acc == "b" && (!notation))
	{
		pitchalteration = -1;
	}
	else
	{
		return -100;
	}
	return pitchalteration;
}