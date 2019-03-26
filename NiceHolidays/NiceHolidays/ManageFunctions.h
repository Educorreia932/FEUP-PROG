#pragma once
#ifndef MAN_FUNCTIONS
#define MAN_FUNCTIONS
#include "Structs.h"

Client CreateClient(std::vector <Client> &StructClients);
void ChangeClient(int ClientNumber, std::vector <Client> &StructClients);
void RemoveClient(int ClientNumber, std::vector <Client> &StructClients);
void ManageClients(std::vector <Client> &StructClients);
void CreateTravelPack(std::vector <TravelPack> &StructTravelPacks);
void ChangeTravelPack(int TravelPackNumber, std::vector <TravelPack> &StructTravelPacks);
void RemoveTravelPack(int TravelPackNumber, std::vector <TravelPack> &StructTravelPacks);
void ManageTravelPacks(std::vector <TravelPack> &StructTravelPacks);

#endif //MAN_FUNCTIONS