#include "Menu.h"
#define clients AgencyObj.clientsObjs
#define travelPacks AgencyObj.travelPacksObjs	

//Constructor
Menu::Menu(Agency AgencyObj) {
	this->AgencyObj = AgencyObj;
}

/*
	«Show» functions - Mostram menu de seleção e retornam opção selecionada
	«Selection» functions - "Switch cases", fazem ações diferentes conforme o selecionado
*/

int Menu::showMenu() {
	system("cls");

	cout << "What do you want to do? Insert the corresponding key." << endl << endl
		<< "1) Manage clients." << endl
		<< "2) Manage travel packs." << endl
		<< "3) Visualize a specific client." << endl
		<< "4) Visualize all the clients of the agency." << endl
		<< "5) Visualize available travel packs." << endl
		<< "6) Visualize sold travel packs." << endl
		<< "7) Buy a travel pack for a client." << endl
		<< "8) Visualize the number and total value of sold travel packs." << endl
		<< "9) Obtain the name of the most visited places." << endl
		// << "10) Obtain a list of the clients with one of the travel packs with one of the most visited places." << endl << endl
		<< "0) Exit the program and save the alterations made." << endl;


	int selection = readOption(9); // Mudar para outro valor se se acrescentar alguma coisa

	return selection;
}

void Menu::menuSelection(int selected) {
	system("cls");

	switch (selected) {
		case 1:
			manageClientsSelection(showManageClients());
			break;
		case 2:
			manageTravelPacksSelection(showManageTravelPacks());
			break;
		case 3:
			cout << "Which client do you wish to check the information of? Insert the corresponding key." << endl;
			AgencyObj.viewSpecificClient(showClients() - 1);
			system("pause");
			break;
		case 4:
			AgencyObj.viewAllClients();
			system("pause");
			break;
		case 5:
			AgencyObj.viewAvailablePacks();
			system("pause");
			break;
		case 6:
			AgencyObj.viewSoldPacks();
			system("pause");
			break;
		case 7:
			cout << "Not working. In construction.";
			break;
		case 8:
			cout << "Not working. In construction.";
			break;
		case 9:
			cout << "Not working. In construction.";
			break;
		case 0:
			break;
	}

	menuSelection(showMenu());
}

//Clients Menus

int Menu::showClients() {

	for (size_t i = 0; i < size(clients); i++)
		cout << i + 1 << ") " << clients[i].getName() << " (" << clients[i].getNif() << ")" << endl;

	int selection = readOption(size(clients));

	return selection;
}

int Menu::showManageClients() {
	

	cout << "What do you want to do? Insert the corresponding key." << endl << endl
		<< "1) Create a new client." << endl
		<< "2) Change the information of a client." << endl
		<< "3) Remove an existent client." << endl
		<< "0) Go back." << endl;

	int selection = readOption(3);

	return selection;
}

void Menu::manageClientsSelection(int selected) {
	int selected_client;
	system("cls");

	switch (selected) {
		case 1:
			createClient();
			break;
		case 2:
			cout << "Which client do you wish to change the information of? Insert the corresponding key." << endl << endl;

			selected_client = showClients() - 1;
			system("cls");
			changeClientsSelection(showChangeClients(), selected_client);
			break;
		case 3:
			cout << "Which client do you wish to remove? Insert the corresponding key." << endl << endl;

			selected_client = showClients() - 1;
			AgencyObj.removeClient(selected_client);
			break;
	}
}

int Menu::showChangeClients() {

	cout << "What do you want to change in the client? Insert the corresponding key." << endl << endl
		 << "1) The name." << endl
		 << "2) The NIF." << endl
		 << "3) The household." << endl
		 << "4) The address." << endl
		 << "5) The acquired travel packs." << endl
		 << "6) The value of total purchases." << endl
		 << "0) Go back." << endl << endl
		 << "Option: ";

	int selection = readOption(6);
	
	return selection;
}

void Menu::changeClientsSelection(int selected, int selected_client) {
	int aux_int;
	string aux_string;

	switch (selected) {
		case 1:
			clients[selected_client].setName(readName("Insert the new name of the client: "));
			break;
		case 2:
			cout << "Insert the new NIF of the client: ";
			cin >> aux_int;
			cin.ignore();

			clients[selected_client].setNif(aux_int);
			break;
		case 3:
			cout << "Insert the new household of the client: ";
			cin >> aux_int;
			cin.ignore();

			clients[selected_client].setHousehold(aux_int);
			break;
		case 4:
			cout << "Insert the new address of the client: ";
			getline(cin, aux_string);

			clients[selected_client].setAddress(aux_string);
			break;
		case 5:
			cout << "Insert the new acquired travel packs of the client: ";
			getline(cin, aux_string);

			clients[selected_client].setAcquiredTravelPacks(aux_string);
			break;
		case 6:
			cout << "Insert the new value of total purchases of the client: ";
			cin >> aux_int;
			cin.ignore();

			clients[selected_client].setTotalPurchases(aux_int);
			break;
	}
}

void Menu::createClient() {
	string aux_name;
	int aux_nif;
	int aux_household;
	string aux_client_address;
	string aux_acquired_travel_packs;
	int aux_total_purchases;

	//cout << "What's the name of the new client? ";
	aux_name = readName("What's the name of the new client? ");

	cout << "What's the NIF of the new client? ";
	cin >> aux_nif;
	cin.ignore();

	cout << "What's the household of the new client? ";
	cin >> aux_household;
	cin.ignore();

	cout << "What's the address of the new client? ";
	getline(cin, aux_client_address);
	Address auxClientAddress(aux_client_address);

	cout << "What are the acquired travel packs of the new client? ";
	getline(cin, aux_acquired_travel_packs);
	vector <int> auxAcquiredTravelPacks = str_to_PackageIds(aux_acquired_travel_packs);

	cout << "What's the value of total purchases of the new client? ";
	cin >> aux_total_purchases;
	cin.ignore();

	clients.push_back(Client(aux_name, aux_nif, aux_household, auxClientAddress, auxAcquiredTravelPacks, aux_total_purchases));
}

//Travel Packs Menus

int Menu::showTravelPacks() {

	for (int i = 0; i < size(travelPacks); i++)
		cout << i + 1 << ") " << travelPacks[i].getTravelDestination()[0] << " (" << travelPacks[i].getIdentifier() << ")" << endl;

	int selection = readOption(size(travelPacks));

	return selection;
}

int Menu::showManageTravelPacks() {

	cout << "What do you want to do? Insert the corresponding key." << endl << endl
		<< "1) Create a new travel pack." << endl
		<< "2) Change the information of a travel pack." << endl
		<< "3) Remove an existent travel pack." << endl
		<< "0) Go back." << endl << endl;
		
	int selection = readOption(3);

	return selection;
}

void Menu::manageTravelPacksSelection(int selected) {
	int selected_travel_pack;
	system("cls");

	switch (selected) {
		case 1:
			createTravelPack();			
			break;
		case 2:
			cout << "Which travel pack do you wish to change the information of? Insert the corresponding key." << endl << endl;

			selected_travel_pack = showTravelPacks() - 1;
			changeTravelPacksSelection(showChangeTravelPacks(), selected_travel_pack);
			break;
		case 3:
			cout << "Which travel pack do you wish to remove? Insert the corresponding key." << endl << endl;

			selected_travel_pack = showTravelPacks() - 1;
			AgencyObj.removeTravelPack(selected_travel_pack);
			break;
		case 0:
			break;
	}
}

int Menu::showChangeTravelPacks() {

	cout << "What do you want to change in the travel pack? Insert the corresponding key." << endl << endl
		 << "1) The identifier." << endl
		 << "2) The travel destination." << endl
		 << "3) The departure date." << endl
	 	 << "4) The arrival date." << endl
	 	 << "5) The price." << endl
		 << "6) The number of maximum seats." << endl
		 << "0) Go back." << endl << endl
		 << "Option: " << endl;

	int selection = readOption(6);

	return selection;
}

void Menu::changeTravelPacksSelection(int selected, int selected_travel_pack) {
	int aux_int;
	string aux_string;

	switch (selected) {
		case 1:
			cout << "Insert the new identifier of the travel pack: ";
			cin >> aux_int;
			cin.ignore();

			travelPacks[selected_travel_pack].setIdentifier(aux_int);
			break;
		case 2:
			cout << "Insert the new travel destination of the travel pack (in the format 'Region - Place1, Place2...'): ";
			getline(cin, aux_string);

			travelPacks[selected_travel_pack].setTravelDestination(aux_string);
			break;
		case 3:
			cout << "Insert the new departure date of the travel pack (in the format 'YYYY/MM/DD'): ";
			getline(cin, aux_string);

			travelPacks[selected_travel_pack].setDepartureDate(aux_string);
			break;
		case 4:
			cout << "Insert the new arrival date of the travel pack (in the format 'YYYY/MM/DD'): ";
			getline(cin, aux_string);

			travelPacks[selected_travel_pack].setArrivalDate(aux_string);
			break;
		case 5:
			cout << "Insert the new price of the travel pack: ";
			cin >> aux_int;
			cin.ignore();

			travelPacks[selected_travel_pack].setPrice(aux_int);
			break;
		case 6:
			cout << "Insert the new number of maximum seats of the travel pack: ";
			cin >> aux_int;
			cin.ignore();

			travelPacks[selected_travel_pack].setMaximumSeats(aux_int);
			break;
	}
}

void Menu::createTravelPack() {
	int aux_identifier;
	string aux_travel_destination;
	string aux_date;
	int aux_price;
	int aux_maximum_seats;
	int aux_sold_seats;

	cout << "What's the identifier of the new travel pack? "; 
	cin >> aux_identifier;
	cin.ignore();

	cout << "What's the travel destination of the new travel pack (in the format 'Region - Place1, Place2...')? ";
	getline(cin, aux_travel_destination);

	cout << "What's the departure date of the new travel pack (in the format 'YYYY/MM/DD')? ";
	getline(cin, aux_date);
	Date AuxDepartureDate(aux_date);

	cout << "What's the arrival date of the new travel pack (in the format 'YYYY/MM/DD')? ";
	getline(cin, aux_date);
	Date AuxArrivalDate(aux_date);

	cout << "What's the price of the new travel pack? ";
	cin >> aux_price;
	cin.ignore();

	cout << "What's the number of maximum seats of the new travel pack? ";
	cin >> aux_maximum_seats;
	cin.ignore();

	cout << "What's the number of sold seats of the new travel pack? ";
	cin >> aux_sold_seats;
	cin.ignore();

	travelPacks.push_back(TravelPack(aux_identifier, aux_travel_destination, AuxDepartureDate, AuxArrivalDate, aux_price, aux_maximum_seats, aux_sold_seats));
}



//Reading Function


//Reads an integer between 0 (inclusive if includingZero is true(default) else exclusive) and maxOption(inclusive)
//Returns that value
int Menu::readOption(int maxOptions, bool includingZero) {

	int option;
	if (includingZero) {
		do {
			cout << endl << "Choose your option:  ";
			if (cin >> option && option >= 0 && option <= maxOptions) {
				cin.ignore(1000, '\n');
				return option;
			}
			else {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid input!!" << endl;
			}
		} while (true);
	}
	else {
		do {
			cout << endl << "Choose your option:  ";
			if (cin >> option && option > 0 && option <= maxOptions) {
				cin.ignore(1000, '\n');
				return option;
			}
			else {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid input!!" << endl;
			}
		} while (true);
	}
}
