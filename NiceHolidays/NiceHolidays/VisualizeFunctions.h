#pragma once
#ifndef VIS_FUNCTIONS
#define VIS_FUNCTIONS
#include <vector>
#include "Structs.h"

void VisualizeSpecificClient(int ClientNumber, std::vector <Client> StructClients);
void VisualizeAgencyClients(std::vector <Client> StructClients);
void VisualizeSpecificTravelPack(int TravelPackNumber, std::vector <TravelPack> StructTravelPacks);
void VisualizeAvailableTravelPacks(std::vector <TravelPack> StructTravelPacks);
void VisualizeSoldTravelPacks(std::vector <TravelPack> StructTravelPacks, std::vector <Client> StructClients);

#endif //VIS_FUNCTIONS