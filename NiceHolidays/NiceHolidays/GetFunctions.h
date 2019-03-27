#pragma once
#ifndef GET_FUNCTIONS
#define GET_FUNCTIONS
#include "Structs.h"

std::vector <int> getAdquiredTravelPacks(std::string Line);
std::vector <std::string> getTravelDestination(std::string Line);
void getAddress(Address &Address, std::string Line);
void getDate(Date &Date, std::string Line);

#endif //GET_FUNCTIONS