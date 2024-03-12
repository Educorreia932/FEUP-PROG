#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, denominator = 1;
	float result = 0;

	cout << "Insert the number of terms: ";
	cin >> n;

	for (int iteration = 0; iteration <= n; iteration ++) {
		result += pow(-1, iteration) * 4.0 / denominator;
		denominator += 2;
	}

	cout << "The value of pi is " << result;
	return 0;
}