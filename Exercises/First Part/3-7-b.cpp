#include <iostream>
using namespace std;

long factorial_rec(int n) {
	if (n == 1)
		return 1;

	else
		return n * factorial_rec(n - 1);
}

int main() {
	int n;

	cout << "Insert a number (must be lower than 12): ";
	cin >> n;
	cout << n << "! = " << factorial_rec(n);

	return 0;
}