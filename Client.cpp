#include "Client.h"

Client::Client(string name, int nif, int household, Address ClientAddress, vector <int> AcquiredTravelPacks, int totalPurchases) {
	this->name = name;
	this->nif = nif;
	this->household = household;
	this->ClientAddress = ClientAddress;
	this->AcquiredTravelPacks = AcquiredTravelPacks;
	this->totalPurchases = totalPurchases;
}

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