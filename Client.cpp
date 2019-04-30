#include "Client.h"



Client::Client(string name, int nif, int household, Address ClientAddress, vector <int> AcquiredTravelPacks, int totalPurchases) {

	this->name = name;
	this->nif = nif;
	this->household = household;
	this->ClientAddress = ClientAddress;
	this->AcquiredTravelPacks = AcquiredTravelPacks;
	this->totalPurchases = totalPurchases;

}

string Client::getName() {
	return this->name;
}
int Client::getNif() {
	return this->nif;
}
int Client::getHousehold() {
	return this->household;
}
Address Client::getClientAddress() {
	return this->ClientAddress;
}
vector <int> Client::getAcquiredTravelPacks() {
	return this->AcquiredTravelPacks;
}
int Client::getTotalPurchases() {
	return this->totalPurchases;
}