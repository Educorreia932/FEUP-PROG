#include <fstream>
#include "SaveFunctions.h"
#include "GetFunctions.h"
#include "AuxiliaryFunctions.h"

Agency SaveAgency(std::string File) {
	Agency AuxStruct;
	std::string Line;
	std::ifstream Agency(File);
	int Counter = 0;

	if (Agency.is_open()) {
		while (getline(Agency, Line)) {
			switch (Counter) {
				case 0:
					AuxStruct.Name = Line;
					break;
				case 1:
					AuxStruct.NIF = stoi(Line);
					break;
				case 2:
					AuxStruct.URL = Line;
					break;
				case 3:
					GetAddress(AuxStruct.AgencyAddress, Line);
					break;
				case 4:
					AuxStruct.ClientsFile = Line;
					break;
				case 5:
					AuxStruct.TravelPacksFile = Line;
					break;
			}

			Counter += 1;
		}

		Agency.close();
	}

	return AuxStruct;
}

void SaveClients(std::string File, std::vector <Client> &StructClients) {
	std::string Line;
	std::ifstream Clients(File);
	Client AuxStruct;
	int Counter = 0, ClientCounter = 0;

	if (Clients.is_open()) {
		while (getline(Clients, Line)) {
			if (Line == "::::::::::") {
				StructClients.push_back(AuxStruct);
				Counter = -1;
				ClientCounter += 1;
			}

			else
				switch (Counter) {
				case 0:
					AuxStruct.Name = Line;
					break;
				case 1:
					AuxStruct.NIF = stoi(Line);
					break;
				case 2:
					AuxStruct.Household = stoi(Line);
					break;
				case 3:
					GetAddress(AuxStruct.ClientAddress, Line);
					break;
				case 4:
					AuxStruct.AdquiredTravelPacks = GetAdquiredTravelPacks(Line);
					break;
				}

			Counter += 1;
		}

		StructClients.push_back(AuxStruct);

		Clients.close();
	}
}

void SaveTravelPacks(std::string File, std::vector <TravelPack> &StructTravelPacks) {
	std::string Line;
	std::ifstream TravelPacks(File);
	TravelPack AuxStruct;

	int Counter = 0, TravelPackCounter = 0;
	bool FirstLine = true;

	if (TravelPacks.is_open()) {
		while (getline(TravelPacks, Line)) {
			if (FirstLine) {
				Counter = -1;
				FirstLine = false;
			}

			else if (Line == "::::::::::") {
				StructTravelPacks.push_back(AuxStruct);
				Counter = -1;
				TravelPackCounter += 1;
			}

			else
				switch (Counter) {
				case 0:
					AuxStruct.Identifier = stoi(Line);
					break;
				case 1:
					AuxStruct.TravelDestination = GetTravelDestination(Line);
					break;
				case 2:
					GetDate(AuxStruct.DepartureDate, Line);
					break;
				case 3:
					GetDate(AuxStruct.ArrivalDate, Line);
					break;
				case 4:
					AuxStruct.Price = stoi(Line);
					break;
				case 5:
					AuxStruct.InitiallyAvailableSeats = stoi(Line);
					break;
				case 6:
					AuxStruct.SoldSeats = stoi(Line);
					break;
				}

			Counter += 1;
		}

		StructTravelPacks.push_back(AuxStruct);

		TravelPacks.close();
	}
}