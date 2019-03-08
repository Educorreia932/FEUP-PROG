#include<iostream>
#include<cmath>
#include<ctime> 
using namespace std;

int main() {
	clock_t tStart = clock();
	int num;

	int counter = 0;
	int number = 1;


	while (number < 100000) {
		bool primo = true;
		number += 1;
		for (int divisor = 2; divisor <= (int)sqrt(number); divisor++) {
			if (number % divisor == 0) {
				primo = false;
				break;
			}

		}
		if (primo == true) {
			cout << "O número " << number << " é primo.\n";
			counter += 1;
			primo = false;
		}

	}

	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	return 0;
}