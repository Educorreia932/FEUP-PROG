#include <iostream>
using namespace std;

int main() {
	float number1, number2, result;
	char operation;
	cout << "Insert two numbers: ";
	cin >> number1 >> number2;
	cout << "Insert an operation (+, -, * or /): ";
	cin >> operation;

	switch (operation) {
		case '+':
			result = number1 + number2;
			break;

		case '-':
			result = number1 - number2;
			break;

		case '*':
			result = number1 * number2;
			break;

		case '/':
			result = number1 / number2;
			break;
	}

	cout << "The result is " << result << "." << endl;
}