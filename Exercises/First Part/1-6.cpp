#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float x1, y1, x2, y2, x3, y3;

	cout << "Insert the coordinates of the first point: ";
	cin >> x1 >> y1;
	cout << "Insert the coordinates of the second point: ";
	cin >> x2 >> y2;
	cout << "Insert the coordinates of the third point: ";
	cin >> x3 >> y3;

	float a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	float b = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
	float c = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	float s = (a + b + c) / 2;
	float área = sqrt(s * (s - a) * (s - b) * (s - c));

	cout << "The area of the triangle is " << área << " a. u.";
}