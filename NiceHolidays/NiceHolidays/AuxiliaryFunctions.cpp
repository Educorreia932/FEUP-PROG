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