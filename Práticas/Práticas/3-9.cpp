#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
	return sqrt(4 - pow(x, 2));
}

double integrateTR(double f(double), double a, double b, int n) {
	double result = 0, h = (b - a) / n;

	for (int i = 1; i <= n; i++) {
		result += (h / 2) * (f(a + (i - 1) * h) + f(a + i * h));
	}

	return result;
}

int main() {
	double a, b;
	int n;

	cout << "Enter the a and b values and the number of intervals: ";
	cin >> a >> b >> n;
	cout << "The approximate value of the definite integral between " << a << " and " << b << " is " << integrateTR(f, a, b, n) << ".";

	return 0;
}