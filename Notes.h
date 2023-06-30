#include <iostream>;
#include <string>;
#include <fstream>
#include <iomanip>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;

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
	int prima;
	int terzia;
	int quinta;
	int septyma;
	int nona;
	int undecima;
};

int addstep(int step1, int step2);

int addpitch(int pitch1, int pitch2);

void allsum(int c);

int alter_from_pitch(int step, int pitch);

int alteration_counter(string key, int notation);

void Color(int color);

//long long combination_counter(int NoN, int sounds = 2); // параметр за замовчуванням для інтервалів

float Consonans_rate(int* step, int* pitch, int NoN);

string EnterNotes(int notation); // введення ноти з відсіюванням невірних символів

int EnterNum(int max); // введення числа не більше заданого

long long factorial_counter(int amount);

string get_current_time();

//void generateArrays(int n, int k, vector<vector<int>>& res, vector<int> currArray, int lastElement);

int** getArray();

Polychord Initial9(string initial, int notation);

Polychord Initial11(string initial, int notation);

int Int_quality(int steps, int halftones); // якість інтервалу

int If_note_in_Chord(int* step, int interval, int NON); // визначає позицію заданого інтервалу в акорді

bool ifconsonans(int steps, int quality);

int key_to_step(string key, int notation = 1); // ВИЗНАЧЕННЯ СТУПЕНЮ (ВІДНОСНО ДО) за латинським позначеням 

int key_to_pitch(string key, int notation = 1); // Визначення висоти (в півтонах) за латинським позначеням

string key_to_notename(string key, int notation = 1); /// ВИЗНАЧЕННЯ НАЗВИ НОТИ (СЛОВАМИ)

void Line();

string Longline();

float MeanSharpness(Polychord chord, int sounds); // визначає середнє положення на квінтовому колі

int Mode();

bool Oncemore();

string pnotes();

Polychord nonchord_from_keys(string key[], int notation);

string get_chord_string(int sounds);
 
string note_to_key(int step, int pitch); // Трансформує значення ступеню і висоти в латинське написання 

string pitch_to_notename(int step, int pitch); /// ВИЗНАЧЕННЯ НАЗВИ НОТИ (ЗА СТУПІННЮ І ВИСОТОЮ) 

string step_to_notename(int step, int alter); /// ВИЗНАЧЕННЯ АБСОЛЮТНОЇ ВИСОТИ ЗВУКА (У ПІВТОНАХ від рівня ДО)

int pitchchange(string n_acc, string note_as_written, int notation = 1); /// допоміжний для визначення назви ноти

bool PitchFilter(int* pitch, int sounds); // фільтрує акорди з октавами



/* Підрахунок інтервалів між нотами.
Виходимо з того, що кожен наступний голос вищий за попередній,
тому за потреби додаємо до вищого голосу октаву: 7 ступенів або 12 півтонів
*/

int pitchdiff(int low_pitch, int high_pitch);

Polychord* Polychord_Add(Polychord* polychord, int modifications, int& counter, int& sound, int sounds, bool test);

float Sharpness(int enterstep, int alter); // вводиться step, alter 

int stepdiff(int low_note, int high_note);

int step_to_pitch(int step, int alteration);  /// ВИЗНАЧЕННЯ НАЗВИ НОТИ (ЗА ЛАТИСНКЬИМ ПОЗНАЧЕННЯМ) 

int sum_steps(int step[], int NoI);

int sum_pitchs(int pitch[], int NoI);

void title(int c, string title);

void tableheader(string header);

void tablefooter(float consonansrate, bool rate, int amount);

int quality_of_a_step(int position, int* steps, int* halftones, int inversion = 0);

#endif
