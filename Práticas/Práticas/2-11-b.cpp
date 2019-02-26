#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, denominator = 1;
	float term = 1, result = 1;

	cout << "Insert the number of terms: ";
	cin >> n;

	for (int iteration = 1; iteration <= n; iteration++) {
		term = 1 * term / iteration;
		result += term;
		denominator += 2;
	}

	cout << "The value of e is " << result;
	return 0;
}