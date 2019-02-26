#include <iostream>
using namespace std;

int main() {
	float weight;
	float cost;

	cout << "Insert the weight (in grams)";
	cin >> weight;
	
	if (weight < 500) {
		cost = 5;
	}

	else if (weight >= 500 && weight <= 1000) {
		weight -= 500;
		custo = 5 + 1.5 * ((peso - 500) / 100) //Fazer ciclo for
	}
}