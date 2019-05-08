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
			int client;
			int pack;
			cout << "Which client do is going to buy a pack? Insert the corresponding key." << endl;
			client = showClients() - 1;
			system("cls");
			cout << "Which travel pack is the client going to buy? Insert the corresponding key." << endl;
			pack = showTravelPacks() - 1;
			system("cls");
			if (travelPacks.at(pack).getIdentifier() < 0)
			{
				cerr << "ERROR:\n This pack is not available anymore (negative ID). Please try again.\n\n";
				cout << "Which travel pack is the client going to buy? Insert the corresponding key." << endl;
				pack = showTravelPacks() - 1;
				system("cls");
			}
			AgencyObj.buyPack(pack, client);
			system("pause");
			break;
		case 8:
			AgencyObj.viewNumberAndValueSoldPacks();
			system("pause");
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

	string aux_string;

	switch (selected) {
		case 1:
			clients[selected_client].setName(readName("Insert the new name of the client: "));
			break;
		case 2:
			clients[selected_client].setNif(readNIF("Insert the new NIF of the client: "));
			cin.ignore();
			break;
		case 3:
			clients[selected_client].setHousehold(readPositiveInt("Insert the new household of the client: "));
			cin.ignore();
			break;
		case 4:
			clients[selected_client].setAddress(readAddress("Insert the new address of the client: "));
			break;
		case 5:
			clients[selected_client].setAcquiredTravelPacks(readBoughtPacks("Insert the new acquired travel packs of the client:(end withCtrl+Z) "));
			break;
		case 6:
			clients[selected_client].setTotalPurchases(readPositiveInt("Insert the new value of total purchases of the client: "));
			cin.ignore();
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

	//cout << "What's the NIF of the new client? ";
	aux_nif = readNIF("What's the NIF of the new client? ");
	cin.ignore();

	//cout << "What's the household of the new client? ";
	aux_household = readPositiveInt("What's the household of the new client? ");
	cin.ignore();

	//cout << "What's the address of the new client? ";
	Address auxClientAddress = readAddress("What's the address of the new client? ");

	//cout << "What are the acquired travel packs of the new client? ";
	vector <int> auxAcquiredTravelPacks = readBoughtPacks("What are the acquired travel packs of the new client?(end with Ctrl+Z) ");

	//cout << "What's the value of total purchases of the new client? ";
	aux_total_purchases = readPositiveInt("What's the value of total purchases of the new client? ");
	cin.ignore();

	clients.push_back(Client(aux_name, aux_nif, aux_household, auxClientAddress, auxAcquiredTravelPacks, aux_total_purchases));
}

//Travel Packs Menus

int Menu::showTravelPacks() {

	for (size_t i = 0; i < size(travelPacks); i++)
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
		<< "0) Go back." << endl << endl;

	int selection = readOption(6);

	return selection;
}

void Menu::changeTravelPacksSelection(int selected, int selected_travel_pack) {

	string aux_string;

	switch (selected) {
		case 1:
			//cout << "Insert the new identifier of the travel pack: ";
			travelPacks[selected_travel_pack].setIdentifier(readInt("Insert the new identifier of the travel pack: "));
			cin.ignore();
			break;
		case 2:
			//cout << "Insert the new travel destination of the travel pack (in the format 'Region - Place1, Place2...'): ";
			travelPacks[selected_travel_pack].setTravelDestination(readDestinations("Insert the new travel destination of the travel pack (end with Ctrl+Z): "));
			break;
		case 3:
			//cout << "Insert the new departure date of the travel pack (in the format 'YYYY/MM/DD'): ";
			travelPacks[selected_travel_pack].setDepartureDate(readDate("Insert the new departure date of the travel pack(in the format 'YYYY/MM/DD') : "));
			break;
		case 4:
			//cout << "Insert the new arrival date of the travel pack (in the format 'YYYY/MM/DD'): ";
			travelPacks[selected_travel_pack].setArrivalDate(readDate("Insert the new arrival date of the travel pack (in the format 'YYYY/MM/DD'): "));
			break;
		case 5:
			//cout << "Insert the new price of the travel pack: ";
			travelPacks[selected_travel_pack].setPrice(readPositiveInt("Insert the new price of the travel pack: "));
			cin.ignore();
			break;
		case 6:
			//cout << "Insert the new number of maximum seats of the travel pack: ";
			travelPacks[selected_travel_pack].setMaximumSeats(readPositiveInt("Insert the new number of maximum seats of the travel pack: "));
			cin.ignore();
			break;
	}
}

void Menu::createTravelPack() {

	//cout << "What's the identifier of the new travel pack? "; 
	int aux_identifier = readInt("What's the identifier of the new travel pack? ");
	cin.ignore();

	//cout << "What's the travel destination of the new travel pack (in the format 'Region - Place1, Place2...')? ";
	vector <string> aux_travel_destination = readDestinations("What's the travel destination of the new travel pack (in the format 'Region - Place1, Place2...')? ");

	//cout << "What's the departure date of the new travel pack (in the format 'YYYY/MM/DD')? ";
	Date AuxDepartureDate = readDate("What's the departure date of the new travel pack (in the format 'YYYY/MM/DD')? ");

	//cout << "What's the arrival date of the new travel pack (in the format 'YYYY/MM/DD')? ";
	Date AuxArrivalDate = readDate("What's the arrival date of the new travel pack (in the format 'YYYY/MM/DD')? ");

	//cout << "What's the price of the new travel pack? ";
	int aux_price = readPositiveInt("What's the price of the new travel pack? ");
	cin.ignore();

	//cout << "What's the number of maximum seats of the new travel pack? ";
	int aux_maximum_seats = readPositiveInt("What's the number of maximum seats of the new travel pack? ");
	cin.ignore();

	//cout << "What's the number of sold seats of the new travel pack? ";
	int aux_sold_seats = readPositiveInt("What's the number of sold seats of the new travel pack? ");
	cin.ignore();

	travelPacks.push_back(TravelPack(aux_identifier, aux_travel_destination, AuxDepartureDate, AuxArrivalDate, aux_price, aux_maximum_seats, aux_sold_seats));
}
