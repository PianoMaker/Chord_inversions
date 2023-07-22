#include"Notes.h";

Polychord* Polychord_Add(Polychord* polychord, long modifications, int& counter, int& sound, int sounds, bool test)
{

	Polychord* A = new Polychord[counter * 2];


	if (test)cout << "" << "" << "" << "" << "";
	//else cout << "_";


	for (int i = 0; i < counter; i++)
	{
		//if (test)cout << "\nCopying existing chord from taken:\n";
		for (int j = 0; j <= sound; j++)
		{
			A[i].pitch[j] = polychord[i].pitch[j]; // старі акорди
			A[i].step[j] = polychord[i].step[j]; // старі акорди
			if (test)cout << "";
		}

	}

	//if (test)std::system("pause>0");
	//if (test)cout << "\nTransfering chords to make room for new ones: " << endl;
	for (int i = counter - 1; i > 0; i--)
	{
		A[i * 2] = A[i];
		//if (test)cout << i * 2 << " -> " << i << endl;
	}


	//if (test)std::system("pause>0");
	if (test)cout << "";
	//else cout << ".";

	for (int i = 0; i <= (counter - 1) * 2; i += 2)
	{
		for (int j = 0; j <= sound; j++)
		{
			A[i + 1].pitch[j] = A[i].pitch[j]; // нові акорди, копія старих вуків
			A[i + 1].step[j] = A[i].step[j]; // нові акорди, копія старих вуків
			//if (test)cout << "chord " << i + 1 << ", pitch" << j << " = " << A[i].pitch[j] << endl;
		}
	} if (test)cout << "";

	////////////////////!!!!!!!!!!!!!!!!!!!!!//////////////////////
	if (test)
	{

		//system("pause>0");
		//cout << "\nVerifying chords:\n " << endl;
		for (int i = 0; i < counter * 2; i++)
		{
			for (int k = 0; k <= sound; k++)
				cout << "";
			cout << "";
		}

	}
	///////////////////////////!!!!!!!!!!!!////////////////////

	if (test)
	{
		//system("pause>0");
		//cout << "\nCreating new pitch for new chords:\n " << endl;
	}
	//else cout << ".";

	for (int i = 0; i < counter * 2; i += 2)
	{
		for (int k = 0; k <= 1; k++)
		{
			A[i + k].pitch[sound + 1] = A[i + k].pitch[sound] + k + 3; // + 1 звук
			A[i + k].step[sound + 1] = A[i + k].step[sound] + 2;
			//if (test)cout << "chord " << i + k << ", pitch " << A[i + k].pitch[sound + 1] << endl;

		}
		//if (test)cout << endl;
	}

	sound++;

	if (test)		
	{
		//system("pause>0");
		//cout << "\nVerifying chords:\n " << endl;
		//for (int i = 0; i < counter * 2; i++)
		{
			//for (int k = 0; k <= sound; k++)
				//cout << A[i].pitch[k] << " ";
			//cout << endl;
		}
	}


	if (test)
	{
		//system("pause>0");
		//cout << endl;
		//cout << "check counter = " << counter << ", check if sound < sounds: " << sound << " vs " << sounds - 1 << endl;
	}
	//else cout << ".";
	delete[] polychord;

	if (sound < sounds - 1)
	{

		counter *= 2;
		A = Polychord_Add(A, modifications, counter, sound, sounds, test);
	}
	else return A;
}