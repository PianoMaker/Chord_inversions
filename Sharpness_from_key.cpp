#include"Notes.h"
int Sharpness_from_key(string key, bool notation=1)
{
 return Sharpness(Key_to_step(key, notation), alteration_counter(key, notation));
}