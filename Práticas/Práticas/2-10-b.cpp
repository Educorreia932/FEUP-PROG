#include <iostream>
#include <cmath>
using namespace std;

int main() {
	unsigned long long int n, first, last, length = 1, divider = 1;
	bool palindrome = true;
	
	cout << "Insert a number: ";
	cin >> n;

	unsigned long long int nCopy = n;

	while (nCopy /= 10) {
		length++;
	}

	while (length > 1) {
		first = n / pow(10, length - 1); 
		last = n % 10; 

		cout << first << ' ' << last << endl;
		
		if (first != last) {
			palindrome = false;
			break;
		}

		n -=  first * pow(10, length - 1);
		n /= 10;
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