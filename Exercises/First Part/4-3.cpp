#include <iostream>
#include <string>
using namespace std;

void decompose(string compound) {
	for (int i = 0; i < compound.length(); i++) {
		if (islower(compound[i + 1])) {
			cout << compound[i];
		}
		
		else if (!isdigit(compound[i])) {
			cout << compound[i] << " ";
		}	
	}
}

int main() {
	string compound;

	cout << "Insert a compound: ";
	cin >> compound;
	cout << compound << " is constituted by the elements: ";
	decompose(compound);

	return 0;
}