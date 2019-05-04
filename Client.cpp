#include "Client.h"

Client::Client(string name, int nif, int household, Address ClientAddress, vector <int> AcquiredTravelPacks, int totalPurchases) {
	this->name = name;
	this->nif = nif;
	this->household = household;
	this->ClientAddress = ClientAddress;
	this->AcquiredTravelPacks = AcquiredTravelPacks;
	this->totalPurchases = totalPurchases;
}

//Getters

string Client::getName() const {
	return this->name;
}

int Client::getNif() const {
	return this->nif;
}

int Client::getHousehold() const {
	return this->household;
}

Address Client::getClientAddress() const {
	return this->ClientAddress;
}

vector <int> Client::getAcquiredTravelPacks() const {
	return this->AcquiredTravelPacks;
}

int Client::getTotalPurchases() const{
	return this->totalPurchases;
}

//Setters

void Client::setName(string name) {
	this->name = name;
}

void Client::setNif(int nif) {
	this->nif = nif;
}

void Client::setHousehold(int household) {
	this->household = household;
}

void Client::setAddress(string client_address) {
	this->ClientAddress = Address(client_address);
}

void Client::setAcquiredTravelPacks(string adcquired_travel_packs) {
	this->AcquiredTravelPacks = str_to_PackageIds(adcquired_travel_packs);
}

void Client::setTotalPurchases(int total_purchases) {
	this->totalPurchases = total_purchases;
}