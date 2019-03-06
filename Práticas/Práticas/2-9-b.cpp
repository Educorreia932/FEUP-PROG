#include <iostream>
using namespace std;

int main() {
	double mean, n, sum = 0.0;
	int length, lowest = 0, greatest = 0, counter = 0;
	bool first = true;

	cout << "How many numbers do you want to insert? ";
	cin >> length;
	cout << "Insert a sequence of numbers: "; //Is it supposed to write all of numbers in just a sequence?

	while (cin >> n && counter <= length) {
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