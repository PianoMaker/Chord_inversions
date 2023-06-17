#include"Notes.h"
using std::cin;
using std::ios;
using std::fstream;
using std::setw;




void Chord_inversions1_1(Polychord* Polychords, int& modifications);
void Chord_inversions1_2(Polychord* Polychords, int& modifications);
void Chord_inversions1_3(Polychord* Polychords, int& modifications);
void Chord_inversions1_4(Polychord* Polychords, int& modifications);
void Extchordstats(Polychord* Polychords, int& modifications); 


int main()
{
	time_t now = time(0);
	cout << now;
	clef();

	int N, NoN;
	int notation = 1;
	int choice;
	int modifications;
	string longline = Longline();


	title(11, "\nОберіть програму\n");
	title(15, "1 - Нонакорди v 1.1\n2 - Нонакорди v 1.2\n3 - Ундецимакорди v 1.3 \n4 - Політерцієві із заданою кількістю звуків \n5 - статистика");
	do
	{
     cin >> choice;
	 if (choice > 5) cout << "incorrect choice, try once more\n";
	}while (choice < 1 || choice > 5);
	system("cls");

	if (choice == 1 || choice == 2)
	{
		N = 120; NoN = 5;
	}
	else
	{
		N = 840;NoN = 6;
	}
	
	Polychord*polychord = new Polychord[N];

	cout << "choice 1 passed";

	switch (choice)
	{
	case 1:
	{
		N = 120;
		Chord_inversions1_1(&*polychord, modifications); break;
	}
	case 2:
	{
		N = 120;
		Chord_inversions1_2(&*polychord, modifications); break;
	}
	case 3:
	{
		N = 840;
		Chord_inversions1_3(&*polychord, modifications); break;
	}
	case 4:
	{
		N = 120;
		Chord_inversions1_4(&*polychord, modifications); break;
	}
	case 5:
	{
		Extchordstats(&*polychord, modifications); break;
	}
	default: cout << "\nincorrect choice";  break;
	}


	int save;
	title(11, "зберегти результати в файл?\t1 - так, 0 - ні");
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
			for (int i = 0; i < NoN; i++)
			{
				print << setw(3) << polychord[j].name[i] << setw(1) << " \t"; // послідовно записуємо в файл усі акоди по одному звуку
			}
			print << setw(5) << " | " << setw(2) << sum_steps(polychord[j].step, NoN - 1) << setw(1) << " ";//підсумок - ступені
			print << setw(5) << " | " << setw(2) << sum_pitchs(polychord[j].pitch, NoN - 1) << endl;// підсумок - півтони
		}
		print.close();
		title(11, "Збережено у файлі");
		title(15, filename);
	}

	cout << longline;
	title(11, "Дякуємо за використання програми!");

}

