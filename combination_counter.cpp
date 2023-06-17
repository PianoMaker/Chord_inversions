long long factorial_counter(int amount);

long long combination_counter(int NoN, int sounds = 2) // параметр за замовчуванням для інтервалів
{
	if (NoN < sounds)
		return 0;
	long long diff, combinations;
	diff = NoN - sounds;
	combinations = factorial_counter(NoN) / (factorial_counter(sounds) * factorial_counter(diff));
	return combinations;
}