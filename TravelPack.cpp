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

TravelPack::TravelPack(int identifier, vector <string> travel_destination, Date DepartureDate, Date ArrivalDate, int price, int maximum_seats, int sold_seats) {
	this->identifier = identifier;
	this->travelDestination = travel_destination;
	this->DepartureDate = DepartureDate;
	this->ArrivalDate = ArrivalDate;
	this->price = price;
	this->maximum_seats = maximum_seats;
	this->sold_seats = sold_seats;
}

//Getters
int TravelPack::getIdentifier() const {
	return this->identifier;
}

vector <string> TravelPack::getTravelDestination() const {
	return this->travelDestination;
}

Date TravelPack::getDepartureDate() const {
	return this->DepartureDate;
}

Date TravelPack::getArrivalDate() const {
	return this->ArrivalDate;
}

int TravelPack::getPrice() const {
	return this->price;
}

int TravelPack::getMaximumSeats() const {
	return this->maximum_seats;
}

int TravelPack::getSoldSeats() const {
	return this->sold_seats;
}

//Setters
void TravelPack::setIdentifier(int identifier) {
	this->identifier = identifier;
}

void TravelPack::setTravelDestination(string travelDestination) {
	this->travelDestination = convertTravelDestination(travelDestination);
}

void TravelPack::setTravelDestination(vector<string> travelDestination) {
	this->travelDestination = travelDestination;
}

void TravelPack::setDepartureDate(string DepartureDate) {
	this->DepartureDate = Date(DepartureDate);
}

void TravelPack::setDepartureDate(Date DepartureDate) {
	this->DepartureDate = DepartureDate;
}

void TravelPack::setArrivalDate(string ArrivalDate) {
	this->ArrivalDate = Date(ArrivalDate);
}

void TravelPack::setArrivalDate(Date ArrivalDate) {
	this->ArrivalDate = ArrivalDate;
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

	for (size_t i = 0; i < travel_destination.length(); i++)
		if (travel_destination[i] == '–' || travel_destination[i] == ',' || travel_destination[i] == '-') {
			result.push_back(trim(aux_string));
			aux_string = "";
		}

		else
			aux_string += travel_destination[i];

	result.push_back(trim(aux_string));

	return result;
} 