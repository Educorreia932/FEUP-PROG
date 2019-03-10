#include <iostream>
using namespace std;

double integrateTR(double f(double), double a, double b, int n) {
	double result,  h = (b - a) / n;

	for (int i = a; i < b; i++) {
		result += (h / 2) * (f(a + (i - 1) * h) + f(a + i * h));
	}
	
	return result;
}

int main() {
	double f(double), a, b;
	int n;

	cout << "Insert a function, the value of a and b and the number of intervals: ";
	cin >> f, a, b, n;
}