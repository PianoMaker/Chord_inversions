#include <iostream>;

int pitchdiff(int low_pitch, int high_pitch)
{
	if (low_pitch > high_pitch) high_pitch += 12;
	//cout << "\nhigh_pitch - low_pitch: " << high_pitch << " - " << low_pitch;
	int halftones = high_pitch - low_pitch;
	return halftones;
}