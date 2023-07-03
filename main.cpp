#include"Notes.h"
using std::cin;
using std::ios;
using std::fstream;
using std::setw;


void Chord_inversions1_3(Polychord* polychords, int& modifications, int numberofnotes);
void Chord_inversions1_4(Polychord* polychords, int& modifications);
void Extchordstats(Polychord* polychords, int& modifications); 


int main()
{
	time_t now = time(0);
	cout << now;
	clef();

	int N, numberofnotes, modifications;
	int notation = 1;
	int choice = Menu(numberofnotes);

	N = PermutationCounter(numberofnotes);
	Polychord*polychord = new Polychord[N];

	switch (choice)
	{
	case 1:
	case 2:
	case 3: Chord_inversions1_3(&*polychord, modifications, numberofnotes); break;
	case 4:	Chord_inversions1_4(&*polychord, modifications); break;
	case 5: Extchordstats(&*polychord, modifications); break;
	default: cout << "\nincorrect choice";  break;
	};
	

	int save;
	Message(11, "зберегти результати в файл?\t1 - так, 0 - ні");
	cin >> save;
	if (save)
	{
		fstream print;
		string filename = get_current_time(); // у назву файлу вписується поточний час у секундах
		filename.append("_chords.txt");
		print.open(filename, ios::out);
		print << "Акорди отримано:\n";
		print << "\t\t\tЗвуки\t\t| діапазон\n \t\t\t\t\t|ступенів | півтонів\n";
		for (int j = 0; j < modifications; j++)
		{
			for (int i = 0; i < numberofnotes; i++)
			{
				print << setw(3) << polychord[j].name[i] << setw(1) << " \t"; // послідовно записуємо в файл усі акоди по одному звуку
			}
			print << setw(5) << " | " << setw(2) << sum_steps(polychord[j].step, numberofnotes - 1) << setw(1) << " ";//підсумок - ступені
			print << setw(5) << " | " << setw(2) << sum_pitchs(polychord[j].pitch, numberofnotes - 1) << endl;// підсумок - півтони
		}
		print.close();
		Message(11, "Збережено у файлі");
		Message(15, filename);
	}

	Longline();
	Message(11, "Дякуємо за використання програми!");

}

