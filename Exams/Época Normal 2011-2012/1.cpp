#include <iostream>
#include <string>
#include <map>

using namespace std;

string cardRankToSymbola(unsigned int rank) { //Exercise 1.b) (First Part)
	string names[] = {" A"," 2"," 3"," 4"," 5"," 6"," 7"," 8"," 9","10"," J"," Q"," K"};

	if (1 <= rank && rank <= 13)
		return names[rank - 1];

	else
		return "Invalid card";
}

string cardRankToSymbol(unsigned int rank) { //Exercise 1.b) (Second Part)
	map<unsigned int, string> names; 
	
	names.insert(pair<int, string>(1, " A"));
	names.insert(pair<int, string>(2, " 2"));
	names.insert(pair<int, string>(3, " 3"));
	names.insert(pair<int, string>(4, " 4"));
	names.insert(pair<int, string>(5, " 5"));
	names.insert(pair<int, string>(6, " 6"));
	names.insert(pair<int, string>(7, " 7"));
	names.insert(pair<int, string>(8, " 8"));
	names.insert(pair<int, string>(9, " 9"));
	names.insert(pair<int, string>(10, " 10"));
	names.insert(pair<int, string>(11, " J"));
	names.insert(pair<int, string>(12, " Q"));
	names.insert(pair<int, string>(13, " K"));

	if (!names[rank].empty())
		return names[rank];

	else
		return "Invalid card";
}

template <class T>
T absolute(T number) {
	if (number < 0)
		return -number;

	else
		return number;
}

int main() { //Just to test
	int a = -3;
	float b = -4.0;
	double c = -5.121;

	cout << absolute(c);
}