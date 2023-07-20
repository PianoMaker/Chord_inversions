// create_xml.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Notes.h"
#include "Messages.h"
#include <fstream>
#include <string>
#include <cctype> // для функції toupper
using namespace std;


bool Mode()
{
    Message(11, choose_model());
    return EnterBool(chordmode());
}


string* Capitalise(std::string note[], int size) {
    string* result = new string[size]; // створюємо новий масив розміру size

    for (int i = 0; i < size; i++) {
        string str = note[i]; // копіюємо поточний елемент масиву note у змінну str

        // перетворюємо всі маленькі літери на великі
        for (int j = 0; j < str.length(); j++) {
            str[j] = toupper(str[j]);
        }

        result[i] = str; // додаємо перетворений рядок у новий масив
    }

    return result; // повертаємо новий масив
}


void Header(ofstream& write, int size, bool mode)
{
	write << "        <time>" << '\n';
	if (mode)
		write << "         <beats>" << size << "</beats>" << '\n';
	if (!mode)
		write << "         <beats>4</beats>" << '\n';
	write << "          <beat-type>4</beat-type>" << '\n';
	write << "        </time>" << '\n';
	write << "        <clef>" << '\n';
	write << "         <sign>G</sign>" << '\n';
	write << "         <line>2</line>" << '\n';
	write << "        </clef>" << '\n';
	write << "        </attributes>" << '\n';
}

void Addtempo(ofstream& write)
{
    Message(11, entertempo());
    int tempo = EnterNum(500, 20);
  
    
	write << "     <direction placement=\"above\">\n";
	write << "       <direction-type>\n";
	write << "         <metronome parentheses=\"no\">\n";
	write << "           <beat-unit>half</beat-unit>\n";
	write << "           <per-minute>" << tempo << "</per-minute>\n";
	write << "          </metronome>\n";
	write << "        </direction-type>\n";
	write << "      <sound tempo=\"" << tempo * 2 << "\"/>\n";
	write << "    </direction>\n";
}

void Octave(Polychord &A) // переводить висоту в октаву (переробити....)
{
    for (int i = 0; i < A.numberofnotes; i++)
    {
        if (A.pitch[0] + A.pitch[A.numberofnotes - 1] < 32)A.octave[i] = A.pitch[i] / 12 + 4;
        else if (A.pitch[0] + A.pitch[A.numberofnotes - 1] < 44)A.octave[i] = A.pitch[i] / 12 + 3;
        else A.octave[i] = A.pitch[i] / 12 + 2;
    }
}


void Step_to_Capital(Polychord &A)
{
    
    
    for (int i=0; i<A.numberofnotes; i++)
    {
        switch (A.step[i]%7)
        {
        case 0: A.capitalized[i] = 'C'; break;
        case 1: A.capitalized[i] = 'D'; break;
        case 2: A.capitalized[i] = 'E'; break;
        case 3: A.capitalized[i] = 'F'; break;
        case 4: A.capitalized[i] = 'G'; break;
        case 5: A.capitalized[i] = 'A'; break;
        case 6: A.capitalized[i] = 'B'; break;
        default: A.capitalized[i] = '/0'; break;
        }
    }
}



void Note(ofstream& write, char note, int octave, bool chord, string duration, int alter = 0)
{
    write << "      <note>" << '\n';
    if (chord)write << "      <chord/>" << '\n';
    write << "        <pitch>" << '\n';
    write << "          <step>" << note << "</step>" << '\n';
    write << "          <alter>" << alter << "</alter>" << '\n';
    write << "          <octave>" << octave << "</octave>" << '\n';
    write << "        </pitch>" << '\n';
    write << "        <duration>1</duration>" << '\n';
    write << "        <voice>1</voice>" << '\n';
    write << "        <type>" << duration << "</type>" << '\n';
    if (alter == 1) write << "<accidental>sharp</accidental>" << '\n';
    write << "        </note>" << '\n';
}

void Barend(ofstream& write)
{
    write << "    </measure>" << '\n';
}

void Barstart(ofstream& write, int& barcounter)
{
    barcounter++;
    write << "<measure number = \"" << barcounter << "\">";

}

void End(ofstream& write)
{
    write << "    </part>" << '\n';
    write << "</score-partwise>" << '\n';
}


void xml(Polychord *polychord, int numberofnotes, int modifications) {

    ifstream head("xml-start.txt");// адреса шапки  
    string file = "xml-start.txt";
    if (!head) {
        cout << "Error: Failed to open input file " << file << "\n";
    }
    else {
        
        string new_filename = "archive/";
        new_filename.append(get_current_time()); // у назву файлу вписується поточний час у секундах
        new_filename.append("_output.xml");
        ofstream write(new_filename);
        if (!write) {
            cout << "Error: Failed to open output file " << new_filename << '\n';
        }
        else
        {
            cout << "writing to file " << new_filename << endl;
        }

        string line;
        while (getline(head, line)) {// копіюється довга шапка  
            write << line << '\n';
        }

        int mode = Mode();

        Header(write, numberofnotes, mode); // розмір за кількістю нот 
        int barnumber; // нумерація тактів

        string duration;
        if (mode) duration = "whole";
        else duration = "quarter";


        Addtempo(write);
        for (int j = 0; j < modifications; j++)
        {
            Step_to_Capital(polychord[j]); // форматування ноти (літера) під xml
            Octave(polychord[j]);// форматування ноти (октава) під xml
            for (int i = 0; i < numberofnotes; i++)
                polychord[j].alter[i] = alter_from_pitch(polychord[j].step[i], polychord[j].pitch[i]);

            if (j > 0)write << "   <measure number = \"" << j + 1 << "\">\n";//початок такту

            for (int i = 0; i < numberofnotes; i++)
            {
                if (i != 0 && mode) Note(write, polychord[j].capitalized[i], polychord[j].octave[i], true, duration, polychord[j].alter[i]); // запис нот, арпеджіо
                else  Note(write, polychord[j].capitalized[i], polychord[j].octave[i], false, duration, polychord[j].alter[i]); // запис нот, акордами
            }

            Barend(write); // закінчення такту
        }

        End(write);
        write.close();
    }

}
