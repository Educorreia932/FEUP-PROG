#pragma once
#include <string>
using namespace std;

string Trim(string s) {
	s.erase(0, s.find_first_not_of(' ')); //Removes spaces to the left

	if (s[s.length() - 1] == ' ')
		s.erase(s.find_last_of(' ') + 1); //Removes spaces to the right

	return s;
}