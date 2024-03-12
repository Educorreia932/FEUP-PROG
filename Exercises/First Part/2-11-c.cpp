#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, denominator = 1;
	float x, term = 1, result = 1;

	cout << "Insert the number of terms: ";
	cin >> n;
	cout << "Insert the value of x: ";
	cin >> x;

	for (int iteration = 1; iteration <= n; iteration++) {
		term = pow(-1, iteration) * x * term / iteration;
		result += term;
	}

	cout << "The value of e is " << result;
	return 0;
}