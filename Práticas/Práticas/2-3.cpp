#include <iostream>
using namespace std;

int main() {
	float number1, number2, result;
	char operation;
	cout << "Insert two numbers: " << endl;
	cin >> number1, number2;
	cout << "Insert an operation (+, -, * or /): " << endl;
	cin >> operation;

	switch (operation) {
		case "+":
			result = number1 + number2;

		case "-":
			result = number1 - number2;

		case "*":
			result = number1 * number2;

		case "/":
			result = number1 / number2;
	}

	cout << "The result is " << result << "." << endl;
}