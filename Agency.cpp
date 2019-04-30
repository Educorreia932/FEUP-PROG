#include "Agency.h"

Agency::Agency() {
	this->name = "N/A";
	this->nif = -1;
	this->url = "N/A";
	this->AgencyAddress = Address();
	this->clients_file = "N/A";
	this->travelpacks_file = "N/A";
}

Agency::Agency(string file_name) {
	string line;
	ifstream AgencyFile(file_name);
	int counter = 0;
	
	if (AgencyFile.is_open()) {
		while (getline(AgencyFile, line)) {
			switch (counter) {
				case 0:
					this->name = line;
					break;
				case 1:
					this->nif = stoi(line);
					break;
				case 2:
					this->url = line;
					break;
				case 3:
					this->AgencyAddress = Address(line);
					break;
				case 4:
					this->clients_file = line;
					break;
				case 5:
					this->travelpacks_file = line;
					break;
			}

			counter++;
		}

		AgencyFile.close();
	}

	this->travelPacksObjs = readTravelPacks(travelpacks_file);
}

string Agency::getClientsFile() const  {
	return clients_file;
}

string Agency::getTravelPacksFile() const {
	return travelpacks_file;
}

vector <TravelPack> Agency::getTravelPacksObjs() const {
	return travelPacksObjs;
}

vector <TravelPack> Agency::readTravelPacks(string file_name) {
	vector <TravelPack> result;
	string line;
	ifstream TravelPacksFile(file_name);	
	int counter = 0;
	bool first_line = true;

	int aux_identifier;
	string aux_travel_destination;
	Date AuxDepartureDate;
	Date AuxArrivalDate;
	int aux_price;
	int aux_maximum_seats;

	if (TravelPacksFile.is_open()) {
		while (getline(TravelPacksFile, line)) {
			if (first_line) {
				counter = -1;
				first_line = false;
			}

			if (line == "::::::::::") {
				result.push_back(TravelPack(aux_identifier, aux_travel_destination, AuxDepartureDate, AuxArrivalDate, aux_price, aux_maximum_seats));
				counter = -1;
			}

			switch (counter) {
				case 0:
					aux_identifier = stoi(line);
					break;
				case 1:
					aux_travel_destination = line;
					break;
				case 2:
					AuxDepartureDate = Date(line);
					break;
				case 3:
					AuxArrivalDate = Date(line);
					break;
				case 4:
					aux_price = stoi(line);
					break;
				case 5:
					aux_maximum_seats = stoi(line);
			}

			counter++;
		}

		result.push_back(TravelPack(aux_identifier, aux_travel_destination, AuxDepartureDate, AuxArrivalDate, aux_price, aux_maximum_seats));
		TravelPacksFile.close(); 
	}

	return result;
}

vector <Client> Agency::readClients(string file_name) {
	vector <Client> result;
	string line;
	ifstream ClientsFile(file_name);
	int counter = 0;

	string aux_name;
	int aux_nif;
	int aux_household;
	Address aux_ClientAddress;
	vector <int> aux_AcquiredTravelPacks;
	int aux_total_purchases;


	if (ClientsFile.is_open()) {
		while (getline(ClientsFile, line)) {
			if (line == "::::::::::") {
				counter = -1;
			}

			switch (counter) {
			case 0:
				aux_name = line;
				break;
			case 1:
				aux_nif = stoi(line);
				break;
			case 2:
				aux_household = stoi(line);
				break;
			case 3:
				aux_ClientAddress = Address(line);
				break;
			case 4:
				aux_AcquiredTravelPacks = readPackageIds(line);
				break;
			case 5:
				aux_total_purchases = stoi(line);
				break;
			}

			counter++;
		}

		result.push_back(Client(aux_name, aux_nif, aux_household, aux_ClientAddress, aux_AcquiredTravelPacks,aux_total_purchases));
		ClientsFile.close();
	}

	return result;
}