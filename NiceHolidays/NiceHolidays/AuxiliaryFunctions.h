#pragma once
#ifndef AUX_FUNCTIONS
#define AUX_FUNCTIONS
#include <string>

std::string Trim(std::string s);
bool IsAvailable(int TravelPackBumber, std::vector <TravelPack> StructTravelPacks);
bool IsBefore(int Year1, int Month1, int Day1, int Year2, int Month2, int Day2);
bool IsAfter(int Year1, int Month1, int Day1, int Year2, int Month2, int Day2);

#endif //AUX_FUNCTIONS