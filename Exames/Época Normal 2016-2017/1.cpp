#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

void simplify(const string &name, string &sName) { //Exercise 1.b)
	stringstream s;
	vector <string> names;
	string aux;

	s << name;

	int i = 0;

	while (s >> aux) {
		names.push_back(aux);
		i++;
	}		

	if (size(names) > 1)
		sName = names[0] + " " + names[size(names) - 1];

	else
		sName = names[0];
}

int main() { //Exercise 1.a)
	ifstream File1("people1.txt");

	if (File1) {
		string line;
		vector<string> sNames;

		if (File1.is_open()) {			
			while (getline(File1, line)) {
				simplify(line, line);
				sNames.push_back(line);
			}				

			File1.close();
		}

		ofstream File2("people2.txt");

		if (File2.is_open())
			for (int i = 0; i < size(sNames); i++)
				File2 << sNames[i] << endl;
	}

	else {
		cerr << "people1.txt not found";

		return 1;
	}
}