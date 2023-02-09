#include <iostream>;
using namespace std;

#ifndef NOTECOUNTER
#define NOTECOUNTER

/// МАЛЮНОЧОК
void clef();


int addstep(int step1, int step2);

int addpitch(int pitch1, int pitch2);

int int_quality(int steps, int halftones); // якість інтервалу

int If_note_in_Chord(int* step, int interval, int NON); // визначає позицію заданого інтервалу в акорді

int key_to_step(string key, int notation = 1); // ВИЗНАЧЕННЯ СТУПЕНЮ (ВІДНОСНО ДО) за латинським позначеням 

int key_to_pitch(string key, int notation = 1); // Визначення висоти (в півтонах) за латинським позначеням

string key_to_notename(string key, int notation = 1); /// ВИЗНАЧЕННЯ НАЗВИ НОТИ (СЛОВАМИ)
 
string note_to_key(int step, int pitch); // Трансформує значення ступеню і висоти в латинське написання 

string pitch_to_notename(int step, int pitch); /// ВИЗНАЧЕННЯ НАЗВИ НОТИ (ЗА СТУПІННЮ І ВИСОТОЮ) 

string step_to_notename(int step, int alter); /// ВИЗНАЧЕННЯ АБСОЛЮТНОЇ ВИСОТИ ЗВУКА (У ПІВТОНАХ від рівня ДО)

int pitchchange(string n_acc, string note_as_written, int notation = 1); /// допоміжний для визначення назви ноти

int step_to_pitch(int step, int alteration);  /// ВИЗНАЧЕННЯ НАЗВИ НОТИ (ЗА ЛАТИСНКЬИМ ПОЗНАЧЕННЯМ) 

/* Підрахунок інтервалів між нотами.
Виходимо з того, що кожен наступний голос вищий за попередній,
тому за потреби додаємо до вищого голосу октаву: 7 ступенів або 12 півтонів
*/

int pitchdiff(int low_pitch, int high_pitch);

int stepdiff(int low_note, int high_note);


int quality_of_a_step(int position, int* steps, int* halftones, int inversion = 0);

#endif
