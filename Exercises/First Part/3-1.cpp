#include <iostream>
#include <cmath>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
};

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
	double a = distance(x1, y1, x2, y2), b = distance(x2, y2, x3, y3), c = distance(x1, y1, x3, y3), s = (a + b + c) / 2;
	
	return sqrt(s * (s - a) * (s - b) * (s - c));
};

int main() {
	double x1, x2, x3, y1, y2, y3;

	cout << "Insert the coordinates of the first point: ";
	cin >> x1 >> y1;
	cout << "Insert the coordinates of the second point: ";
	cin >> x2 >> y2;
	cout << "Insert the coordinates of the third point: ";
	cin >> x3 >> y3;

	cout << "The area of the triangle is " << area(x1, y1, x2, y2, x3, y3);

	return 0;
}