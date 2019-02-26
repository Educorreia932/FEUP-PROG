#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float a, b, c;

	
	cout << "Insert the  (a b c): ";
	cin >> a >> b >> c;

	float solution1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / a;
	float solution2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / a;

	cout << "The equation has  " << solução1 << " e " << solução2;
}