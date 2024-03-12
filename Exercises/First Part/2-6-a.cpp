#include <iostream>
#include <cmath>
using namespace std;

int wmain() {
	int número;
	bool primo = true;

	cout << "Insert the number: ";
	cin >> número;

	for (int divisor = 2; divisor <= (int)sqrt(número); divisor++) {
		if (número % divisor == 0) {
			primo = false;
			break;
		}
	}

	if (primo) {
		cout << "The number is prime";
	}

	else {
		cout << "O número é composto";
	}

	return 0;
}