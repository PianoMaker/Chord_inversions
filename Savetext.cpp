#include"Notes.h";

void SaveText(Polychord *polychord, int modifications, int numberofnotes)
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