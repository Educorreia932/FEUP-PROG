#include <iostream>
using namespace std;

bool readFracc(long long &numerator, long long &denominator) {
	char slash;

	cin >> numerator >> slash >> denominator;

	if (!cin) {
		denominator, numerator = 0;
		return false;
	}

	return true;
}

void writeFracc(long long numerator, long long denominator) {
	cout << numerator << '/' << denominator;
}

void reduceFracc(long long &numerator, long long &denominator) {
	long long  r, n = numerator, m = denominator;

	while (n != 0)
	{
		r = m % n;
		m = n;
		n = r;
	}
	
	numerator = numerator / m;
	denominator = denominator / m;
}

void multiplyFracc(long long numerator1, long long denominator1, long long numerator2, long long denominator2, long long &numerator, long long &denominator) {
	numerator = numerator1 * numerator2;
	denominator = denominator1 * denominator2;
}

void addFracc(long long numerator1, long long denominator1, long long numerator2, long long denominator2, long long &numerator, long long &denominator) {
	numerator = numerator1 * denominator2 + numerator2 * denominator1;
	denominator = denominator1 * denominator2;
}

void switchOperation(char operation, long long &numerator, long long &denominator) {
	long long numerator1, denominator1, numerator2, denominator2;

	cout << "Insert the first fraction (two numbers separated by a slash): ";

	readFracc(numerator1, denominator1);
	   
	cout << "Insert the second fraction (two numbers separated by a slash): ";

	readFracc(numerator2, denominator2);

	switch (operation) {
		case '+':
			addFracc(numerator1, denominator1, numerator2, denominator2, numerator, denominator);
			break;

		case '-':
			addFracc(numerator1, denominator1, -numerator2, denominator2, numerator, denominator);
			break;

		case '*':
			multiplyFracc(numerator1, denominator1, numerator2, denominator2, numerator, denominator);
			break;
		
		case '/':
			multiplyFracc(numerator1, denominator1, denominator2, numerator2, numerator, denominator);
			break;
	}
}

void selection(long long &numerator, long long &denominator) {
	
	char operation;

	cout << "What operation do you want to do (insert +, -, * or / character)? ";
	cin >> operation;

	switchOperation(operation, numerator, denominator);
}

int main() {
	long long numerator, denominator;	

	selection(numerator, denominator);

	reduceFracc(numerator, denominator);

	cout << "The result is ";
	
	writeFracc(numerator, denominator);

	return 0;
}