#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	const int width = 15;
	const double pi = 3.141592653589793238463;

	cout << setw(10) << "ang" << setw(width) << "sen" << setw(width) << "cos" << setw(width) << "tan" << endl;

	for (double ang = 0; ang <= 90; ang += 15) {
		if (ang == 90)
			cout << setw(width) << ang << setw(10) << sin(ang * pi / 180) << setw(width) << cos(ang * pi / 180.0) << setw(width) << "infinito" << endl;

		else
			cout << setw(width) << ang << setw(10) << sin(ang * pi / 180) << setw(width) << cos(ang * pi / 180.0) << setw(width) << tan(ang * pi / 180.0) << endl;;
	}

	return 0;
}