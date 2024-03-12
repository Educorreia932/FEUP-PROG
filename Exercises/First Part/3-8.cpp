#include <iostream>
using namespace std;

int gdc(int m, int n) {
	if (m % n == 0)
		return n;

	else
		return gdc(n, m % n);
}

int main() {
	int number1, number2;

	cout << "Insert two numbers: ";
	cin >> number1 >> number2;
	cout << "The greatest common divisor between " << number1 << " and " << number2 << " is " << gdc(number1, number2) << ".";
	return 0;
}