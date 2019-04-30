#pragma once
#include <vector>
#include "Date.h"
#include "Auxiliary.h"

using namespace std;

class TravelPack {
	public:
		TravelPack(int identifier, string travel_destination, Date DepartureDate, Date ArrivalDate, int price, int maximum_seats);
		
		//Getters
		int getIdentifier() const;
		vector <string> getTravelDestination() const;

		//Setters
		void setIdentifier(int identifier);
		void setTravelDestination(vector <string> travelDestination);
		void setArrivalDate(Date ArrivalDate);
		void setDepartureDate(Date DepartureDate);
		void setPrice(int price);
		void setMaximumSeats(int maximum_seats);
	private:
		int identifier;
		vector <string> travelDestination; 
		Date DepartureDate;
		Date ArrivalDate;
		int price;
		int maximum_seats;

		vector <string> convertTravelDestination(string travel_destination);
};