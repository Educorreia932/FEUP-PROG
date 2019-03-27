#pragma once
#ifndef SAVE_FUNCTIONS
#define SAVE_FUNCTIONS
#include "Structs.h"
#include <string> //Verificar se é possível remover

Agency saveAgency(std::string File);
void saveClients(std::string File, std::vector <Client> &StructClients);
void saveTravelPacks(std::string File, std::vector <TravelPack> &StructTravelPacks);

#endif //SAVE_FUNCTIONS