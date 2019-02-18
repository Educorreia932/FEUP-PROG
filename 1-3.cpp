#include <iostream>
using namespace std;

int main() {
	double M;
	double p;
	double r;
	double pi = 3.14159;

	cout << "Introduza o valor de p (em Kg/m3): "; //"³" desconfigura
	cin >> p;
	cout << "Introduza o valor de r (em m): ";
	cin >> r;
	cout << "O valor de M (em Kg) e " << 4 / 3 * (p*pi*r*r*r * 3); //Acento desconfigura

	return 0;
}