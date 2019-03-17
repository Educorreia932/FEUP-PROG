#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//WIP

string normalizeName(string name) {
	int length = name.length(), counter = 0;
	string resultArray[50];
	string word, resultString = "";

	for (int i = 0; i <= length; i++) {
		if (name[i - 1] != ' ' && name[i] != ' ') {
			if (name[i - 1] == ' ')
				word += ' ';

			word += toupper(name[i]);

			if (name[i] == ' ' || name[i] == '\0') {
				resultArray[counter] = word;
				counter = 0;
			}
		}
	}

	for (int i = 0; i < 50; i++) {
		resultString += resultArray[i];
	}

	return resultString;
}

int main() {
	string name;

	cout << "Insert a name: ";
	getline(cin, name);
	cout << normalizeName(name);

	return 0;
}