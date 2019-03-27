#include <string>
#include <vector>
#include "Structs.h"
#include "AuxiliaryFunctions.h"

std::string trim(std::string s) {
	s.erase(0, s.find_first_not_of(' ')); //Removes spaces to the left

	if (s[s.length() - 1] == ' ')
		s.erase(s.find_last_of(' ')); //Removes spaces to the right

	return s;
}

bool isAvailable(int TravelPackBumber, std::vector <TravelPack> StructTravelPacks) {
	if (StructTravelPacks[TravelPackBumber].Identifier > 0)
		return true;

	else
		return false;
}

bool isBefore(int Year1, int Month1, int Day1, int Year2, int Month2, int Day2) {
	if (Year1 < Year2)
		return true;

	else if (Year1 == Year2 && Month1 < Month2)
		return true;

	else if (Year1 == Year2 && Month1 == Month2 && Day1 < Day2)
		return true;

	else
		return false;
}

bool isAfter(int Year1, int Month1, int Day1, int Year2, int Month2, int Day2) {
	if (Year1 > Year2)
		return true;

	else if (Year1 == Year2 && Month1 > Month2)
		return true;

	else if (Year1 == Year2 && Month1 == Month2 && Day1 > Day2)
		return true;

	else
		return false;
}

bool isBissextile(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;

	else
		return false;
}

int numberOfDays(int month, int year) {
	switch (month) {
		case 2:
			if (isBissextile(year))
				return 29;
			else
				return 28;
		case 4:
			return 30;
		case 6:
			return 30;
		case 9:
			return 30;
		case 11:
			return 30;
		default:
			return 31;
	}
}