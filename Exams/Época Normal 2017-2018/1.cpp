#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm> 

using namespace std;

void toUpperStr(string& s) { //Exercise 1.a)
	for (int i = 0; i < s.length(); i++)
		s[i] = toupper(s[i]);
}

string transformLine(string s) { //Exercise 1.b)
	for (int i = 0; i < s.length(); i++)
		if (!isalpha(s[i]))
			s[i] = ' ';

	toUpperStr(s);

	return s;
}

void decomposeLine(string& line, vector <string> &words) { //Exercise 1.c)
	string aux;
	stringstream result;
	
	line = transformLine(line);

	result << line;

	while (result >> aux)
		words.push_back(aux);
}

void saveToFile() { //Exercise 1.d)
	ifstream File1("C:\\docs\\text.txt");
	ofstream File2("C:\\docs\\words.txt");
	vector <string> words;
	string line;

	if (File1.is_open()) {
		while (getline(File1, line))
			decomposeLine(line, words);

		File1.close();
	} 

	sort(words.begin(), words.end());

	if (File2.is_open()) {
		for (int i = 0; i < size(words); i++)
			File2 << words[i] << endl;

		File2.close();
	}
}

void decomposeLineRepeated(string& line, vector <string>& words) { //Exercise 1.e)
	string aux;
	stringstream result;

	line = transformLine(line);

	result << line;

	while (result >> aux) {
		bool repeated = false;

		for (int i = 0; i < size(words); i++)
			if (words[i] == aux) {
				repeated = true;
				break;
			}
				
		if (!repeated)
			words.push_back(aux);
	}
}