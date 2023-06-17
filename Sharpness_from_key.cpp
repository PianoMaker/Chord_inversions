#include"Notes.h"
int Sharpness_from_key(string key, int notation=1)
{
 return Sharpness(key_to_step(key, notation), alteration_counter(key, notation));
}