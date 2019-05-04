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

//View functions
void Agency::viewSoldPacks() const
{

	if (clientsObjs.empty())
	{
		std::cout << "There are no sold packs. \n\n";
		return;
	}
	else
	{
		vector<int> ids;
		size_t pack_i;

		//packs with info
		for (size_t j = 0; j < travelPacksObjs.size(); j++)
			ids.push_back(travelPacksObjs.at(j).getIdentifier());

		for (size_t k = 0; k < clientsObjs.size(); k++)
		{
			cout << "Client: " << clientsObjs.at(k).getName() << '\n';

			if (clientsObjs.at(k).getAcquiredTravelPacks().size() == 0) //No packs to show
			{
				cout << "This client has bought no packs. \n";
			}

			for (size_t i = 0; i < clientsObjs.at(k).getAcquiredTravelPacks().size(); i++) //client's packs
			{
				std::cout << "\nPack " << clientsObjs.at(k).getAcquiredTravelPacks().at(i) << ": \n"; //Pack ID: 

				if (find(ids.begin(), ids.end(), clientsObjs.at(k).getAcquiredTravelPacks().at(i)) != ids.end() ||
					find(ids.begin(), ids.end(), 0 - clientsObjs.at(k).getAcquiredTravelPacks().at(i)) != ids.end()) //if client's pack in ids
				{
					for (size_t j = 0; j < travelPacksObjs.size(); j++) // find indice
					{
						if (travelPacksObjs.at(j).getIdentifier() == clientsObjs.at(k).getAcquiredTravelPacks().at(i) ||
							travelPacksObjs.at(j).getIdentifier() == 0 - clientsObjs.at(k).getAcquiredTravelPacks().at(i)) //if same indices 
						{
							pack_i = j;
							break;
						}
					}

					//COUT 
					cout << "ID: " << travelPacksObjs.at(pack_i).getIdentifier() << '\n';
					cout << "Start Date: " << travelPacksObjs.at(pack_i).getDepartureDate().getDate() << '\n';
					cout << "Final Date: " << travelPacksObjs.at(pack_i).getArrivalDate().getDate() << '\n';
					cout << "Price: " << travelPacksObjs.at(pack_i).getPrice() << '\n';
					cout << "Capacity: " << travelPacksObjs.at(pack_i).getMaximumSeats() << '\n';
					cout << "Sold: " << travelPacksObjs.at(pack_i).getSoldSeats() << '\n';
					cout << "Places: ";
					//Places
					if (travelPacksObjs.at(pack_i).getTravelDestination().size() == 0)
						cout << "---" << "\n\n";
					else
					{
						cout << travelPacksObjs.at(pack_i).getTravelDestination().at(0);
						for (size_t w = 1; w < travelPacksObjs.at(pack_i).getTravelDestination().size(); w++)
							cout << ", " << travelPacksObjs.at(pack_i).getTravelDestination().at(w);
						cout << "\n\n";
					}
				}
				else
					cout << "There is no info on this pack. \n\n";
			}
			cout << "----------------------------------------------------------------------- \n\n";
		}
		return;
	}
}

void Agency::viewAvailablePacks() const
{
	string date;

	cout << left << setw(10) << "ID";
	cout << left << setw(15) << "Start Date";
	cout << left << setw(15) << "Final Date";
	cout << left << setw(8) << "Price";
	cout << left << setw(9) << "Capacity";
	cout << left << setw(8) << "Sold";
	cout << left << setw(30) << "Places" << '\n';
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------- \n";

	for (size_t i = 0; i < getTravelPacksObjs().size(); i++)
	{
		if (getTravelPacksObjs().at(i).getIdentifier() > 0)
		{
			cout << left << setw(10) << getTravelPacksObjs().at(i).getIdentifier() << left;
			//Start Date
			cout << setw(15) << getTravelPacksObjs().at(i).getDepartureDate().getDate() << left;
			//Final Date
			cout << setw(15) << getTravelPacksObjs().at(i).getArrivalDate().getDate() << left;
		
			cout << setw(8) << getTravelPacksObjs().at(i).getPrice() << left;
			cout << setw(9) << getTravelPacksObjs().at(i).getMaximumSeats() << left;
			cout << setw(8) << getTravelPacksObjs().at(i).getSoldSeats()<< left;

			//Places
			if (getTravelPacksObjs().at(i).getTravelDestination().size() == 0)
				cout << "---";
			else
			{
				cout << getTravelPacksObjs().at(i).getTravelDestination().at(0);
				for (size_t j = 1; j < getTravelPacksObjs().at(i).getTravelDestination().size(); j++)
					if (j == 1)
						cout << " - " << getTravelPacksObjs().at(i).getTravelDestination().at(j);
					else
						cout << ", " << getTravelPacksObjs().at(i).getTravelDestination().at(j);
			}
			cout << "\n \n \n";

		}
		
	}
}

void Agency::viewAllClients() const
{
	cout << '\n';
	cout << left << setw(30) << "Name";
	cout << left << setw(15) << "NIF";
	cout << left << setw(8) << "Family";
	cout << left << setw(30) << "Street";
	cout << left << setw(6) << "Door";
	cout << left << setw(8) << "Floor";
	cout << left << setw(10) << "ZIP";
	cout << left << setw(20) << "City";
	cout << left << "Travel Packs" << '\n';
	cout << "------------------------------------------------------------------------------------------- \n";

	for (size_t i = 0; i < clientsObjs.size(); i++)
	{
		cout << left << setw(30) << clientsObjs[i].getName() << left;
		cout << setw(15) << clientsObjs[i].getNif() << left;
		cout << setw(8) << clientsObjs[i].getHousehold() << left;
		cout << setw(30) << clientsObjs[i].getClientAddress().getStreet() << left;
		cout << setw(6) << clientsObjs[i].getClientAddress().getDoorNumber() << left;
		cout << setw(8) << clientsObjs[i].getClientAddress().getApartment() << left;
		cout << setw(10) << clientsObjs[i].getClientAddress().getZipCode() << left;
		cout << setw(20) << clientsObjs[i].getClientAddress().getLocality() << left;
		//Packs
		if (clientsObjs[i].getAcquiredTravelPacks().size() == 0)
			cout << "---";
		else
		{
			cout << clientsObjs[i].getAcquiredTravelPacks().at(0);
			for (size_t j = 1; j < clientsObjs[i].getAcquiredTravelPacks().size(); j++)
				cout << ", " << clientsObjs[i].getAcquiredTravelPacks().at(j);
		}
		cout << "\n \n \n";
	}
}

void Agency::viewSpecificClient(int index) const
{
	cout << '\n';
	cout << "NAME: " << clientsObjs.at(index).getName() << '\n';
	cout << "NIF: " << clientsObjs.at(index).getNif() << '\n';
	cout << "FAMILY SIZE: " << clientsObjs.at(index).getHousehold() << '\n';
	cout << "STREET: " << clientsObjs.at(index).getClientAddress().getStreet() << '\n';
	cout << "DOOR: " << clientsObjs.at(index).getClientAddress().getDoorNumber() << '\n';
	cout << "FLOOR: " << clientsObjs.at(index).getClientAddress().getApartment() << '\n';
	cout << "ZIP: " << clientsObjs.at(index).getClientAddress().getZipCode() << '\n';
	cout << "CITY: " << clientsObjs.at(index).getClientAddress().getLocality() << '\n';
	cout << "TRAVEL PACKS: ";
	if (clientsObjs.at(index).getAcquiredTravelPacks().size() == 0)
		cout << "-----" << '\n';
	else
	{
		cout << clientsObjs.at(index).getAcquiredTravelPacks().at(0);
		for (size_t i = 1; i < clientsObjs.at(index).getAcquiredTravelPacks().size(); i++)
			cout << ", " << clientsObjs.at(index).getAcquiredTravelPacks().at(i);
		cout << "\n \n \n";
	}
	return;
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
	int aux_sold_seats;

	if (TravelPacksFile.is_open()) {
		while (getline(TravelPacksFile, line)) {
			if (first_line) {
				counter = -1;
				first_line = false;
			}

			if (line == "::::::::::") {
				result.push_back(TravelPack(aux_identifier, aux_travel_destination, AuxDepartureDate, AuxArrivalDate, aux_price, aux_maximum_seats, aux_sold_seats));
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
				case 6:
					aux_sold_seats = stoi(line);
			}

			counter++;
		}

		result.push_back(TravelPack(aux_identifier, aux_travel_destination, AuxDepartureDate, AuxArrivalDate, aux_price, aux_maximum_seats, aux_sold_seats));
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

//Save to clients file
//NOT TESTED

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

//Save to packs file
//NOT TESTED

void Agency::updatePacksFile() {

	ofstream f;

	f.open(travelpacks_file);

	if (f.is_open()) {

		f << abs(travelPacksObjs.at(size(travelPacksObjs) - 1).getIdentifier()) << endl;

		for (size_t i = 0; i < size(travelPacksObjs); i++) {

			f << travelPacksObjs.at(i).getIdentifier() << endl;

			if (size(travelPacksObjs.at(i).getTravelDestination()) == 1)
				f << travelPacksObjs.at(i).getTravelDestination().at(0) << endl;
			else {
				f << travelPacksObjs.at(i).getTravelDestination().at(0) << " - " << travelPacksObjs.at(i).getTravelDestination().at(1);
				for (size_t j = 2; j < size(travelPacksObjs.at(i).getTravelDestination()); j++) {
					f << ',' << travelPacksObjs.at(i).getTravelDestination().at(j);
				} f << endl;

			}

			f << travelPacksObjs.at(i).getDepartureDate().getYear() << '/' << travelPacksObjs.at(i).getDepartureDate().getMonth() << '/' << travelPacksObjs.at(i).getDepartureDate().getDay() << endl;
			f << travelPacksObjs.at(i).getArrivalDate().getYear() << '/' << travelPacksObjs.at(i).getArrivalDate().getMonth() << '/' << travelPacksObjs.at(i).getArrivalDate().getDay() << endl;
			f << travelPacksObjs.at(i).getPrice() << endl;
			f << travelPacksObjs.at(i).getMaximumSeats() << endl;
			f << travelPacksObjs.at(i).getSoldSeats() << endl;

			if (i != size(travelPacksObjs) - 1)
				f << "::::::::::" << endl;

		}
	}
	f.close();
}

void Agency::removeTravelPack(int selected) {
	travelPacksObjs.erase(travelPacksObjs.begin() + selected);
}

void Agency::removeClient(int selected) {
	clientsObjs.erase(clientsObjs.begin() + selected);
}