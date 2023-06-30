#include "Notes.h"



string longline = "\n_________________\n";
enum IFMAJOR {dur = true, moll = false};
int addstep(int step, int addition);


/// МАЛЮНОЧОК

void Line()
{
	cout << longline;
}


/// ВПЛИВ ЗНАКІВ АЛЬТЕРАЦІЇ НА ВИСОТУ ЗВУКА


int Inv_chord(int Chordtype)
{
	if (Chordtype == SEPT)  return QUINTS;
	else if (Chordtype == QUINTS)  return TERZQ;
	else if (Chordtype == TERZQ)  return SEC;
	else if (Chordtype == SEC)  return SEPT;
	else;
}

/* Підрахунок інтервалів між нотами.
Виходимо з того, що кожен наступний голос вищий за попередній,
тому за потреби додаємо до вищого голосу октаву: 7 ступенів або 12 півтонів
*/

int alteration_counter(string key, int notation) // нота текстом, система нотації

{
	string note_as_written(key, 0, 1);
	string n_acc(key, 1, 4);
	int alteration;
	int notation_type = notation;
	if (note_as_written == "b" && notation) alteration = -1;
	else alteration = pitchchange(n_acc, note_as_written, notation_type);
	return alteration;
}

int sharpness_count(int enterstep, int alteration = 0) // вводиться step, alter 
{
	int sharpness;

	if (enterstep > 6) enterstep -= 7;
	if (enterstep == FA) sharpness = -3;
	else if (enterstep == DO) sharpness = -2;
	else if (enterstep == SOL) sharpness = -1;
	else if (enterstep == RE) sharpness = 0;
	else if (enterstep == LA) sharpness = 1;
	else if (enterstep == MI) sharpness = 2;
	else if (enterstep == SI) sharpness = 3;
	else sharpness = 555;

	//if (alteration) sharpness += alteration * 7;

	return sharpness;

}

// Розвязання 
// Структура представляє акорд - 4 ступені і 4 висоти тону.

struct Thechord
{
	int s1;
	int s3;
	int s5;
	int s7;
	int p1;
	int p3;
	int p5;
	int p7;
	int position1;
	int position3;
	int position5;
	int position7;
};


// 

int s1(Thechord chord, int steps)
{
	return addstep(chord.s1, steps);
}
int s3(Thechord chord, int steps)
{
	return addstep(chord.s3, steps);
}
int s5(Thechord chord, int steps)
{
	return addstep(chord.s5, steps);
}
int s7(Thechord chord, int steps)
{
	return addstep(chord.s7, steps);
}

// picthes
int p1(Thechord chord, int pitchs)
{
	return addpitch(chord.p1, pitchs);
}
int p3(Thechord chord, int pitchs)
{
	return addpitch(chord.p3, pitchs);
}
int p5(Thechord chord, int pitchs)
{
	return addpitch(chord.p5, pitchs);
}
int p7(Thechord chord, int pitchs)
{
	return addpitch(chord.p7, pitchs);
}

string Res_name(Thechord chord, int i)

{
	int res_step[4], res_pitch[4]; string  res_name;
	res_step[chord.position1] = chord.s1;
	res_step[chord.position3] = chord.s3;
	res_step[chord.position5] = chord.s5;
	res_step[chord.position7] = chord.s7;
	res_pitch[chord.position1] = chord.p1;
	res_pitch[chord.position3] = chord.p3;
	res_pitch[chord.position5] = chord.p5;
	res_pitch[chord.position7] = chord.p7;
	res_name = pitch_to_notename(res_step[i], res_pitch[i]);
	return res_name;

}
void Resolve(Thechord r) // вивід на екран розв’язання
{
	string res_name[4];
	for (int i = 0; i < 4; i++)
	{
		res_name[i] = Res_name(r, i);
	}
	cout << res_name[0] << " - " << res_name[1] << " - " << res_name[2] << " - " << res_name[3] << endl;
}

void FOO (string x, string  y, int Chordtype)
{
	string inversion;
	//cout << "Chordtype = " << Chordtype;
	if (Chordtype == SEPT) inversion = "7";
	else if (Chordtype == SEC) inversion = "2";
	else if (Chordtype == TERZQ) inversion = "4/3";
	else if (Chordtype == QUINTS) inversion = "6/5";
	else  inversion = " ";
	cout << "\n\tФункція: " << x << inversion << setw(5) << " --> " << y << endl;
}

void Tonality(string res_tone, bool ifmajor)
{
	
	if (ifmajor) cout << "\tТональність: " << setw(5) << res_tone << setw(5) << " мажор" << endl;
	else cout << "\tТональність: " << setw(3) << res_tone << setw(3) << " мінор" << endl;
}

void Chordname(string chordname, string qualityname)
{
	cout << endl << qualityname << " " << chordname << endl;
}



/// Основна програма
using namespace std;
int main()
{
	clef();
	system("pause");
	system("cls");

	int NoN = 4; // кількість нот в акорді
	/*cout << "скільки нот буде в акорді?" << endl;
	cin >> NoN;*/
	int multiN = 6;
	// основні характеристики для кожного звука
	int* pitch = new int[NoN]; // висота звуку (у півтонах) в кожному з голосів
	int* step = new int[NoN]; // ступінь у кожному з голосів
	int* alter = new int[NoN]; // альтерація для кожної з нот

	// розв’язання
	int* res_pitch = new int[NoN]; // висота звуку (у півтонах) в кожному з голосів
	int* res_step = new int[NoN]; // ступінь у кожному з голосів
	int* res_alter = new int[NoN]; // альтерація для кожної з нот
	// розв’язання альтернативне
	int* res_pitch2 = new int[NoN]; // висота звуку (у півтонах) в кожному з голосів
	int* res_step2 = new int[NoN]; // ступінь у кожному з голосів
	int* res_alter2 = new int[NoN]; // альтерація для кожної з нот
	/*res_pitch2 = res_pitch;
	res_step2 = res_step;
	res_alter2 = res_alter;*/
	// те саме для обернених акордів
	int* qualities = new int[NoN]; // для підрахунку якостей інтервалів
	bool restricted; // для пошуку розщеплених інтервалів


	// змінні для аналізу
	int* basic_sharpness = new int[NoN]; // бал по бемольно-дієзній шкалі 
	int NoI = NoN - 1; // кількість інтервалів між сусідніми нотами в акорді
	int unison = 0; // змінна для пошуку унісонів
	int prima, secunda, terzia, quarta, quinta, seksta, septyma, Chordtype = 0, inversion = 0; // визначають позиції інтервалів
	int iprima, isecunda, iterzia, iquarta, iquinta, iseksta, iseptyma; // визначають позиції інтервалів для основного різновиду
	int Prima, Secunda, Terzia, Quarta, Quinta, Seksta, Septyma, Multichord; // визначають позиції інтервалів і тип септакорду
	int step_quality; // визначає якість інтервалу на заданій позиції
	int* allhalftones = new int[multiN]; // усі можливі інтервали мід голосами у півтонах (октава = 12)
	int* allsteps = new int[multiN]; // усі можливі інтервали мід голосами у ступінях (секунда = 1, терція = 2 і т.д.)
	int* allqualities = new int[multiN]; // якості інтервалів (чисті, малі, великі і т.д.)
	int* halftones = new int[NoN]; // інтервали між сусідніми голосами у півтонах (октава = 12)
	int* inv_halftones = new int[NoN]; // інтервали між сусідніми голосами у півтонах (октава = 12)
	int* steps = new int[NoN]; // інтервали у ступінях (секунда = 1, терція = 2 і т.д.)
	int* inv_steps = new int[NoN]; // інтервали у ступінях (для обернених інтервалів)
	int* quality = new int[multiN]; // якості інтервалів (чисті, малі, великі і т.д.)
	int n_steps = 0;
	int main_tone; // основний тон
	bool IFSEPT = false; // чи є акорд септакордом (+обернення)
	bool IFTRI = false; // чи є акорд тризвуком (+обернення)
	bool IFHSEPT = false; // чи є акорд неповним септакордом (+обрернення)
	string res_tone; // основний тон тональності розв’язання 
	string* key = new string[NoN];  // для введення звуків з клавіатури в кожному з голосів
	string* name = new string[NoN]; // для відображення назв звуків у кожному з голосів
	string* name2 = new string[NoN]; // для відображення назв звуків у кожному з голосів (альтернативне)
	string chordname; // назва акорду
	string inv_chordname; // назва основного акорду
	string qualityname; // назва акорду
	string res_name[4]; // назви нот в розв’язанні
	string res_name2[4]; // альтернативний



	int notation; // вибір системи нотації. Можна переписати через bool, але не люблю глюків. 
	cout << "оберіть тип буквенної нотації 0 - американська, 1 - європейська" << endl;
	cin >> notation;

	if (notation) cout << "ви обрали європейський тип нотації" << endl;
	else cout << "ви обрали американський тип нотації" << endl;
start:
	cin.get();
	system("cls");

	// отут власне старт введення нот (бас, тенор, альт, сопрано). 
	string c_a_scale = "\nс - до,\nd - ре,\ne - мі,\nf - фа,  \ng - соль, \na - ля\n";
	if (notation)
		cout << "введіть ноти, використовуючи європейську буквенну нотацію" << c_a_scale << "b - сі - бемоль\t h - сі \nis - дiєз, \n es - бемоль  \n";
	else
		cout << "введіть ноти, використовуючи американську буквенну нотацію" << c_a_scale << "b - сі \n#  - дiєз, \nb - бемоль  \n";


for (int i = 0; i <= NoI; i++)
		{
			do
			{
				if (i < 4) cout << longline << voice(i) << endl;
				else cout << longline << voice(i) << i - 3 << endl;
				cin >> key[i];
				cout << "введено: ";
				pitch[i] = key_to_pitch(key[i], notation);
				name[i] = key_to_notename(key[i], notation);
				step[i] = key_to_step(key[i], notation);
				alter[i] = alteration_counter(key[i], notation);  // вплив знаків альтерації 
				basic_sharpness[i] = sharpness_count(step[i]);
				cout << name[i] << endl;
				//cout << "(відносна висота: " << pitch[i] << ")" << endl;*/
				if (pitch[i] == -100) cout << "спробуйте ще раз\n";
			} while (pitch[i] == -100);

		}

	system("cls");
	cout << longline << "РЕЗУЛЬТАТИ:";

	cout << "\nВведено ноти : " << name[0] << " - " << name[1] << " - " << name[2] << " - " << name[3] << longline;

	// АНАЛІЗ
	// виявлення інтервалів
	prima = If_note_in_Chord(step, PRIMA, NoN);
	secunda = If_note_in_Chord(step, SECUNDA, NoN);
	terzia = If_note_in_Chord(step, TERZIA, NoN);
	quarta = If_note_in_Chord(step, QUARTA, NoN);
	quinta = If_note_in_Chord(step, QUINTA, NoN);
	seksta = If_note_in_Chord(step, SEKSTA, NoN);
	septyma = If_note_in_Chord(step, SEPTYMA, NoN);

	intervals_detected( prima,  secunda,  terzia,  quarta,  quinta,  seksta,  septyma);


	// Визначеня типу акорду та інтервалів

	Chordtype = ChordType(prima, secunda, terzia, quarta, quinta, seksta, septyma);
	chordname = ChordName(Chordtype);

	if (Chordtype == SEPT || Chordtype == TERZQ || Chordtype == QUINTS || Chordtype == SEC) 	IFSEPT = true;
	else if (Chordtype == TRI || Chordtype == SEXT || Chordtype == QSEXT)  IFTRI = true;
	else if (Chordtype == HSEPT || Chordtype == HSEC || Chordtype == HQUINTS) IFHSEPT = true;
	else
	{
		Chordname(chordname, qualityname);
		return Chordtype;
	}

	// Визначеня позиції окремих акордових звуків

	iprima = Iprima( prima,  secunda,  terzia,  quarta,  quinta, seksta,  septyma,  Chordtype);
	isecunda = Isecunda( prima,  secunda,  terzia,  quarta,  quinta,  seksta,  septyma,  Chordtype);
	iterzia = Iterzia( prima,  secunda,  terzia,  quarta,  quinta,  seksta,  septyma,  Chordtype);
	iquarta = Iquarta( prima,  secunda,  terzia,  quarta,  quinta,  seksta,  septyma,  Chordtype);
	iquinta = Iquinta( prima,  secunda,  terzia,  quarta,  quinta,  seksta,  septyma,  Chordtype);
	iseksta = Iseksta( prima,  secunda,  terzia,  quarta,  quinta,  seksta,  septyma,  Chordtype);
	iseptyma = Iseptyma( prima,  secunda,  terzia,  quarta,  quinta,  seksta,  septyma,  Chordtype);

			

	// Визначаємо якості інтервалів

	Terzia = Q_Terzia(pitch[iprima], pitch[iterzia]);
	if (!IFHSEPT) Quinta = Q_Quinta(pitch[iprima], pitch[iquinta]);
	if (!IFTRI) Septyma = Q_Septyma(pitch[iprima], pitch[iseptyma]);


	if (IFSEPT) Multichord = Multichord_type( Terzia,  Quinta,  Septyma);
	if (IFSEPT) qualityname =  Multichord_name( Terzia,  Quinta,  Septyma);


	

sept:
	// створення структури септакорду з метою подальших розв’язань
	if (IFSEPT)
	{
		
		Chordname(chordname, qualityname);

		cout << "Розв’язання:" << endl;
		
		
		Thechord t;
		t.s1 = step[iprima];
		t.s3 = step[iterzia];
		t.s5 = step[iquinta];
		t.s7 = step[iseptyma];
		t.p1 = pitch[iprima];
		t.p3 = pitch[iterzia];
		t.p5 = pitch[iquinta];
		t.p7 = pitch[iseptyma];
		t.position1 = iprima;
		t.position3 = iterzia;
		t.position5 = iquinta;
		t.position7 = iseptyma;

		// створення структури для розв'язання
		Thechord r = t;
		Thechord r2 = t;


		//// Розв’язуємо септакорди залежно від типу


		switch (Multichord)
		{
		case MINMAJ: // D7
		{
			chordname = "Домінант септакорд";
			// у мажорі 
			// D7->T
			if (Chordtype == SEPT) r.s1 = s1(t, 3);
			else  r.s1 = s1(t, 0);
			r.s7 = s7(t, -1);
			r.s5 = s5(t, -1);
			r.s3 = s3(t, 1);
			if (Chordtype == SEPT)  r.p1 = p1(t, 5);
			else r.p1 = p1(t, 0);
			r.p7 = p7(t, -1);
			r.p5 = p5(t, -2);
			r.p3 = p3(t, 1);

			res_tone = pitch_to_notename(addstep(t.s1, 3), addpitch(t.p1, 5));// тональність


			Tonality(res_tone, dur);
			FOO("D", "T", Chordtype);
			Resolve(r);

			// D7 -> VI
			r.s1 = s1(t, 1);
			r.p1 = p1(t, 2);

			FOO("D", "VI", Chordtype);
			Resolve(r);

			//// у мінорі
			// D7 -> t

			Line();
			Tonality(res_tone, moll);
			if (Chordtype == SEPT)
			{
				r.s1 = s1(t, 3);
				r.p1 = p1(t, 5);
			}
			else
			{
				r.s1 = s1(t, 0);
				r.p1 = p1(t, 0);
			}
			r.p7 = p7(t, -2);
						

			FOO("D", "t", Chordtype);
			Resolve(r);

			// D7 -> vi
			r.s1 = s1(t, 1);
			r.p1 = p1(t, 1);

			FOO("D", "vi", Chordtype);
			Resolve(r);
			break;
		}


		case MINMIN: // II
		{
			//II -> T
			chordname = "Септакорд ІІ в мажорі";

			if (Chordtype == QUINTS)
			{
				r.s1 = s1(t, 1);
				r2.s1 = s1(t, 3);
				r.p1 = p1(t, 2);
				r2.p1 = p1(t, 5);
			}
			else if (Chordtype == SEC)
			{
				r2.s1 = s1(t, -1);
				r.s1 = s1(t, 1);
				r2.p1 = p1(t, -2);
				r.p1 = p1(t, 2);
			}
			else
			{
				r.s1 = s1(t, 1);
				r.p1 = p1(t, 2);
			}

			r.s7 = s7(t, 0);
			r.p7 = p7(t, 0);// CONSTANT!


			if (Chordtype == SEC)
			{
				r2.s5 = s5(t, -1);
				r.s5 = s5(t, 2);
				r2.p5 = p5(t, -2);
				r.p5 = p5(t, 3);
			}
			else if (Chordtype == QUINTS)
			{
				r.s5 = s5(t, -1);
				r2.s5 = s5(t, -1);
				r.p5 = p5(t, -2);
				r2.p5 = p5(t, -2);
			}
			else
			{
				r.s5 = s5(t, -1);
				r.p5 = p5(t, -2);
			}

			if (Chordtype == QUINTS)
			{
				r.s3 = s3(t, -3);
				r2.s3 = s3(t, -1);
				r.p3 = p3(t, -5);
				r2.p3 = p3(t, -1);
			}
			else if (Chordtype == SEC)
			{
				r2.s3 = s3(t, -1);
				r.s3 = s3(t, 1);
				r2.p3 = p3(t, -1);
				r.p3 = p3(t, 2);
			}
			else
			{
				r.s3 = s3(t, 1);
				r.p3 = p3(t, 2);
			}

			res_tone = pitch_to_notename(addstep(t.s1, -1), addpitch(t.p1, -2));// тональність
			Tonality(res_tone, dur);
			FOO("II ", "T", Chordtype);
			Resolve(r);
			if (Chordtype == QUINTS || Chordtype == SEC && t.position1 != 1) Resolve(r2);
			else;


			// S7 -> t 
			Line();
			chordname = "Септакорд ІV в мінорі";

			if (Chordtype == SEPT) r.s1 = s1(t, -3);
			else r.s1 = s1(t, 1);
			r.s7 = s7(t, 0);
			r.s5 = s5(t, 0);
			r.s3 = s3(t, -1);
			if (Chordtype == SEPT)  r.p1 = p1(t, -5);
			else r.p1 = p1(t, 2);
			r.p7 = p7(t, 0);
			r.p5 = p5(t, 0);
			r.p3 = p3(t, -1);

			res_tone = pitch_to_notename(addstep(step[iprima], -3), addpitch(pitch[iprima], -5));// тональність
			Tonality(res_tone, moll);
			FOO("IV ", "T", Chordtype);
			Resolve(r);

			//V -> t
			Line();
			chordname = "Септакорд V в мінорі";

			if (Chordtype == SEPT) r.s1 = s1(t, -4);
			else r.s1 = s1(t, 0);
			r.s7 = s7(t, -1);
			r.s5 = s5(t, -1);
			r.s3 = s3(t, -2);
			if (Chordtype == SEPT)  r.p1 = p1(t, -7);
			else r.p1 = p1(t, 0);
			r.p7 = p7(t, -2);
			r.p5 = p5(t, -2);
			r.p3 = p3(t, -3);

			res_tone = pitch_to_notename(r.s5, r.p5);// тональність
			Tonality(res_tone, moll);
			FOO("V ", "t", Chordtype);
			Resolve(r);


			break;

		}

		case MINDIM: // VII

		{
			//VII -> T
			Line();
			chordname = "Септакорд VІІ в мажорі";

			r.s1 = s1(t, 1);
			r.p1 = p1(t, 1);

			r.s3 = s3(t, 1);
			r.p3 = p3(t, 2);

			r.s5 = s5(t, -1);
			r.p5 = p5(t, -1);

			r.s7 = s7(t, -1);
			r.p7 = p7(t, -2);

			res_tone = pitch_to_notename(addstep(step[iprima], 1), addpitch(pitch[iprima], 1));// тональність
			Tonality(res_tone, dur);
			FOO("VII ", "T", Chordtype);
			Resolve(r);

			// VII -> D -> T

			FOO("VII ", "D --> T ", Chordtype);

			r.s1 = s1(t, 0);
			r.p1 = p1(t, 0);

			r.s3 = s3(t, 0);
			r.p3 = p3(t, 0);

			r.s5 = s5(t, 0);
			r.p5 = p5(t, 0);

			r.s7 = s7(t, -1);
			r.p7 = p7(t, -2);

			Resolve(r);

			r2.s1 = s1(t, 1);
			r2.p1 = p1(t, 1);

			r2.s3 = s3(t, -1);
			r2.p3 = p3(t, -2);

			r2.s5 = s5(t, -1);
			r2.p5 = p5(t, -1);

			r2.s7 = s7(t, -1);
			r2.p7 = p7(t, -2);

			Resolve(r2);

			// II - t 

			Line();
			chordname = "Септакорд ІІ в мінорі";

			if (Chordtype == QUINTS)
			{
				r.s1 = s1(t, 1);
				r2.s1 = s1(t, 3);
				r.p1 = p1(t, 1);
				r2.p1 = p1(t, 5);
			}
			else if (Chordtype == SEC)
			{
				r2.s1 = s1(t, -1);
				r.s1 = s1(t, 1);
				r2.p1 = p1(t, -2);
				r.p1 = p1(t, 1);
			}
			else
			{
				r.s1 = s1(t, 1);
				r.p1 = p1(t, 1);
				r2.s1 = s1(t, 1);
				r2.p1 = p1(t, 1);
			}

			r.s7 = s7(t, 0);
			r.p7 = p7(t, 0);// CONSTANT!
			r2.s7 = s7(t, 0);
			r2.p7 = p7(t, 0);// CONSTANT!


			if (Chordtype == SEC)
			{
				r2.s5 = s5(t, -1);
				r.s5 = s5(t, 2);
				r2.p5 = p5(t, -1);
				r.p5 = p5(t, 3);
			}
			else if (Chordtype == QUINTS)
			{
				r.s5 = s5(t, -1);
				r2.s5 = s5(t, -1);
				r.p5 = p5(t, -1);
				r2.p5 = p5(t, -1);
			}
			else
			{
				r.s5 = s5(t, -1);
				r.p5 = p5(t, -1);
				r2.s5 = s5(t, -1);
				r2.p5 = p5(t, -1);
			}

			if (Chordtype == QUINTS)
			{
				r.s3 = s3(t, -3);
				r2.s3 = s3(t, -1);
				r.p3 = p3(t, -5);
				r2.p3 = p3(t, -2);
			}
			else if (Chordtype == SEC)
			{
				r2.s3 = s3(t, -1);
				r.s3 = s3(t, 1);
				r2.p3 = p3(t, -2);
				r.p3 = p3(t, 2);
			}
			else
			{
				r.s3 = s3(t, 1);
				r.p3 = p3(t, 2);
				r2.s3 = s3(t, 1);
				r2.p3 = p3(t, 2);
			}

			Line();
			res_tone = pitch_to_notename(addstep(step[iprima], -1), addpitch(pitch[iprima], -2));// тональність
			Tonality(res_tone, moll);
			FOO("II ", "T", Chordtype);
			Resolve(r);
			if (Chordtype == QUINTS || Chordtype == SEC && iprima != 1) Resolve(r2);
			else;

			break;
		}

		case DIMDIM: // VII
		{
			//VII - T

			Line();
			chordname = "Септакорд VІІ в мажорі";

			r.s1 = s1(t, 1);
			r.p1 = p1(t, 1);

			r.s3 = s3(t, 1);
			r.p3 = p3(t, 2);

			r.s5 = s5(t, -1);
			r.p5 = p5(t, -1);

			r.s7 = s7(t, -1);
			r.p7 = p7(t, -1);

			res_tone = pitch_to_notename(addstep(step[iprima], 1), addpitch(pitch[iprima], 1));// тональність
			Tonality(res_tone, dur);

			FOO("VII ", "T", Chordtype);
			Resolve(r);

			//VII - t
			chordname = "Септакорд VІІ в  мінорі";

			r.s1 = s1(t, 1);
			r.p1 = p1(t, 1);

			r.s3 = s3(t, 1);
			r.p3 = p3(t, 1);

			r.s5 = s5(t, -1);
			r.p5 = p5(t, -2);

			r.s7 = s7(t, -1);
			r.p7 = p7(t, -1);

			Tonality(res_tone, moll);
			FOO("VII ", "t", Chordtype);
			Resolve(r);

			// DD -> T
			Line();
			chordname = "Подвійна домінанта в мажорі";

			r.s1 = s1(t, 1);
			r.p1 = p1(t, 1);

			r.s3 = s3(t, 1);
			r.p3 = p3(t, 1);

			r.s5 = s5(t, -1);
			r.p5 = p5(t, -2);

			r.s7 = s7(t, 0);
			r.p7 = p7(t, 0);

			res_tone = pitch_to_notename(step[iseptyma], pitch[iseptyma]);// тональність
			Tonality(res_tone, dur);
			FOO("DD ", "t", Chordtype);
			Resolve(r);

			// DD -> t
			Line();
			chordname = "Подвійна домінанта в мінорі";

			r.s1 = s1(t, 1);
			r.p1 = p1(t, 1);

			r.s3 = s3(t, -1);
			r.p3 = p3(t, -2);

			r.s5 = s5(t, 0);
			r.p5 = p5(t, 0);

			r.s7 = s7(t, 0);
			r.p7 = p7(t, 0);

			res_tone = pitch_to_notename(step[iquinta], pitch[iquinta]);// тональність
			Tonality(res_tone, moll);
			FOO("#IV ", "t", Chordtype);
			Resolve(r);
			break;
		}

		case MAJMAJ:
		{
			//S - T

			Line();
			chordname = "Субдомінантсептакорд в мажорі";

			if (Chordtype == SEPT)
			{
				r.s1 = s1(t, -3);
				r.p1 = p1(t, -5);
			}

			else
			{
				r.s1 = s1(t, 1);
				r.p1 = p1(t, 2);
			}
			if (Chordtype == TERZQ)
			{
				r.s3 = s3(t, 2);
				r.p3 = p3(t, 3);
			}
			else
			{
				r.s3 = s3(t, -1);
				r.p3 = p3(t, -2);
			}

			r.s5 = s5(t, 0);
			r.p5 = p5(t, 0);

			r.s7 = s7(t, 0);
			r.p7 = p7(t, 0);

			res_tone = pitch_to_notename(r.s5, r.p5);// тональність
			Tonality(res_tone, dur);
			FOO("IV ", "T", Chordtype);
			Resolve(r);
			break;

		}
		case MAJAUG:
		{
			//III - t

			Line();
			chordname = "ІІІ  в мінорі";

			r.s1 = s1(t, 0);
			r.p1 = p1(t, 0);


			r.s3 = s3(t, 0);
			r.p3 = p3(t, 0);

			r.s5 = s5(t, 1);
			r.p5 = p5(t, 1);

			r.s7 = s7(t, -1);
			r.p7 = p7(t, -2);

			res_tone = pitch_to_notename(r.s5, r.p5);// тональність
			Tonality(res_tone, moll);
			FOO("III ", "t", Chordtype);
			Resolve(r);
			break;
		}
	unknown:
		default:
			cout << "Структуру акорда не розпізнано" << endl;
		}
	}
	//  Тризвуки та їх обернення
	else if (IFTRI) 

	{
		Line();
		res_tone = pitch_to_notename(step[iprima], pitch[iprima]);
		if (Terzia == MAJ)
			
		{
			if (Quinta == AUG)
			{
				qualityname = "збільшений"; 
			}
			else Tonality(res_tone, dur);
		}
		else if (Terzia == MIN)
		{
			if (Quinta == DIM)
			{
				qualityname = "зменшений";
			}
			else
				Tonality(res_tone, moll);
		}
		else
			cout << "альтерований" << chordname << endl;

		Chordname(chordname,qualityname);
	}
		
	
	else
	cout << "\nТип акорду: " << chordname << endl;

	


	bool oncemore;
	cout << "Спробувати ще раз?  (1 - так, 0 - ні) " << endl;
	cin >> oncemore;
	if (oncemore) goto start;

	return Chordtype;
}