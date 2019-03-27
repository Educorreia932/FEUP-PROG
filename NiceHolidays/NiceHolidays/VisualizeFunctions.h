#pragma once
#ifndef VIS_FUNCTIONS
#define VIS_FUNCTIONS
#include "Structs.h"

void visualizeSpecificClient(int ClientNumber, std::vector <Client> StructClients);
void visualizeAgencyClients(std::vector <Client> StructClients);
void visualizeSpecificTravelPack(int TravelPackNumber, std::vector <TravelPack> StructTravelPacks);
void visualizeAvailableTravelPacks(std::vector <TravelPack> StructTravelPacks);
void visualizeSoldTravelPacks(std::vector <TravelPack> StructTravelPacks, std::vector <Client> StructClients);
void visualizeClientsSelection(std::vector <Client> StructClients);
void visualizeTravelPacksSelection(std::vector <TravelPack> StructTravelPacks);

#endif //VIS_FUNCTIONS