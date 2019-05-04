#include "Auxiliary.h"

string trim(string s) {
	s.erase(0, s.find_first_not_of(' ')); //Removes spaces to the left

	if (s[s.length() - 1] == ' ')
		s.erase(s.find_last_of(' ')); //Removes spaces to the right

	return s;
}

vector<int> str_to_PackageIds(string line) {

	vector<int> packageIds;
	istringstream s(line);
	int aux;
	char c;
	
	while (s >> aux) {
		packageIds.push_back(aux);
		s >> c;
	}

	return packageIds;
}


string readName(string message) {

	string input;
	bool validInput = true;

	do {
		validInput = true;
		cout << message;
		//cin.ignore(1000, '\n');
		getline(cin, input);
		for (size_t i = 0; i < input.length(); i++) {
			if (isdigit(input.at(i)))
				validInput = false;
		}

	} while (!validInput);

	return input;

}