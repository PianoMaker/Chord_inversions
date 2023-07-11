#include <iostream>;
#include "Notes.h";
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
		Message(7, "\nДля введення нот використовуйте європейську буквенну нотацію:");
		Message(8, "\nс - до, \td - ре, \te - мі, \nf - фа, \tg - соль, \ta - ля, \nb - сі - бемоль\th - сі \nis - дiєз, \tes - бемоль  \n");
	}
	else 
	{
		Message(7, "\nДля введення нот використовуйте американську буквенну нотацію:");
		Message(8, "\nс - до, \td - ре, \te - мі, \nf - фа, \tg - соль, \ta - ля, \nb - сі \t#   - дiєз, \tb - бемоль  \n");
	}
	}

void greeting()
{
	Color(7);
	cout << endl << "+++++++++++++++++++" << endl << "Вас вітає Розв’язувач акордів" << endl << "+++++++++++++++++++\n_________________\n";
}


void clef()
{
	
	Color(14);
	cout << "         #" << endl;
	cout << "         ##" << endl;
	cout << "         # #" << endl;
	cout << "         ##" << endl;
	cout << "        ##" << endl;
	cout << "       # #" << endl;
	cout << "      #  #" << endl;
	cout << "     #   #" << endl;
	cout << "    #    #" << endl;
	cout << "   #   # # # *" << endl;
	cout << "   #  *  #    #" << endl;
	cout << "    #    #    #" << endl;
	cout << "      #  #   # " << endl;
	cout << "       * * *  " << endl;
	cout << "         # " << endl;
	cout << "      #  # " << endl;
	cout << "       ## " << endl;
	Color(7);
}