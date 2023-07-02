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

string Textnotation()
{
	return "Для введення нот використовуйте європейську буквенну нотацію \nс - до, \nd - ре, \ne - мі, \nf - фа, \ng - соль, \na - ля\nb - сі - бемоль\nh - сі \nis - дiєз, \nes - бемоль  \n";
}

void clef()
{
	Color(7);
	cout << endl << "+++++++++++++++++++" << endl << "Вас вітає Розв’язувач акордів" << endl << "+++++++++++++++++++\n_________________\n";
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