#include <iostream>;
#include <string>;
#include <fstream>
#include <iomanip>
#include <vector>
#define ifmode (!(mode > 0 && inverted[j].nona - inverted[j].prima < 2) && !(mode > 0 && inverted[j].undecima - inverted[j].prima < 3) && !(mode > 0 && inverted[j].undecima - inverted[j].terzia < 2))


using std::cout;
using std::cin;
using std::string;
using std::fstream;
using std::endl;
using std::setw;
using std::ios;

#ifndef NOTECOUNTER
#define NOTECOUNTER


enum NOTENAMES { DO, RE, MI, FA, SOL, LA, SI };
enum QALITY { PERFECT = 0, MAJ = 1, MIN = -1, AUG = 2, DIM = -2, AUG2 = 3, DIM2 = -3 };
enum INTERVALS { PRIMA, SECUNDA, TERZIA, QUARTA, QUINTA, SEKSTA, SEPTYMA, OCTAVA };
enum IFMAJOR {dur = true, moll = false};

/// МАЛЮНОЧОК
void clef();

struct Polychord
{
	string key[12]; // назва латинкою
	string name[12]; // назва кирилицею
	int step[12]; // ступінь від до=0
	int pitch[12]; // півтони від до=0
	string position[12]; // позиція в акорді
	int consonanse_rate;// консонантність
	int prima;//позиції інтервалів
	int terzia;
	int quinta;
	int septyma;
	int nona;
	int undecima;
	int terzdecima;
};

int addstep(int step1, int step2);

int addpitch(int pitch1, int pitch2);

void allsum(int c);

int alter_from_pitch(int step, int pitch);

int alteration_counter(string key, int notation);

void All_11(Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode);

void AnalyzeEnteredChord(Polychord initial, int numberofnotes);

void Chords11v2(Polychord initial, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode);

void Chords11v3(Polychord initial, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode);

void Chords11v4(Polychord initial, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode);

void Chords11v5(string initialnote, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode);

void Chords11v6(string initialnote, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode);


int ChooseOperation();

void Color(int color);

//int Combine(Polychord* A, Polychord initialnote, int numberofnotes);

int Combine5(Polychord initial, Polychord* inverted);

int Combine6(Polychord initial, Polychord* inverted);

int CombineN(Polychord initial, Polychord* inverted, int numberofnotes);

long long CombinationsCounter(int numberofnotes, int sounds); // параметр за замовчуванням для інтервалів

float Consonans_rate(int* step, int* pitch, int numberofnotes);

void Construct11(Polychord& initial, int model);

void Construct9(Polychord& initial, int model);

int CountCombinations(int numberofnotes);


string EnterNotes(int notation, string text); // введення ноти з відсіюванням невірних символів

int EnterNum(int max); // введення числа не більше заданого

long long Factorial_counter(int amount);

string get_current_time();

//void generateArrays(int n, int k, vector<vector<int>>& res, vector<int> currArray, int lastElement);

//Polychord Initial9(string initialnote, int notation);
//
//Polychord Initial11(string initialnote, int notation);
//
//void InitChord(Polychord& initial, int notation, int numberofnotes, int model);

int Int_quality(int steps, int halftones); // якість інтервалу

//int If_note_in_Chord(int* step, int interval, int numberofnotes); // визначає позицію заданого інтервалу в акорді

bool Ifconsonans(int steps, int quality);

void InitChordManual(Polychord& initial, string& initialnote, int notation, int numberofnotes);//конструктор акорду

void InitNote(string& initialnote, int model, int notation); // введення основної ноти

void InitChordAuto(Polychord& initial, string initialnote, int notation, int numberofnotes); // конструктор акорду

void IntervaslAnalize(Polychord initial, Polychord* inverted, int numberofnotes, int numberofcombinations); // встановлює положення складових акорду

int Key_to_step(string key, int notation = 1); // ВИЗНАЧЕННЯ СТУПЕНЮ (ВІДНОСНО ДО) за латинським позначеням 

int Key_to_pitch(string key, int notation = 1); // Визначення висоти (в півтонах) за латинським позначеням

string Key_to_notename(string key, int notation = 1); /// ВИЗНАЧЕННЯ НАЗВИ НОТИ (СЛОВАМИ)

void Line();

string Longline();

float MeanSharpness(Polychord chord, int sounds); // визначає середнє положення на квінтовому колі

int Mode();

int Model(int numberofnotes);

void MultiAnalyze(Polychord* inverted, int numberofnotes, int notation, int numberofcombinations);



bool Oncemore();

string Textnotation();

Polychord numberofnoteschord_from_keys(string key[], int notation);

string get_chord_string(int sounds);
 
string Note_to_key(int step, int pitch); // Трансформує значення ступеню і висоти в латинське написання 

string Pitch_to_notename(int step, int pitch); /// ВИЗНАЧЕННЯ НАЗВИ НОТИ (ЗА СТУПІННЮ І ВИСОТОЮ) 

string Step_to_notename(int step, int alter); /// ВИЗНАЧЕННЯ АБСОЛЮТНОЇ ВИСОТИ ЗВУКА (У ПІВТОНАХ від рівня ДО)

int pitchchange(string n_acc, string note_as_written, int notation = 1); /// допоміжний для визначення назви ноти

bool PitchFilter(int* pitch, int sounds); // фільтрує акорди з октавами



/* Підрахунок інтервалів між нотами.
Виходимо з того, що кожен наступний голос вищий за попередній,
тому за потреби додаємо до вищого голосу октаву: 7 ступенів або 12 півтонів
*/

int Pitchdiff(int low_pitch, int high_pitch);

Polychord* Polychord_Add(Polychord* polychord, int modifications, int& counter, int& sound, int sounds, bool test);

float Sharpness(int enterstep, int alter); // вводиться step, alter 

int Stepdiff(int low_note, int high_note);

int step_to_pitch(int step, int alteration);  /// ВИЗНАЧЕННЯ НАЗВИ НОТИ (ЗА ЛАТИСНКЬИМ ПОЗНАЧЕННЯМ) 

int sum_steps(int step[], int numberofintervals);

int sum_pitchs(int pitch[], int numberofintervals);

void Message(int c, string title);

void tableheader(string header);

void tablefooter(float consonansrate, bool rate, int amount);

int Quality_of_a_step(int position, int* steps, int* halftones, int inversion = 0);

#endif
