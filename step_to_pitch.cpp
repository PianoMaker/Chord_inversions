/// ВПЛИВ ЗНАКІВ АЛЬТЕРАЦІЇ НА ВИСОТУ ЗВУКА


enum NOTES { DO, RE, MI, FA, SOL, LA, SI };

int step_to_pitch(int step, int alteration)
{
	int pitch;
	do
	{
		if (step > 6) step -= 7;
	} while (step > 6);

	if (step == DO)
	{
		pitch = 0;
	}
	else if (step == RE)
	{
		pitch = 2;
	}
	else if (step == MI)
	{
		pitch = 4;
	}
	else if (step == FA)
	{
		pitch = 5;
	}
	else if (step == SOL)
	{
		pitch = 7;
	}
	else if (step == LA)
	{
		pitch = 9;
	}
	else if (step == SI)
	{
		pitch = 11;
	}
	else pitch = -100;

	pitch = pitch + alteration;


	return pitch;

}