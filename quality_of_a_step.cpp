#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;
int Int_quality(int steps, int halftones);

int quality_of_a_step(int position, int* steps, int* halftones, int inversion = 0) // визначає якість інтервалу між басом і нотою на заданій позиції
{
	int quality;
	int base_halftones = 0;
	int base_steps = 0;
	for (int i = 0; i < position; i++)
		base_halftones += halftones[i];
	for (int i = 0; i < position; i++)
		base_steps += steps[i];
	quality = Int_quality(base_steps, base_halftones);
	return quality;
}