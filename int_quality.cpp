#include <iostream>

int int_quality(int steps, int halftones)
{

	int quality;
	int temp_steps = steps, temp_halftones = halftones;
	if (steps > 6) temp_steps -= 7; else;
	if (halftones > 12) temp_halftones -= 12; else;

	// умови для альтерованих досконалих консонансів (0 - прима, 3 - кварта, 4 -квінта, 7 - октава)

	if ((temp_steps == 0 && temp_halftones == 0) ||
		(temp_steps == 3 && temp_halftones == 5) ||
		(temp_steps == 4 && temp_halftones == 7) ||
		(temp_steps == 7 && temp_halftones == 12))  quality = 0; // "чистий"

	else if ((temp_steps == 0 && temp_halftones == 1) ||
		(temp_steps == 3 && temp_halftones == 6) ||
		(temp_steps == 4 && temp_halftones == 8) ||
		(temp_steps == 7 && temp_halftones == 1))  quality = 2;//збільшений

	else if ((temp_steps == 0 && temp_halftones == 2) ||
		(temp_steps == 3 && temp_halftones == 7) ||
		(temp_steps == 4 && temp_halftones == 9) ||
		(temp_steps == 7 && temp_halftones == 2))  quality = 3;//двічі збільшений

	else if ((temp_steps == 0 && temp_halftones == -1) ||
		(temp_steps == 3 && temp_halftones == 4) ||
		(temp_steps == 4 && temp_halftones == 6) ||
		(temp_steps == 7 && temp_halftones == 11))  quality = -2;//зменшений

	else if ((temp_steps == 0 && temp_halftones == -2) ||
		(temp_steps == 3 && temp_halftones == 3) ||
		(temp_steps == 4 && temp_halftones == 5) ||
		(temp_steps == 7 && temp_halftones == 10))  quality = -3;//двічі зменшений


	// умови для альтерованих недосконалих консонансів (2 - терція, 5 - секста)

	else if ((temp_steps == 2 && temp_halftones == 3) ||
		(temp_steps == 5 && temp_halftones == 8))  quality = -1; // малий

	else if ((temp_steps == 2 && temp_halftones == 2) ||
		(temp_steps == 5 && temp_halftones == 7))  quality = -2; // зменшенй

	else if ((temp_steps == 2 && temp_halftones == 4) ||
		(temp_steps == 5 && temp_halftones == 9))  quality = 1; // великий

	else if ((temp_steps == 2 && temp_halftones == 5) ||
		(temp_steps == 5 && temp_halftones == 10))  quality = 2; // збільшений


	// умови для альтерованих дисонансів (1 - секунда, 6 - септима)

	else if ((temp_steps == 1 && temp_halftones == 1) ||
		(temp_steps == 6 && temp_halftones == 10))  quality = -1;// малий

	else if ((temp_steps == 1 && temp_halftones == 0) ||
		(temp_steps == 6 && temp_halftones == 9))  quality = -2;// зменшений

	else if ((temp_steps == 1 && temp_halftones == 2) ||
		(temp_steps == 6 && temp_halftones == 11))  quality = 1;//великий

	else if ((temp_steps == 1 && temp_halftones == 3) ||
		(temp_steps == 6 && temp_halftones == 12))  quality = 2;//збільшений

	// для тих хто вирішив повимахуватись і думає, що програма це схаває

	else quality = 10;


	if (quality == 10)
	{
		std::cout << "\n\nНе властиві альтерації. ступенів: " << steps << ", півтонів: " << halftones << "\n\n"; return 10;
	}

	return quality;
}