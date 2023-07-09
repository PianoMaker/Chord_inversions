#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#define ifmode (!(mode > 0 && inverted[j].nona - inverted[j].prima < 2) && !(mode > 0 && numberofnotes > 5 && inverted[j].undecima - inverted[j].prima < 3) && !(mode > 0 && numberofnotes > 5 && inverted[j].undecima - inverted[j].terzia < 2))
int const A4 = 440; // камертон (стандарт = 440)
int const playspeed = 300; // тривалість звуку (реком.300)
int const fermata = 100; // пауза між рядками (реком.100)

using std::cout;
using std::cin;
using std::string;
using std::fstream;
using std::endl;
using std::to_string;
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
void greeting();

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

int alteration_counter(string key, bool notation);

void All_11(Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode);

void AnalyzeEnteredChord(Polychord& initial, int numberofnotes);

// озвучення акордів
void Beeper(Polychord* polychord, long modifications, int numberofnotes); 

// конструктори акордів за інтервальною структурою
void Chords11v2(Polychord initial, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode);
void Chords11v3(Polychord initial, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode);
void Chords11v4(Polychord initial, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode);
void Chords11v5(string initialnote, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode, bool notation);
void Chords11v6(string initialnote, Polychord* inverted, Polychord* polychords, int& sum, string& header, int numberofcombinations, int numberofnotes, int mode, bool notation);

int ChooseOperation(int numberofnotes);// вибір моделі конструювання акорду
bool ChooseNotation(); // вибір системи нотації
void Color(int color);

//int Combine(Polychord* A, Polychord initialnote, int numberofnotes);

int Combine4(Polychord initial, Polychord* inverted);
int Combine5(Polychord initial, Polychord* inverted);
int Combine6(Polychord initial, Polychord* inverted);
int CombineN(const Polychord& initial, Polychord* inverted, int nn);

string ChordName(int numberofnotes);

long CombinationsCounter(int numberofnotes, int sounds); // параметр за замовчуванням для інтервалів

float Consonans_rate(int* step, int* pitch, int numberofnotes);

void Construct11(Polychord& initial, int model, bool notation);
void Construct9(Polychord& initial, int model, bool notation);
void Construct7(Polychord& initial, int model, bool notation);
long CombinationsCounter(int numberofnotes, int sounds = 2);


string EnterNotes(bool notation, string text, string comment = " "); // введення ноти з відсіюванням невірних символів

int EnterNum(int max); // введення числа не більше заданого

long long Factorial_counter(int amount);

string get_current_time();

//void InitChord(Polychord& initial, bool notation, int numberofnotes, int model);

int Int_quality(int steps, int halftones); // якість інтервалу

//int If_note_in_Chord(int* step, int interval, int numberofnotes); // визначає позицію заданого інтервалу в акорді

bool Ifconsonans(int steps, int quality);

void InitChordManual(Polychord& initial, string& initialnote, bool notation, int numberofnotes);//конструктор акорду

void InitNote(string& initialnote, int model, bool notation); // введення основної ноти

void InitChordAuto(Polychord& initial, string initialnote, bool notation, int numberofnotes); // конструктор акорду

void IntervaslAnalize(Polychord initial, Polychord* inverted, int numberofnotes, int numberofcombinations); // встановлює положення складових акорду

int Key_to_step(string key, bool notation = 1); // ВИЗНАЧЕННЯ СТУПЕНЮ (ВІДНОСНО ДО) за латинським позначеням 

int Key_to_pitch(string key, bool notation = 1); // Визначення висоти (в півтонах) за латинським позначеням

string Key_to_notename(string key, bool notation = 1); /// ВИЗНАЧЕННЯ НАЗВИ НОТИ (СЛОВАМИ)

void Line();

string Longline();

int Menu(int& numberofnotes);// головне меню

float MeanSharpness(Polychord chord, int sounds); // визначає середнє положення на квінтовому колі

int Restrictions(int numberofnotes); // вибір обмежень

int Model(int numberofnotes); // вибір виду акордів

void MultiAnalyze(Polychord* inverted, int numberofnotes, bool notation, int numberofcombinations);

void NoteRanger(Polychord* polychord, long modifications, int numberofnotes);

bool Oncemore();

long PermutationCounter(int numberofnotes);// рахує кількість перестановок

int Postmenu(); // постменю


void SaveText(Polychord *polychord, long modifications, int numberofnotes);

string Textnotation(bool notation);

Polychord numberofnoteschord_from_keys(string key[], bool notation);

string get_chord_string(int sounds);
 
string Note_to_key(int step, int pitch, bool notation); // Трансформує значення ступеню і висоти в латинське написання 

string Pitch_to_notename(int step, int pitch); /// ВИЗНАЧЕННЯ НАЗВИ НОТИ (ЗА СТУПІННЮ І ВИСОТОЮ) 

string Step_to_notename(int step, int alter); /// ВИЗНАЧЕННЯ АБСОЛЮТНОЇ ВИСОТИ ЗВУКА (У ПІВТОНАХ від рівня ДО)

int pitchchange(string n_acc, string note_as_written, bool notation = 1); /// допоміжний для визначення назви ноти

bool PitchFilter(int* pitch, int sounds); // фільтрує акорди з октавами



/* Підрахунок інтервалів між нотами.
Виходимо з того, що кожен наступний голос вищий за попередній,
тому за потреби додаємо до вищого голосу октаву: 7 ступенів або 12 півтонів
*/

int Pitchdiff(int low_pitch, int high_pitch);

Polychord* Polychord_Add(Polychord* polychord, long modifications, int& counter, int& sound, int numberofnotes, bool test);

float Sharpness(int enterstep, int alter); // вводиться step, alter 

int Stepdiff(int low_note, int high_note);

int step_to_pitch(int step, int alteration);  /// ВИЗНАЧЕННЯ НАЗВИ НОТИ (ЗА ЛАТИСНКЬИМ ПОЗНАЧЕННЯМ) 

int sum_steps(int step[], int numberofintervals);

int sum_pitchs(int pitch[], int numberofintervals);

void Message(int c, string title);

void tableheader(string header);

void tablefooter(float consonansrate, bool rate, int amount);

bool EnterBool(string text);

int Quality_of_a_step(int position, int* steps, int* halftones, int inversion = 0);

#endif
