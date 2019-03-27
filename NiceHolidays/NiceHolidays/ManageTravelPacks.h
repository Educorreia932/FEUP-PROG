#pragma once
#ifndef MAN_TRAVELPACKS
#define MAN_TRAVELPACKS
#include "Structs.h"

TravelPack createTravelPack(std::vector <TravelPack> &StructTravelPacks);
void changeTravelPack(int TravelPackNumber, std::vector <TravelPack> &StructTravelPacks);
void removeTravelPack(int TravelPackNumber, std::vector <TravelPack> &StructTravelPacks);
void manageTravelPacks(std::vector <TravelPack> &StructTravelPacks);

#endif //MAN_TRAVELPACKS
