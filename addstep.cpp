
// обчислює ступінь після додаання заданого інтервалу (в ступенях)
#include <iostream>;
int addstep(int step1, int step2)
{
	int step = step1 + step2;
	if (step < 0) step += 7;
	if (step > 6) step -= 7;
	return step;
}