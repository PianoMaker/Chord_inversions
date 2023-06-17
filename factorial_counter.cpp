#include"Notes.h"

long long factorial_counter(int amount)
{
	long long factorial = 1.0;

	if (amount < 0)
		cout << "Error! Factorial of a negative number doesn't exist.";
	else {
		for (int i = 1; i <= amount; ++i) {
			factorial *= i;
		}
	}
	//cout << factorial << endl;
	return factorial;
}