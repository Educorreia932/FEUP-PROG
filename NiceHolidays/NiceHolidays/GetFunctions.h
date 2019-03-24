#pragma once
#ifndef GET_FUNCTIONS
#define GET_FUNCTIONS
#include "Structs.h"

std::vector <int> GetAdquiredTravelPacks(std::string Line);
std::vector <std::string> GetTravelDestination(std::string Line);
void GetAddress(Address &Address, std::string Line);
void GetDate(Date &Date, std::string Line);

#endif //GET_FUNCTIONS
