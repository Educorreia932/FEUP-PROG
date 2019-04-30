#pragma once
#include <vector>
#include "Date.h"
#include "Auxiliary.h"

using namespace std;

class TravelPack {
	public:
		TravelPack(int identifier, string travel_destination, Date DepartureDate, Date ArrivalDate, int price, int maximum_seats);
		int getIdentifier() const;
		vector <string> getTravelDestination() const;
		void setIdentifier(int identifier);
	private:
		int identifier;
		vector <string> travelDestination; 
		Date DepartureDate;
		Date ArrivalDate;
		int price;
		int maximum_seats;

		vector <string> convertTravelDestination(string travel_destination);
};