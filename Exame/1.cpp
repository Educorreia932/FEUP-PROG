#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

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

void saveToFile(vector <string> &words) { //Exercise 1.d)
	ifstream File("C:\docs\words.txt");
	string line;

	if (File.is_open()) {
		while (getline(File, line))
			decomposeLine(line, words);

		File.close();
	}
}