#include <iostream>
#include <cmath>
using namespace std;

int wmain() {
	int n�mero;
	bool primo = true;

	cout << "Insert the number: ";
	cin >> n�mero;

	for (int divisor = 2; divisor <= (int)sqrt(n�mero); divisor++) {
		if (n�mero % divisor == 0) {
			primo = false;
			break;
		}
	}

	if (primo) {
		cout << "The number is prime";
	}

	else {
		cout << "O n�mero � composto";
	}

	return 0;
}