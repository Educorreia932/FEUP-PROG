#pragma once
#include <string>
#include <vector>
#include "Date.h"

using namespace std;

class TravelPack {
	private:
		int Identifier;
		vector <string> TravelDestination;
		Date DepartureDate;
		Date ArrivalDate;
		int Price;
		int InitiallyAvailableSeats;
		int SoldSeats;
};