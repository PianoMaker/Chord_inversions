#include"Notes.h"
#include <vector>
#include <algorithm>
#include <algorithm>


int CombineN(Polychord initial, Polychord* inverted, int nn)
{
	inverted[0] = initial;

	int c = 1; // рахує кількість модифікацій

	std::vector<std::string> combination(nn);
	for (int i = 0; i < nn; i++) {
		combination[i] = initial.key[i];
	}

	// Генеруємо всі можливі комбінації за допомогою next_permutation
	while (std::next_permutation(combination.begin(), combination.end())) {
		for (int i = 0; i < nn; i++) {
			inverted[c].key[i] = combination[i];
		}
		c++;
	}

	return c;
}


int Combine6(Polychord initial, Polychord* inverted)
{

	inverted[0] = initial;

	int c = 0;//рахує кількість модифікацій

    int nn = 6;//кількість нот в акорді

	for (int i = 0; i < nn; i++)
		for (int j = 0; j < nn; j++)
			for (int k = 0; k < nn; k++)
				for (int l = 0; l < nn; l++)
					for (int m = 0; m < nn; m++)
						for (int n = 0; n < nn; n++)
						{
							if (i != j && i != k && i != l && i != m && i != n &&// умова для уникнення однакових нот
								j != k && j != l && j != m && j != n
								&& k != l && k != m && k != n
								&& l != m && l != n &&
								m != n)
							{

								//cout << c << ": ";
								inverted[c].key[0] = initial.key[i]; //cout << initial.key[i];
								inverted[c].key[1] = initial.key[j]; //cout << initial.key[j];
								inverted[c].key[2] = initial.key[k]; //cout << initial.key[k];
								inverted[c].key[3] = initial.key[l]; //cout << initial.key[l];
								inverted[c].key[4] = initial.key[m]; //cout << initial.key[m] << endl;
								inverted[c].key[5] = initial.key[n]; //cout << initial.key[m] << endl;

								c++;
							}
						}
    return c;
}

int Combine5(Polychord initial, Polychord* inverted)
{

	inverted[0] = initial;

	int c = 0;//рахує кількість модифікацій

	int nn = 5;//кількість нот в акорді

	for (int i = 0; i < nn; i++)
		for (int j = 0; j < nn; j++)
			for (int k = 0; k < nn; k++)
				for (int l = 0; l < nn; l++)
					for (int m = 0; m < nn; m++)
						{
							if (i != j && i != k && i != l && i != m &&// умова для уникнення однакових нот
								j != k && j != l && j != m 
								&& k != l && k != m 
								&& l != m  )
							{

								//cout << c << ": ";
								inverted[c].key[0] = initial.key[i]; //cout << initial.key[i];
								inverted[c].key[1] = initial.key[j]; //cout << initial.key[j];
								inverted[c].key[2] = initial.key[k]; //cout << initial.key[k];
								inverted[c].key[3] = initial.key[l]; //cout << initial.key[l];
								inverted[c].key[4] = initial.key[m]; //cout << initial.key[m] << endl;
								c++;
							}
						}
	return c;
}


