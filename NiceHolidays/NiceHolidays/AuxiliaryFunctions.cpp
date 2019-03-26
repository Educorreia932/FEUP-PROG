#include <string>
#include <vector>
#include "Structs.h"
#include "AuxiliaryFunctions.h"

std::string Trim(std::string s) {
	s.erase(0, s.find_first_not_of(' ')); //Removes spaces to the left

	if (s[s.length() - 1] == ' ')
		s.erase(s.find_last_of(' ')); //Removes spaces to the right

	return s;
}

bool IsAvailable(int TravelPackBumber, std::vector <TravelPack> StructTravelPacks) {
	if (StructTravelPacks[TravelPackBumber].Identifier > 0)
		return true;

	else
		return false;
}

bool IsBefore(int Year1, int Month1, int Day1, int Year2, int Month2, int Day2) {
	if (Year1 < Year2)
		return true;

	else if (Year1 == Year2 && Month1 < Month2)
		return true;

	else if (Year1 == Year2 && Month1 == Month2 && Day1 < Day2)
		return true;

	else
		return false;
}

bool IsAfter(int Year1, int Month1, int Day1, int Year2, int Month2, int Day2) {
	if (Year1 > Year2)
		return true;

	else if (Year1 == Year2 && Month1 > Month2)
		return true;

	else if (Year1 == Year2 && Month1 == Month2 && Day1 > Day2)
		return true;

	else
		return false;
}