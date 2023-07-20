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
				cout << A[i].key[j] << " -> ";
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