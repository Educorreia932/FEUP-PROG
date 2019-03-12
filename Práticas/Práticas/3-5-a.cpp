#include <iostream>
using namespace std;

bool readFracc(int &numerator, int &denominator) {
	char slash;	

	cin >> numerator >> slash >> denominator;

	if (!cin) {
		denominator, numerator = 0;
		return false;
	}

	return true;
}