#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	srand(time(NULL));

	int number1 = rand() % (9 - 2 + 1) + 2, number2 = rand() % (9 - 2 + 1) + 2, guess;	

	cout << "What is the result of " << number1 << " * " << number2 << "?" << endl;
	
	time_t begin = time(0);

	cin >> guess;

	time_t end = time(0);

	time_t interval = end - begin;

	if (guess != number1 * number2) {
		cout << "Muito Mau";
	}

	else if (interval < 5) {
		cout << "Bom";
	}

	else if (interval >= 5 && interval <= 10) {
		cout << "Satisfaz";
	}

	else {
		cout << "Insuficiente";
	}

	return 0;
}