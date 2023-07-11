#include"Notes.h";
#include"Messages.h"

void SaveText(Polychord *polychord, long modifications, int numberofnotes, bool lang)
{
		fstream print;
		string filename = get_current_time(); // у назву файлу вписується поточний час у секундах
		filename.append("_chords.txt");
		print.open(filename, ios::out);
		print << chords_achieved(lang);
		print << tonetable(lang);
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
		Message(11, save_as(lang));
		Message(15, filename);

}