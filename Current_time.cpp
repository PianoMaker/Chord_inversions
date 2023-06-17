
#include <iostream>
#include <ctime>
#include <string>

using namespace std;


string get_current_time() 
{
	int Time = time(NULL);
	string time = to_string(Time);
	return time;
}