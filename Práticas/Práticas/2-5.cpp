#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	float a, b, c;
	
	cout << "Insert the coefficients (a b c): ";
	cin >> a >> b >> c;

	if (pow(b, 2) - 4 * a * c < 0) {
		cout << "The equations has two conjugated complex solutions " << setprecision(4) << -b/(2 * a) << " + " << sqrt(-(pow(b, 2) - 4 * a * c)) / (2 * a) << "i and " 
			 << -b / (2 * a) << " - " << sqrt(-(pow(b, 2) - 4 * a * c)) / (2 * a) << "i";
	}

	else {
		float solution1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		float solution2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		
		cout << "The equation has two different real solutions " << solution1 << " and " << solution2;
	}

	return 0;
}