#pragma once
#include <string>
using namespace std;

string Trim(string s) {
	s.erase(0, s.find_first_not_of(' ')); //Removes spaces to the left

	if (s[s.length() - 1] == ' ')
		s.erase(s.find_last_of(' ')); //Removes spaces to the right

	return s;
}

vector <int> GetAdquiredTravelPacks(string Line) {
	vector <int> Result;
	string AuxString;

	for (int i = 0; i < Line.length(); i++) {
		if (Line[i] == ';') {
			Result.push_back(stoi(AuxString));
			AuxString = "";
		}

		else
			AuxString += Line[i];
	}

	return Result;
}

vector <string> GetTravelDestination(string Line) {
	vector <string> Result;
	string AuxString;

	for (int i = 0; i < Line.length(); i++) {
		if (Line[i] == '–' || Line[i] == ',' || Line[i] == '-') {
			Result.push_back(Trim(AuxString));
			AuxString = "";
		}

		else {
			AuxString += Line[i];
		}
	}

	Result.push_back(Trim(AuxString));

	return Result;
}