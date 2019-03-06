#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number) {
	for (int i = 0; i <= (int)pow(number, 0.5); i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}

int main() {
	int n;

	cout << "Insert a number: ";
	cin >> n;

	if (isPrime(n)) {
		cout << "The number is prime.";
	}

	else
		cout << "The number is not prime.";

	return 0;
}