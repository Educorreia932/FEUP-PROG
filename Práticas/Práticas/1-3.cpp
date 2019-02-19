#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float p;
	float r;
	float pi = 3.14159;

	cout << "Introduza o valor de p (em Kg/m3): "; 
	cin >> p;
	cout << "Introduza o valor de r (em m): ";
	cin >> r;
	cout << "O valor de M (em Kg) e " << (4 * (pi * p * pow(r, 3))) / 3;

	return 0;
}