#include"Notes.h"

int EnterNum(int max)
{
	int initial;
	do
	{
		cin >> initial;

		if (initial > max)
			title(12, "завелике число, спробуйте ще!");
	} while (initial > max);

	return initial;

}