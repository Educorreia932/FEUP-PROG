#include <iostream>
using namespace std;

int main() {
	double a, b, c, d, e, f;

	cout << "Insira os valores de a, b, c, d, e e f: ";
	cin >> a >> b >> c >> d >> e >> f;

	if (a * e - b * d == 0) {
		cout << "Sistema indeterminado";
		return 0;
	}

	double x = (c*e - b * f) / (a * e - b * d);
	double y = (a*f - c * d) / (a * e - b * d);

	if (a * x + b * y == d * x + e * y && c != f) {
		cout << "Sistema impossível";
		return 0;
	}

	cout << "Os valores de x e de y são, respetivamente, " << x << " e " << y;

	return 0;
}