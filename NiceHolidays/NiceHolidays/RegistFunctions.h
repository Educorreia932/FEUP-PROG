#pragma once
#ifndef REG_FUNCTIONS
#define REG_FUNCTIONS
#include "Structs.h"

void RegistIdentifier(std::vector <TravelPack> &StructTravelPacks);
void RegistClients(Agency StructAgency, std::vector <Client> StructClients);
void RegistTravelPacks(Agency StructAgency, std::vector <TravelPack> StructTravelPacks);

#endif //REG_FUNCTIONS