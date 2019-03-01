#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, first, last, length = 1, divider = 1;
	bool palindrome = true;
	
	cout << "Insert a number: ";
	cin >> n;

	while (n /= 10) {
		length++;
	}

	cout << n << " " <<length << endl;

	while (length > 1) {
		first = n / pow(10, length - 1); // 1000
		last = n % 10; //10
		
		cout << first << " " << last << endl;
		
		if (first != last) {
			palindrome = false;
			break;
		}

		cout << ((int)pow(10, length - 1)) << endl;
		n = n % ((int) pow(10, length - 1));
		cout << n << endl;
		n = n / 10;
		cout << n << endl;

		length -= 2;

		if (length == 0) {
			break;
		}
	}

	if (palindrome) {
		cout << "The number is palindromic.";
	}

	else {
		cout << "The number is not palindromic.";
	}

	return 0;
}