#include <iostream>
using namespace std;

int main() {
	double A = 0;
	double B = 0;
	double C = 0;

	cout << "A ? ";
	cin >> A;
	cout << "B ? ";
	cin >> B;
	cout << "C ? ";
	cin >> C;

	double m�dia = (A + B + C) / 3;
	double A_m�dia = A - m�dia;
	double B_m�dia = B - m�dia;
	double C_m�dia = C - m�dia;

	cout << "media   = " << m�dia << endl //Acertar precis�o
		<< "A-media = " << A_m�dia << endl
		<< "B-media = " << B_m�dia << endl
		<< "C-media = " << C_m�dia;

	return 0;
}