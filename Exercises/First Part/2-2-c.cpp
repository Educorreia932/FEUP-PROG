#include <iostream>
using namespace std;

int main() {
	double a, b, c;
	cout << "Insert the length of the three sides: ";
	cin >> a >> b >> c;
	
	if (a + b < c) {
		cout << "It's impossible to build the triangle.";
	}

	else if (a + c < b) {
		cout << "It's impossible to build the triangle.";
	}

	else if (c + b < a) {
		cout << "It's impossible to build the triangle.";
	}

	else {
		cout << "It's possible to build the triangle.";
	}

	return 0;
}