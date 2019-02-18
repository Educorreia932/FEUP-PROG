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

	double média = (A + B + C) / 3;
	double A_média = A - média;
	double B_média = B - média;
	double C_média = C - média;

	cout << "media   = " << média << endl //Acertar precisão
		<< "A-media = " << A_média << endl
		<< "B-media = " << B_média << endl
		<< "C-media = " << C_média;

	return 0;
}