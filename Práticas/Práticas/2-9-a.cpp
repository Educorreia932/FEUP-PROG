#include <iostream>
using namespace std;

int main() {
	double mean, n, sum = 0.0;
	int lowest = 0, greatest = 0, counter = 0;
	bool first = true;

	cout << "Insert a sequence of numbers (ending it with 0): ";

	while (cin >> n && n != 0) {
		if (first) {
			lowest = n;
			greatest = n;
			first = false;
		}

		else if (n > greatest) {
			greatest = n;
		}

		else if (n < lowest) { 
			lowest = n;
		}

		counter += 1;
		sum += n;
		mean = sum / counter;
	}
		
	cout << "The sum of the numbers is " << sum << ", the mean is " << mean << ", the greatest one is " << greatest << " and the lowest is " << lowest << ".";

	return 0;
}