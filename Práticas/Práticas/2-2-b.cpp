#include <iostream>
using namespace std;

int main() {
	float a, b, c, first, second, third;

	cout << "Insert three numbers: ";
	cin >> a >> b >> c;

	if (a > b and a > c) {
		first = a;

		if (b < c) {
			third = b;
			second = c;
		}

		else {
			third = c;
			second = b;
		}
	}

	else if (b > a and b > c) {
		first = b;

		if (a < c) {
			third = a;
		}

		else {
			third = c;
		}
	}

	else {
		first = c;

		if (a < b) {
			third = a;
			second = b;
		}

		else {
			third = b;
			second = a;
		}
	}

	cout << first << " " << second << " " << third;
	return 0;
}