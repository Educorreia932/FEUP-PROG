#include <string>
#include <vector>
#include "AuxiliaryFunctions.h"

std::string Trim(std::string s) {
	s.erase(0, s.find_first_not_of(' ')); //Removes spaces to the left

	if (s[s.length() - 1] == ' ')
		s.erase(s.find_last_of(' ')); //Removes spaces to the right

	return s;
}

std::vector <int> GetAdquiredTravelPacks(std::string Line) {
	std::vector <int> Result;
	std::string AuxString;

	for (int i = 0; i < Line.length(); i++) {
		if (Line[i] == ';') {
			Result.push_back(stoi(AuxString));
			AuxString = "";
		}

		else
			AuxString += Line[i];
	}

	Result.push_back(stoi(AuxString));

	return Result;
}

std::vector <std::string> GetTravelDestination(std::string Line) {
	std::vector <std::string> Result;
	std::string AuxString;

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