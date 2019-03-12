#include <iostream>
using namespace std;

double rq(int n, int nMaxIter, double delta) {
	double rqn, rqn2, dif, rq = 1;	
	int iterations = 1;
		
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

	return rqn;
}

int main() {
	int n, nMaxIter;
	double delta;

	cout << "Insert the number you want to know the squareroot of, the maximum number of iterations and a delta: ";
	cin >> n >> nMaxIter >> delta;
	cout << "The squareroot value of " << n << " is " << rq(n, nMaxIter, delta) << ".";

	return 0;
}