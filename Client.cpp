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

void Client::show()
{
	cout << "NAME: " << name << '\n';
	cout << "NIF: " << nif << '\n';
	cout << "FAMILY SIZE: " << household << '\n';
	cout << "STREET: " << ClientAddress.getStreet() << '\n';
	cout << "DOOR: " << ClientAddress.getDoorNumber() << '\n';
	cout << "FLOOR: " << ClientAddress.getApartment() << '\n';
	cout << "ZIP: " << ClientAddress.getZipCode() << '\n';
	cout << "CITY: " << ClientAddress.getLocality() << '\n';
	cout << "TRAVEL PACKS: ";
	if (AcquiredTravelPacks.size() == 0)
		cout << "-----" << '\n';
	else
	{
		cout << AcquiredTravelPacks.at(0);
		for (size_t i = 1; i <AcquiredTravelPacks.size(); i++)
			cout << ", " << AcquiredTravelPacks.at(i);
		cout << "\n \n \n";
	}
	return;
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
void Client::setAddress(Address new_address) {
	this->ClientAddress = new_address;
}

void Client::setAcquiredTravelPacks(string adcquired_travel_packs) {
	this->AcquiredTravelPacks = str_to_PackageIds(adcquired_travel_packs);
}
void Client::setAcquiredTravelPacks(vector<int> adcquired_travel_packs) {
	this->AcquiredTravelPacks =adcquired_travel_packs;
}

void Client::setTotalPurchases(int total_purchases) {
	this->totalPurchases = total_purchases;
}

bool operator <(const Client& c1, const Client& c2)
{
	if (c1.getName().at(0) < c2.getName().at(0))
		return true;
	else return false;
}