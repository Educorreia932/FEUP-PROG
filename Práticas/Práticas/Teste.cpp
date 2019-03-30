#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main() {
	string s1 = "batatata";
	string s2 = "batata";

	if (s1.find(s2) != string::npos)
		cout << "True";

	else
		cout << "False";
}