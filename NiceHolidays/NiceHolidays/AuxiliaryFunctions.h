#pragma once
#ifndef AUX_FUNCTIONS
#define AUX_FUNCTIONS
#include <string>

std::string Trim(std::string s);
std::vector <int> GetAdquiredTravelPacks(std::string Line);
std::vector <std::string> GetTravelDestination(std::string Line);

#endif //AUX_FUNCTIONS