#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double delta, rqn, rqn2, dif, csqrt, error, rq = 1;
	int nMaxIter, n, precision = 0, iterations = 1;

	cout << "Insert the number you want to know the squareroot of, the maximum number of iterations and a delta: ";
	cin >> n >> nMaxIter >> delta;

	csqrt = sqrt(n);

	do {
		rqn = (rq + n / rq) / 2;
		rqn2 = rqn * rqn;
		dif = n - rqn2;

		if (dif < 0) {
			dif = -dif;
		}

		rq = rqn;
		iterations += 1;
	} while (iterations < nMaxIter && dif > delta);

	while (delta < 1) {
		precision += 1;
		delta *= 10;
	}

	error = ((rq - csqrt) / csqrt) * 100;

	cout << "The estimated squareroot value of " << n << " is " << fixed << setprecision(precision) << rqn << " with an error margin of " << error << "%.";

	return 0;
}