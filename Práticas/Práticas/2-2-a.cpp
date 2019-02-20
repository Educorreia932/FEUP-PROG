#include <iostream>
using namespace std;

int main () {
	float a, b, c, greatest, lowest;
	cout << "Insert three numbers: ";
	cin >> a >> b >> c;

	if (a > b && a > c) {
		greatest = a;
		
		if (b < c) {
			lowest = b;
		}

		else {
			lowest = c;
		}
	}

	else if (b > a && b > c) {
		greatest = b;

		if (a < c) {
			lowest = a;
		}

		else {
			lowest = c;
		}
	}

	else {
		greatest = c;

		if (a < b) {
			lowest = a;
		}

		else {
			lowest = b;
		}
	}

	cout << "The greatest number is " << greatest << " and the lowest is " << lowest << ".";
    return 0;
}