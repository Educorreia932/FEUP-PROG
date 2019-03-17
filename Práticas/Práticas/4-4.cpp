#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string normalizeName(string name) {
	int length = name.length(), counter = 0;
	string resultArray[50], word, resultString = "";

	for (int i = 0; i <= length; i++) {
		if (isalpha(name[i]))
			word += toupper(name[i]);

		else if ((name[i] == ' ' && isalpha(name[i - 1]) && i > 0)) {
			word += ' ';
			resultArray[counter] = word;
			word = "";
			counter += 1;
		}
	}

	word += ' ';
	resultArray[counter] = word;
	word = "";
	counter += 1;
	
	for (int i = 0; i < 50; i++) {
		if (resultArray[i].compare("DE ") == 0 || resultArray[i].compare("DO ") == 0 || resultArray[i].compare("DA ") == 0 ||
			resultArray[i].compare("DAS ") == 0 || resultArray[i].compare("DOS ") == 0 || resultArray[i].compare("E ") == 0)
			;

		else
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