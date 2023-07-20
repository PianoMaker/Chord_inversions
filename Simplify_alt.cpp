#include"Notes.h"

void Simplify(Polychord *A, int modifications, bool notation)
{
	for(int i = 0; i < modifications; i++)
		for (int j = 0; j < A[i].numberofnotes; j++)
		{
			A[i].alter[j] = alter_from_pitch(A[i].step[j], A[i].pitch[j]); // альтерації (int)
			if (A[i].alter[j] > 1)
			{
				A[i].step[j]+=1;
				A[i].name[j] = Pitch_to_notename(A[i].step[j], A[i].pitch[j]);
				A[i].key[j] = Note_to_key(A[i].step[j], A[i].pitch[j], notation);
				cout << A[i].key[j] << endl;
				A[i].alter[j] = alter_from_pitch(A[i].step[j], A[i].pitch[j]);
			
			}
			else if (A[i].alter[j] < -1)
			{
				A[i].step[j]--;
				A[i].name[j] = Pitch_to_notename(A[i].step[j], A[i].pitch[j]);
				A[i].key[j] = Note_to_key(A[i].step[j], A[i].pitch[j], notation);
				A[i].alter[j] = alter_from_pitch(A[i].step[j], A[i].pitch[j]);
			}
		}
}

void Sharpize(Polychord* A, int modifications, bool notation)
{
	for (int i = 0; i < modifications; i++)
		for (int j = 0; j < A[i].numberofnotes; j++)
		{
			A[i].alter[j] = alter_from_pitch(A[i].step[j], A[i].pitch[j]); // альтерації (int)
			while (A[i].alter[j] < 0)
			{
				A[i].step[j] -= 1;
				A[i].name[j] = Pitch_to_notename(A[i].step[j], A[i].pitch[j]);
				//cout << A[i].key[j] << " -> ";
				A[i].key[j] = Note_to_key(A[i].step[j], A[i].pitch[j], notation);
				//cout << A[i].key[j] << endl;
				A[i].alter[j] = alter_from_pitch(A[i].step[j], A[i].pitch[j]);
			}
		}
}

void Flatize(Polychord* A, int modifications, bool notation)
{
	for (int i = 0; i < modifications; i++)
		for (int j = 0; j < A[i].numberofnotes; j++)
		{
			A[i].alter[j] = alter_from_pitch(A[i].step[j], A[i].pitch[j]); // альтерації (int)
			while (A[i].alter[j] > 0)
			{
				A[i].step[j] += 1;
				A[i].name[j] = Pitch_to_notename(A[i].step[j], A[i].pitch[j]);
				//cout << A[i].key[j] << " -> ";
				A[i].key[j] = Note_to_key(A[i].step[j], A[i].pitch[j], notation);
				//cout << A[i].key[j] << endl;
				A[i].alter[j] = alter_from_pitch(A[i].step[j], A[i].pitch[j]);
			}
		}
}

void Stepdown(Polychord &A, bool notation)
{
		for (int j = 0; j < A.numberofnotes; j++)
		{
			A.step[j] -= 1;
			A.name[j] = Pitch_to_notename(A.step[j], A.pitch[j]);
			A.key[j] = Note_to_key(A.step[j], A.pitch[j], notation);
			A.alter[j] = alter_from_pitch(A.step[j], A.pitch[j]);
		}
}

void Stepup(Polychord &A, bool notation)
{
		for (int j = 0; j < A.numberofnotes; j++)
		{
			A.step[j] += 1;
			A.name[j] = Pitch_to_notename(A.step[j], A.pitch[j]);
			A.key[j] = Note_to_key(A.step[j], A.pitch[j], notation);
			A.alter[j] = alter_from_pitch(A.step[j], A.pitch[j]);
		}
}

void Alterize(Polychord* A, int modifications, bool notation)
{
	for (int i = 0; i < modifications; i++)
	{
		int sharp = MeanSharpness(A[i]);
		if (sharp > 6)
			Stepup(A[i], notation);
		else if (sharp < -6)
			Stepdown(A[i], notation);
	}
}