#pragma once
#ifndef SAVE_FUNCTIONS
#define SAVE_FUNCTIONS
#include "Structs.h"
#include <string> //Verificar se � poss�vel remover

void SaveAgency(std::string File, Agency &StructAgency);
void SaveClients(std::string File, std::vector <Client> &StructClients);
void SaveTravelPacks(std::string File, std::vector <TravelPack> &StructTravelPacks);

#endif //SAVE_FUNCTIONS