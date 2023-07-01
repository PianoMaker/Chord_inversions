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