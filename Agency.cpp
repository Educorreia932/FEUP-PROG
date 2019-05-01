#include "Agency.h"

//Constructors
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
	this->clientsObjs = readClients(clients_file);
}

//Getters
string Agency::getClientsFile() const  {
	return clients_file;
}

string Agency::getTravelPacksFile() const {
	return travelpacks_file;
}

vector <TravelPack> Agency::getTravelPacksObjs() const {
	return travelPacksObjs;
}

//Read functions
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
				result.push_back(Client(aux_name, aux_nif, aux_household, aux_ClientAddress, aux_AcquiredTravelPacks, aux_total_purchases));
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

//Not tested
void Agency::updateClientFile() {

	ofstream f;

	f.open(clients_file);

	if (f.is_open()) {

		for (size_t i = 0; i < size(clientsObjs); i++) {

			f << clientsObjs.at(i).getName() << endl;
			f << clientsObjs.at(i).getNif() << endl;
			f << clientsObjs.at(i).getHousehold() << endl;
			f << clientsObjs.at(i).getClientAddress().getStreet() << '/' << clientsObjs.at(i).getClientAddress().getDoorNumber() << '/' << clientsObjs.at(i).getClientAddress().getApartment() << '/'
				<< clientsObjs.at(i).getClientAddress().getZipCode() << '/' << clientsObjs.at(i).getClientAddress().getLocality() << endl;
			f << clientsObjs.at(i).getAcquiredTravelPacks()[0];
			for (size_t j = 1; j < size(clientsObjs.at(i).getAcquiredTravelPacks()); j++) {
				f << ';' << clientsObjs.at(i).getAcquiredTravelPacks().at(j);
			}
			f << endl;

			if (i != size(clientsObjs) - 1)
				f << "::::::::::" << endl;

		}

	}
	f.close();

}

//Save to packs file(Not working)
/*

void Agency::updatePacksFile() {

	ofstream f;

	f.open(travelpacks_file);

	if (f.is_open()) {

		f << abs(packs.at(size(packs) - 1).identifier) << endl;

		for (size_t i = 0; i < size(packs); i++) {

			f << packs.at(i).identifier << endl;

			if (size(packs.at(i).destinations) == 1)
				f << packs.at(i).destinations.at(0) << endl;
			else {
				f << packs.at(i).destinations.at(0) << " - " << packs.at(i).destinations.at(1);
				for (size_t j = 2; j < size(packs.at(i).destinations); j++) {
					f << ',' << packs.at(i).destinations.at(j);
				} f << endl;

			}

			f << packs.at(i).startDate.year << '/' << packs.at(i).startDate.month << '/' << packs.at(i).startDate.day << endl;
			f << packs.at(i).endDate.year << '/' << packs.at(i).endDate.month << '/' << packs.at(i).endDate.day << endl;
			f << packs.at(i).price << endl;
			f << packs.at(i).maxPeople << endl;
			f << packs.at(i).numberOfSold << endl;

			if (i != size(packs) - 1)
				f << "::::::::::" << endl;

		}

	}
	f.close();

}

*/

void Agency::removeTravelPack(int selected) {
	travelPacksObjs.erase(travelPacksObjs.begin() + selected);
}

void Agency::removeClient(int selected) {
	clientsObjs.erase(clientsObjs.begin() + selected);
}