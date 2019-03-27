#pragma once
#ifndef AUX_FUNCTIONS
#define AUX_FUNCTIONS
#include <string>

std::string trim(std::string s);
bool isAvailable(int TravelPackBumber, std::vector <TravelPack> StructTravelPacks);
bool isBefore(int Year1, int Month1, int Day1, int Year2, int Month2, int Day2);
bool isAfter(int Year1, int Month1, int Day1, int Year2, int Month2, int Day2);
bool isBissextile(int year);
int numberOfDays(int month, int year);

#endif //AUX_FUNCTIONS