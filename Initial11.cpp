#include"Notes.h"
Polychord Initial11(string initial, int notation)
{
	Polychord Initial;

	Initial.step[0] = key_to_step(initial, notation);
	Initial.pitch[0] = key_to_pitch(initial, notation);
	Initial.step[1] = addstep(Initial.step[0], 2);
	Initial.step[2] = addstep(Initial.step[1], 2);
	Initial.step[3] = addstep(Initial.step[2], 2);
	Initial.step[4] = addstep(Initial.step[3], 2);
	Initial.step[5] = addstep(Initial.step[4], 2);
	Initial.pitch[2] = addpitch(Initial.pitch[0], 7);
	Initial.pitch[4] = addpitch(Initial.pitch[0], 2);

	return Initial;
}