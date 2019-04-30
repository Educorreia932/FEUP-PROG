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
		void setTravelDestination(string travelDestination);
		void setArrivalDate(string ArrivalDate);
		void setDepartureDate(string DepartureDate);
		void setPrice(int price);
		void setMaximumSeats(int maximum_seats);
	private:
		//Variables/Data Structure
		int identifier;
		vector <string> travelDestination; 
		Date DepartureDate;
		Date ArrivalDate;
		int price;
		int maximum_seats;

		//Functions
		vector <string> convertTravelDestination(string travel_destination);
};