#include <iostream>
#include <string>
using namespace std;

bool sequenceSearch(string s, int nc, char c) {
	int counter = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == c) {
			counter += 1;

			if (counter == nc) 
				return true;
		}

		else
			counter = 0;
	}

	return false;
}

int main() {
	string inputS;
	int inputNC;
	char inputC;

	cout << "Insert a string, the number of consecutives characters and a character: ";
	cin >> inputS >> inputNC >> inputC;
	cout << sequenceSearch(inputS, inputNC, inputC);

	return 0;
}