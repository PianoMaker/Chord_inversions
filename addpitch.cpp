// обчислює висоту звуку після додаання заданого інтервалу (в півнтоах)
#include <iostream>;
int addpitch(int pitch1, int pitch2)
{
	int pitch = pitch1 + pitch2;
	if (pitch < 0) pitch += 12;
	if (pitch > 11) pitch -= 12;
	return pitch;
}