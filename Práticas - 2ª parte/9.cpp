#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

vector <string> readFile(string file_name) {
	vector <string> result;	
	string line;
	ifstream File(file_name);
	
	if (File.is_open()) {
		while (getline(File, line)) {
			string word;
			stringstream words(line);
			words >> word;
			result.push_back(word);
		}

		File.close();
	}

	return result;
}

vector <string> eliminateDuplicates(vector <string> v) {
	vector <string> result;

	sort(v.begin(), v.end());

	for (size_t i = 0; i < size(v) - 1; i++)
		if (i == 0 || v[i] != v[i - 1])
			result.push_back(v[i]);

	return result;
}

void saveFile(string file_name, vector <string> v) {
	ofstream File(file_name);

	for (size_t i = 0; i < size(v); i++) 
		File << v[i] << endl;

	File.close();
}

int main() {
	string file_name = "9.txt";

	vector <string> v = readFile(file_name);	
	v = eliminateDuplicates(v);
	saveFile(file_name, v);

	return 0;
}