#include "Agency.h"
#undef travelPack 
#define travelPack travelPacksObjs.at(i)

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

//View functions - To visualize information about packs, clients and the agency
void Agency::viewSoldPacks() const {
	if (clientsObjs.empty()) {
		std::cout << "There are no sold packs. \n\n";
		return;
	}

	else {
		vector<int> ids;
		size_t pack_i;

		//Packs with info
		for (size_t j = 0; j < travelPacksObjs.size(); j++)
			ids.push_back(travelPacksObjs.at(j).getIdentifier());

		for (size_t k = 0; k < clientsObjs.size(); k++)
		{
			cout << "Client: " << clientsObjs.at(k).getName() << '\n';

			if (clientsObjs.at(k).getAcquiredTravelPacks().size() == 0) //No packs to show
			{
				cout << "This client has bought no packs. \n";
			}

			for (size_t i = 0; i < clientsObjs.at(k).getAcquiredTravelPacks().size(); i++) //Client's packs
			{
				std::cout << "\nPack " << clientsObjs.at(k).getAcquiredTravelPacks().at(i) << ": \n"; //Pack ID: 

				if (find(ids.begin(), ids.end(), clientsObjs.at(k).getAcquiredTravelPacks().at(i)) != ids.end() ||
					find(ids.begin(), ids.end(), 0 - clientsObjs.at(k).getAcquiredTravelPacks().at(i)) != ids.end()) //If client's pack in ids
				{
					for (size_t j = 0; j < travelPacksObjs.size(); j++) //Find index
					{
						if (travelPacksObjs.at(j).getIdentifier() == clientsObjs.at(k).getAcquiredTravelPacks().at(i) ||
							travelPacksObjs.at(j).getIdentifier() == 0 - clientsObjs.at(k).getAcquiredTravelPacks().at(i)) //If same index
						{
							pack_i = j;
							break;
						}
					}

					//COUT 
					travelPacksObjs.at(pack_i).show();
				}
				else
					cout << "There is no info on this pack. \n\n";
			}
			cout << "----------------------------------------------------------------------- \n\n";
		}
		return;
	}
}

void Agency::viewAvailablePacks() const {
	string date;

	cout << left << setw(10) << "ID";
	cout << left << setw(15) << "Start Date";
	cout << left << setw(15) << "Final Date";
	cout << left << setw(8) << "Price";
	cout << left << setw(9) << "Capacity";
	cout << left << setw(8) << "Sold";
	cout << left << setw(30) << "Places" << '\n';
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------- \n";

	for (size_t i = 0; i < getTravelPacksObjs().size(); i++) {
		if (getTravelPacksObjs().at(i).getIdentifier() > 0)	{
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

			else {
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
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------ \n";

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

void Agency::viewNumberAndValueSoldPacks() const {
	int total_price = 0, total_sold = 0;

	for (size_t i = 0; i < travelPacksObjs.size(); i++)	{
		cout << "Travel Pack: " << travelPack.getIdentifier() << '\n'
			 << "Sold Seats: " << travelPack.getSoldSeats() << '\n'
			 << "Price per seat: " << travelPack.getPrice() << "\n\n"
			 << "-----------------------------\n\n";

		total_price += travelPack.getPrice() * travelPack.getSoldSeats();
		total_sold += travelPack.getSoldSeats();
	}

	cout << "Total Sold Seats: " << total_sold << '\n'
		<< "Total Revenue: " << total_price << "\n\n";
	
	return;
}

void Agency::viewSpecificClient(size_t index) {
	clientsObjs.at(index).show();
	return;
}

void Agency::show() {
	cout << "AGENCY INFO\n\n";
	cout << "NAME: " << name << '\n'
		 << "NIF: " << nif << '\n'
		 << "STREET: " << AgencyAddress.getStreet() << '\n'
		 << "DOOR: " << AgencyAddress.getDoorNumber() << '\n'
		 << "FLOOR: " << AgencyAddress.getApartment() << '\n'
		 << "ZIP: " << AgencyAddress.getZipCode() << '\n'
		 << "CITY: " << AgencyAddress.getLocality() << '\n'
		 << "URL: " << url << '\n'
		 << "CLIENTS FILE: " <<	clients_file << '\n'
		 << "TRAVEL PACKS FILE: " << travelpacks_file << '\n'
		 << "CLIENTS: ";

	//Clients
	if (clientsObjs.size() != 0)
	{
		cout << clientsObjs.at(0).getName();
		for (size_t i = 1; i < clientsObjs.size(); i++)
			cout << ", " << clientsObjs.at(i).getName();
	}
	else cout << "---";

	//Travel Packs
	cout << "\nTRAVEL PACKS: ";
	if (travelPacksObjs.size() != 0)
	{
		cout << travelPacksObjs.at(0).getIdentifier();
		for (size_t j = 1; j < travelPacksObjs.size(); j++)
			cout << ", " << travelPacksObjs.at(j).getIdentifier();
	}
	else cout << "---";

	cout << "\n\n";

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
				aux_AcquiredTravelPacks = str_to_PackageIds(line);
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

//Update Functions - Saves the alterations made to the respective files
void Agency::updateClientFile() {
	ofstream f;

	f.open(clients_file);

	if (f.is_open()) {
		for (size_t i = 0; i < size(clientsObjs); i++) {

			f << clientsObjs.at(i).getName() << endl
		      << clientsObjs.at(i).getNif() << endl
			  << clientsObjs.at(i).getHousehold() << endl
			  << clientsObjs.at(i).getClientAddress().getStreet() << '/' << clientsObjs.at(i).getClientAddress().getDoorNumber() << '/' << clientsObjs.at(i).getClientAddress().getApartment() << '/'
			  << clientsObjs.at(i).getClientAddress().getZipCode() << '/' << clientsObjs.at(i).getClientAddress().getLocality() << endl
			  << clientsObjs.at(i).getAcquiredTravelPacks()[0];

			for (size_t j = 1; j < size(clientsObjs.at(i).getAcquiredTravelPacks()); j++) {
				f << ';' << clientsObjs.at(i).getAcquiredTravelPacks().at(j);
			}

			f << endl << clientsObjs.at(i).getTotalPurchases() << endl;

			if (i != size(clientsObjs) - 1)
				f << "::::::::::" << endl;
		}
	}

	f.close();
}

void Agency::updatePacksFile() {

	ofstream f;

	f.open(travelpacks_file);

	if (f.is_open()) {

		f << abs(travelPacksObjs.at(size(travelPacksObjs) - 1).getIdentifier()) << endl;

		for (size_t i = 0; i < size(travelPacksObjs); i++) {

			f << travelPack.getIdentifier() << endl;

			if (size(travelPack.getTravelDestination()) == 1)
				f << travelPack.getTravelDestination().at(0) << endl;

			else {
				f << travelPack.getTravelDestination().at(0) << " - " << travelPack.getTravelDestination().at(1);
				for (size_t j = 2; j < size(travelPack.getTravelDestination()); j++) {
					f << ',' << travelPack.getTravelDestination().at(j);
				} f << endl;

			}

			f << travelPack.getDepartureDate().getYear() << '/' << setw(2) << setfill('0') << travelPack.getDepartureDate().getMonth() << '/' << setw(2) << setfill('0') << travelPack.getDepartureDate().getDay() << endl;
			f << travelPack.getArrivalDate().getYear() << '/' << setw(2) << setfill('0') << travelPack.getArrivalDate().getMonth() << '/' << setw(2) << setfill('0') << travelPack.getArrivalDate().getDay() << endl;
			f << travelPack.getPrice() << endl;
			f << travelPack.getMaximumSeats() << endl;
			f << travelPack.getSoldSeats() << endl;

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

//Other functions

#undef travelPack 
#define client clientsObjs.at(clientSelected)
#define travelPack travelPacksObjs.at(packSelected)

void Agency::buyPack(int packSelected, int clientSelected) {
	vector<int> result;

	if ((travelPack.getMaximumSeats() - travelPack.getSoldSeats()) >= client.getHousehold()) {
		travelPack.setSoldSeats(travelPack.getSoldSeats() + client.getHousehold()); //update sold seats

		if (travelPack.getSoldSeats() == travelPack.getMaximumSeats())
			travelPack.setIdentifier(0 - travelPack.getIdentifier()); //update id if sold out

		//Add id
		for (size_t i = 0; i < client.getAcquiredTravelPacks().size(); i++)
			result.push_back(client.getAcquiredTravelPacks().at(i));

		result.push_back(travelPack.getIdentifier());
		client.setAcquiredTravelPacks(result);

		client.setTotalPurchases(client.getTotalPurchases() + travelPack.getPrice() * client.getHousehold());
		cout << "Purchase complete.\n Total Price: " << travelPack.getPrice() * client.getHousehold() << "euros\n\n";
	}

	else
		cerr << "ERROR:\nThere is no sufficient available seats to complete the purchase. \n\n";
}

#undef travelPack 
#define travelPack travelPacksObjs.at(i)

vector<string> Agency::mostVisitedPlaces() {
	vector<string> result;
	result.clear();

	if (travelPacksObjs.size() == 0) {
		result.clear();
		return result;
	}

	map<string, int> placesAndSeats;
	int aux, max = 0;

	for (size_t i = 0; i < travelPacksObjs.size(); i++) { //Percorre os pacotes
		for (size_t j = 0; j < travelPack.getTravelDestination().size(); j++) { //Percorre os destinos do pacote
			if (placesAndSeats.find(travelPack.getTravelDestination().at(j)) != placesAndSeats.end()) { //Se o local já estiver em placesAndSeats
				aux = placesAndSeats[travelPack.getTravelDestination().at(j)];
				placesAndSeats[travelPack.getTravelDestination().at(j)] = aux + travelPack.getSoldSeats(); //update sold seats

				if (max < aux + travelPack.getSoldSeats()) //update max if less
				{
					max = aux + travelPack.getSoldSeats();
					result.clear(); //empty vec
					result.push_back(travelPack.getTravelDestination().at(j)); //adds place
				}

				else {
					if (max == aux + travelPack.getSoldSeats()) //dont need to update max
						result.push_back(travelPack.getTravelDestination().at(j)); //only adds place to result
				}
			}
			
			else {
				placesAndSeats.insert(pair<string, int>(travelPack.getTravelDestination().at(j), travelPack.getSoldSeats())); //if not in map add

				if (max < travelPack.getSoldSeats()) //update max
				{
					max = travelPack.getSoldSeats();
					result.clear();
					result.push_back(travelPack.getTravelDestination().at(j)); //add place
				}

				else {
					if (max == travelPack.getSoldSeats()) //dont need to update max
						result.push_back(travelPack.getTravelDestination().at(j)); //only adds place to result
				}
			}
		}
	}

	return result;
}

vector<int> Agency::packsWithMostVisitedPlaces(vector<string> &places)
{
	vector<int> result;

	for (size_t i = 0; i < travelPacksObjs.size(); i++)
	{
		for (size_t j = 0; j < travelPack.getTravelDestination().size(); j++)
		{
			if (find(places.begin(), places.end(), travelPack.getTravelDestination().at(j)) != places.end())
			{
				result.push_back(travelPack.getIdentifier());
				break;
			}
		}
	}
	return result;
}
