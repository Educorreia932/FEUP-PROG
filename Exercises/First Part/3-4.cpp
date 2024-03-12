#include <iostream>
#include <cmath>
using namespace std;

double round(double x, unsigned n) {
	return floor(x * pow(10, n) + 0.5) / pow(10, n);
}	

int main() {
	double number;
	int precision;

	cout << "Insert a number and a precision: ";
	cin >> number >> precision;
	cout << "The rounded value of the number is " << round(number, precision);

	return 0;
}