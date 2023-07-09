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

string Textnotation(bool notation)
{
	if (notation) return "\nДля введення нот використовуйте європейську буквенну нотацію \nс - до, \nd - ре, \ne - мі, \ng - соль, \na - ля\nb - сі - бемоль\nh - сі \nis - дiєз, \nes - бемоль  \n";
	else return "\nДля введення нот використовуйте американську буквенну нотацію \nс - до, \nd - ре, \ne - мі, \nf - фа, \ng - соль, \na - ля\nb - сі \n# - дiєз, \nb - бемоль  \n";
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