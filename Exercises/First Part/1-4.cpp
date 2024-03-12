#include <iostream>
using namespace std;

int main() {
	double a, b, c, d, e, f;

	cout << "Insira os valores de a, b, c, d, e e f: ";
	cin >> a >> b >> c >> d >> e >> f;

	double x = (c*e - b * f) / (a*e - b * d);
	double y = (a*f - c * d) / (a*e - b * d);

	cout << "Os valores de x e de y são, respetivamente, " << x << " e " << y;

	return 0;
}