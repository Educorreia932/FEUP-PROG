#include <iostream>

using namespace std;

int function() {
	static int canas = 2;
	canas *= 2;
	return canas;
}

int main() {
	cout << function() << function();

	return 0;
}