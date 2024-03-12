#include <iostream>
using namespace std;

int main() {
	float weight;
	float cost;

	cout << "Insert the weight (in grams): ";
	cin >> weight;
	
	if (weight < 500) {
		cost = 5;
	}

	else if (weight >= 500 && weight <= 1000) {
		cost = 5 + (int)(weight / 100) * 1.5;
		weight -= (int)(weight / 100) * 100;
		
		if (weight != 0) {
			cost += 1.5;
		}

	}

	else if (weight > 1000) {
		cost = 12.5 + (int)(weight / 250) * 5;
		weight -= (int)(weight / 250) * 1000;
	}

	cout << "The cost is " << cost;
}