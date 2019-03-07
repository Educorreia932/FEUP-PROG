#include <iostream>
#include <string>
using namespace std;

int main() {
	int number, divisor = 2;

	cout << "Insert a number: ";
	cin >> number;
	cout << number << "=";

	do {
		if (number % divisor == 0) {
			number /= divisor;
			cout << divisor << "x";
		}

		else
			divisor += 1;
	} while (number != divisor);

	cout << number;
	
	return 0;
}