#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	float a, b, c;
	
	cout << "Insert the coefficients (a b c): ";
	cin >> a >> b >> c;

	if (pow(b, 2) - 4 * a * c < 0) {
		cout << "The equations has two conjugated complex solutions " << setprecision(3) << -b/a << " - " << sqrt(-(pow(b, 2) - 4 * a * c))/a << "i and " 
			 << -b << " + " << sqrt(-(pow(b, 2) - 4 * a * c)) << "i";
	}

	else {
		float solution1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / a;
		float solution2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / a;
		
		cout << "The equation has two different real solutions " << solution1 << " and " << solution2;
	}

	return 0;
}