#pragma once
#include <vector>
#include <string>

typedef struct {
	std::string Street;
	int DoorNumber;
	std::string Apartment;
	std::string ZIPCode;
	std::string Province;
} Address;

typedef struct {
	int Year;
	int Month;
	int Day;
} Date;

typedef struct {
	std::string Name;
	int NIF;
	std::string URL;
	Address AgencyAddress;
	std::string ClientsFile;
	std::string TravelPacksFile;
} Agency;

typedef struct {
	std::string Name;
	int NIF;
	int Household;
	Address ClientAddress;
	std::vector <int> AdquiredTravelPacks;
} Client;

typedef struct {
	int Identifier;
	std::vector <std::string> TravelDestination;
	Date DepartureDate;
	Date ArrivalDate;
	int Price;
	int InitiallyAvailableSeats;
	int SoldSeats;
} TravelPack;