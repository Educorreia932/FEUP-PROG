#pragma once
#ifndef REG_FUNCTIONS
#define REG_FUNCTIONS
#include "Structs.h"

void registIdentifier(std::vector <TravelPack> &StructTravelPacks);
void registClients(Agency StructAgency, std::vector <Client> StructClients);
void registTravelPacks(Agency StructAgency, std::vector <TravelPack> StructTravelPacks);

#endif //REG_FUNCTIONS