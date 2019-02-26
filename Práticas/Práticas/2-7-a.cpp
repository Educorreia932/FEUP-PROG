#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;

int main() {
	float sine, cosine, tangent;
	const float pi = 3.141592653589793238463;

	cout << setw(10) << "ang" << setw(10) << "sen" << setw(10) << "cos" << setw(10) << "tan" << endl;

	for (int ang = 0; ang <= 90; ang += 15) {
		cout << setw(10) << ang << setw(10) << sin(ang * pi / 180.0) << setw(10) << cos(ang * pi / 180.0) << setw(10) << tan(ang * pi / 180.0) << endl;
 	}

	return 0;
}