#pragma once
#ifndef MAN_TRAVELPACKS
#define MAN_TRAVELPACKS
#include "Structs.h"

TravelPack CreateTravelPack(std::vector <TravelPack> &StructTravelPacks);
void ChangeTravelPack(int TravelPackNumber, std::vector <TravelPack> &StructTravelPacks);
void RemoveTravelPack(int TravelPackNumber, std::vector <TravelPack> &StructTravelPacks);
void ManageTravelPacks(std::vector <TravelPack> &StructTravelPacks);

#endif //MAN_TRAVELPACKS
