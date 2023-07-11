#include <iostream>;
#include "Notes.h";
#include"Messages.h"
#define LEFT cout << setw(10) << "" <<
using std::cout;
using std::endl;

string Longline()
{
	return
		"\n_________________\n";
}

void Line()
{
	cout << "\n____________________________________________________________________\n";
}

void Textnotation(bool notation, bool lang)
{
	if (notation)
	{
		Message(7, use_eu(lang));
		Message(8, notes_eu(lang));
	}
	else 
	{
		Message(7, use_us(lang));
		Message(8, notes_us(lang));
	}
	}

const int lline = 40;

void greeting()
{
	cout << left << setw(lline) << setfill('.') << "\n";
	Color(15);
	cout << "\nВас вітає створювач політерцієвих акордів!" << endl;
	Color(14);
	cout << endl << "   Welcome to extended chords generator!";
	Color(7);
	cout << setw(lline) << "\n" << endl;
}

void clef()
{
	Color(14);
	cout << setfill(' ') << "\n";
	LEFT "         #" << endl;
	LEFT"         ##" << endl;
	LEFT"         # #" << endl;
	LEFT"         ##" << endl;
	LEFT"        ##" << endl;
	LEFT"       # #" << endl;
	LEFT"      #  #" << endl;
	LEFT"     #   #" << endl;
	LEFT"    #    #" << endl;
	LEFT"   #   # # # *" << endl;
	LEFT"   #  *  #    #" << endl;
	LEFT"    #    #    #" << endl;
	LEFT"      #  #   # " << endl;
	LEFT"       * * *  " << endl;
	LEFT"         # " << endl;
	LEFT"      #  # " << endl;
	LEFT"       ## " << endl;
	Color(7);
}