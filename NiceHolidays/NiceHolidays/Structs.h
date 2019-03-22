#pragma once
#include <vector>
#include <string>
using namespace std;

typedef struct {
	string Street;
	int DoorNumber;
	string Apartment;
	string ZIPCode;
	string Province;
} Address;

typedef struct {
	int Year;
	int Month;
	int Day;
} Date;

typedef struct {
	string Name;
	int NIF;
	string URL;
	Address AgencyAddress;
	string ClientsFile;
	string TravelPacksFile;
} Agency;

typedef struct {
	string Name;
	int NIF;
	int Household;
	Address ClientAddress;
	vector <int> AdquiredTravelPacks;
} Client;

typedef struct {
	int Identifier;
	vector <string> TravelDestination;
	Date DepartureDate;
	Date ArrivalDate;
	int Price;
	int InitiallyAvailableSeats;
	int SoldSeats;
} TravelPack;