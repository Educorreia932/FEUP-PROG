#include "TravelPack.h"

//Constructor
TravelPack::TravelPack(int identifier, string travel_destination, Date DepartureDate, Date ArrivalDate, int price, int maximum_seats, int sold_seats) {
	this->identifier = identifier;
	this->travelDestination = convertTravelDestination(travel_destination);
	this->DepartureDate = DepartureDate;
	this->ArrivalDate = ArrivalDate;
	this->price = price;
	this->maximum_seats = maximum_seats;
	this->sold_seats = sold_seats;
}

//Getters
int TravelPack::getIdentifier() const {
	return identifier;
}

vector <string> TravelPack::getTravelDestination() const {
	return travelDestination;
}

//Setters
void TravelPack::setIdentifier(int identifier) {
	this->identifier = identifier;
}

void TravelPack::setTravelDestination(string travelDestination) {
	this->travelDestination = convertTravelDestination(travelDestination);
}

void TravelPack::setDepartureDate(string DepartureDate) {
	this->DepartureDate = Date(DepartureDate);
}

void TravelPack::setArrivalDate(string ArrivalDate) {
	this->ArrivalDate = Date(ArrivalDate);
}

void TravelPack::setPrice(int price) {
	this->price = price;
}

void TravelPack::setMaximumSeats(int maximum_seats) {
	this->maximum_seats = maximum_seats;
}

void TravelPack::setSoldSeats(int sold_seats) {
	this->sold_seats = sold_seats;
}

//Other
vector <string> TravelPack::convertTravelDestination(string travel_destination) {
	vector <string> result;
	string aux_string;

	for (int i = 0; i < travel_destination.length(); i++)
		if (travel_destination[i] == '–' || travel_destination[i] == ',' || travel_destination[i] == '-') {
			result.push_back(trim(aux_string));
			aux_string = "";
		}

		else
			aux_string += travel_destination[i];

	result.push_back(trim(aux_string));

	return result;
} 