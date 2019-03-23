#pragma once
#ifndef SAVE_FUNCTIONS
#define SAVE_FUNCTIONS
#include "Structs.h"
#include <string> //Verificar se é possível remover

Agency SaveAgency(std::string File);
void SaveClients(std::string File, std::vector <Client> &StructClients);
void SaveTravelPacks(std::string File, std::vector <TravelPack> &StructTravelPacks);

#endif //SAVE_FUNCTIONS