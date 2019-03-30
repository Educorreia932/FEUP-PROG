#pragma once
#ifndef READ_FUNCTIONS
#define READ_FUNCTIONS
#include <vector>
#include "Structs.h"

int readNIF();
int readHousehold();
int readIdentifier(std::vector <TravelPack> StructTravelPacks);
int readPrice();
int readSeats(char mode, int InitialSeats, int SoldSeats);
bool readDate(std::string StringDate);
int readSelection(int interval_minimum, int interval_maximum);

#endif //READ_FUNCTIONS
