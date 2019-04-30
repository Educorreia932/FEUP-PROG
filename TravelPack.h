#pragma once
#include <vector>
#include "Date.h"
#include "Auxiliary.h"

using namespace std;

class TravelPack {
	public:
		TravelPack();
		TravelPack(int identifier, string travel_destination, Date DepartureDate, Date ArrivalDate, int price, int maximum_seats);
		int getIdentifier() const;
	private:
		int identifier;
		vector <string> travel_destination; 
		Date DepartureDate;
		Date ArrivalDate;
		int price;
		int maximum_seats;

		vector <string> convertTravelDestination(string travel_destination);
};