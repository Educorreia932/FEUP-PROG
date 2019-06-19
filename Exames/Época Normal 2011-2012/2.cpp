#include <iostream> //Exercise 2.e)
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string DICTIONARY_FILENAME = "dictionary.txt"; // ficheiro que contém as palavras do dicionário

bool match(string pattern, string word) { // Exercise 2.d)
	if (pattern.size() != word.size())
		return false;

	else
		for (int i = 0; i < pattern.size(); i++)
			if (pattern[i] != '.' && tolower(pattern[i]) != word[i])
				return false;

	return true;
}

int main() {
	string word;
	string pattern;
	vector<string> dictionary;
	
	//Exercise 2.a)
	string line;
	ifstream File(DICTIONARY_FILENAME);

	if (File.fail()) {
		cerr << "Could not open file.";

		return 1;
	}

	//Exercise 2.b)
	else if (File.is_open()) { 
		while (getline(File, line))
			dictionary.push_back(line);

		File.close();
	}

	cout << endl << "Dictionary size = " << dictionary.size() << endl << endl;

	//ler repetidamente um padrão e tentar encontrar palavras que verificam o padrão
	cout << "Pattern (letters and dots)? ";

	while (cin >> pattern) {
		int numMatches = 0;

		for (size_t i = 0; i < dictionary.size(); i++)
			if (match(pattern, dictionary[i])) {
				cout << "Found: " << dictionary[i] << endl;
				numMatches++;
			}

		cout << "Number of matches = " << numMatches << endl << endl;
		cout << "Pattern (letters and dots)? ";
	}

	return 0;
}