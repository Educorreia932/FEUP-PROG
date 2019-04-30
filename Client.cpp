#include "Client.h"

Client::Client(string name, int nif, int household, Address ClientAddress, vector <int> AcquiredTravelPacks, int total_purchases) {
	this->name = name;
	this->nif = nif;
	this->household = household;
	this->ClientAddress = ClientAddress;
	this->AcquiredTravelPacks = AcquiredTravelPacks;
	this->total_purchases = total_purchases;
}