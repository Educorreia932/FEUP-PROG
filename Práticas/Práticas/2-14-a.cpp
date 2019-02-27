#include <iostream>
using namespace std;

int main() {
	float delta, rqn, rqn2, dif, rq = 1;
	int nMaxIter, n, iterations = 1;

	cout << "Insert the number you want to know the squareroot of, the maximum number of iterations and a delta: ";
	cin >> n >> nMaxIter >> delta;

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

	cout << "The squareroot value of " << n << " is " << rqn << ".";

	return 0;
}