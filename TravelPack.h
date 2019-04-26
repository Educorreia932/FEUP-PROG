#pragma once
#include <string>
#include <vector>
#include "Date.h"

using namespace std;

class TravelPack {
	private:
		int identifier;
		vector <string> travel_destination; //Mudar para stringstream (?)
		Date DepartureDate;
		Date ArrivalDate;
		unsigned int price;
		unsigned int maximum_seats;
};