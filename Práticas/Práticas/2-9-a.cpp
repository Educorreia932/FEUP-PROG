#include <iostream>
using namespace std;

int main() {
	double mean;
	int n, lowest = 0, greatest = 0, sum = 0, counter = 0;

	while (cin >> n && n != 0) {
		if (n > greatest) {
			greatest = n;
		}

		if (n < lowest) { //Concertar
			lowest = n;
		}

		counter += 1;
		sum += n;
		mean = sum / counter;
	}
		
	cout << "The sum of the numbers is " << sum << ", the mean is " << mean << ", the greatest one is " << greatest << " and the lowest is " << lowest << ".";

	return 0;
}