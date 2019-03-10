#include <iostream>
using namespace std;

long factorial_ite(int n) {
	long result = 1;

	for (int i = n; i > 1; i--) {
		result *= i;
	}

	return result;
}

int main() {
	int n;

	cout << "Insert a number (must be lower than 12): ";
	cin >> n;
	cout << n << "! = " << factorial_ite(n);
	
	return 0;
}