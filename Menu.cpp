#include "Menu.h"
#define clients AgencyObj.clientsObjs
#define travelPacks AgencyObj.travelPacksObjs	

//Constructor
Menu::Menu(Agency AgencyObj) {
	this->AgencyObj = AgencyObj;
}

/*
	�Show� functions - Mostram menu de sele��o e retornam op��o selecionada
	�Selection� functions - "Switch cases", fazem a��es diferentes conforme o selecionado
*/

int Menu::showMenu() {
	clearScreen();

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
		<< "10) Obtain a list of the clients with one of the travel packs with one of the most visited places." << endl
		<< "11) Visualize agency's info.\n" 
		<< "0) Exit the program and save the alterations made." << endl;
	
	int selection = readOption(11); // Mudar para outro valor se se acrescentar alguma coisa

	return selection;
}

void Menu::menuSelection(int selected) {
	clearScreen();
	vector<string> places;
	vector <Client> Clients;

	switch (selected) {
		case 1:
			manageClientsSelection(showManageClients());
			break;
		case 2:
			manageTravelPacksSelection(showManageTravelPacks());
			break;
		case 3:
			cout << "Which client do you wish to check the information of? Insert the corresponding key." << endl << endl;
			option = showClients();
			if (option >= 1)
			{
				AgencyObj.viewSpecificClient(option-1);
			pause();
			}
			else (showMenu());
			break;
		case 4:
			AgencyObj.viewAllClients();
			pause();
			break;
		case 5:
			AgencyObj.viewAvailablePacks();
			pause();
			break;
		case 6:
			AgencyObj.viewSoldPacks();
			pause();
			break;
		case 7:
			int selected_client, pack;

			cout << "Which client is going to buy a pack? Insert the corresponding key." << endl << endl;
			
			selected_client = showClients() - 1;
			clearScreen();

			if (!(selected_client + 1)) { //Op��o de voltar para tr�s
				menuSelection(showMenu());
				return;
			}
			
			cout << "Which travel pack is the client going to buy? Insert the corresponding key." << endl;
			pack = showTravelPacks() - 1;
			clearScreen();

			if (travelPacks.at(pack).getIdentifier() < 0) {
				cerr << "ERROR:\n This pack is not available anymore (negative ID). Please try again.\n\n";
				cout << "Which travel pack is the client going to buy? Insert the corresponding key." << endl;
				pack = showTravelPacks() - 1;
				clearScreen();
			}

			AgencyObj.buyPack(pack, selected_client);
			pause();
			break;
		case 8:
			AgencyObj.viewNumberAndValueSoldPacks();
			pause();
			break;
		case 9:
			places = AgencyObj.mostVisitedPlaces();
			if (places.empty())
				cout << "This agency has no travel packs.\n\n";
			else
			{
				cout << "The most visited place(s):\n";

				for (size_t k = 0; k < places.size(); k++)
					cout << places.at(k) << '\n';
				cout << '\n';
			}

			pause();
			break; 
		case 10:
			places = AgencyObj.mostVisitedPlaces();
			Clients = AgencyObj.clientsWithPacksWithPlaces(places);

			if (Clients.empty())
				cout << "There are no clients with travel packs for the most visited places.\n\n";

			else
			{
				cout << "Clients:\n";

				for (size_t k = 0; k < Clients.size(); k++)
				{
					Clients.at(k).show();
				}
			}

			system("pause");
			break;
		/*case 10:
			AgencyObj.viewMostVisitedPlaces()
			system("pause");
			break;*/
		case 11:
			AgencyObj.show();
			pause();
			break;
		case 0:
			AgencyObj.updateClientFile();
			AgencyObj.updatePacksFile();
			return;
	}

	menuSelection(showMenu());
}

//Clients Menus

int Menu::showClients() {
	for (size_t i = 0; i < size(clients); i++)
		cout << i + 1 << ") " << clients[i].getName() << " (" << clients[i].getNif() << ")" << endl;

	cout << "0) Go back." << endl;

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
	clearScreen();

	switch (selected) {
		case 1:
			createClient();
			break;
		case 2:
			cout << "Which client do you wish to change the information of? Insert the corresponding key." << endl << endl;

			selected_client = showClients() - 1;
			clearScreen();

			if (!(selected_client + 1)) { //Op��o de voltar para tr�s
				manageClientsSelection(showManageClients());
				return;
			}
				
			changeClientsSelection(showChangeClients(), selected_client);
			break;
		case 3:
			cout << "Which client do you wish to remove? Insert the corresponding key." << endl << endl;

			selected_client = showClients() - 1;

			if (!(selected_client + 1)) { //Op��o de voltar para tr�s
				manageClientsSelection(showManageClients());
				return;
			}

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
		 << "0) Go back." << endl;

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

	aux_name = readName("What's the name of the new client? ");

	aux_nif = readNIF("What's the NIF of the new client? ");
	cin.ignore();

	aux_household = readPositiveInt("What's the household of the new client? ");
	cin.ignore();

	Address auxClientAddress = readAddress("What's the address of the new client? ");

	vector <int> auxAcquiredTravelPacks = readBoughtPacks("What are the acquired travel packs of the new client?(end with Ctrl+Z) ");

	aux_total_purchases = readPositiveInt("What's the value of total purchases of the new client? ");
	cin.ignore();

	clients.push_back(Client(aux_name, aux_nif, aux_household, auxClientAddress, auxAcquiredTravelPacks, aux_total_purchases));
}

//Travel Packs Menus

int Menu::showTravelPacks() {
	for (size_t i = 0; i < size(travelPacks); i++)
		cout << i + 1 << ") " << travelPacks[i].getTravelDestination()[0] << " (" << travelPacks[i].getIdentifier() << ")" << endl;

	cout << "0) Go back." << endl;

	int selection = readOption(size(travelPacks));

	return selection;
}

int Menu::showManageTravelPacks() {
	cout << "What do you want to do? Insert the corresponding key." << endl << endl
		<< "1) Create a new travel pack." << endl
		<< "2) Change the information of a travel pack." << endl
		<< "3) Remove an existent travel pack." << endl
		<< "0) Go back." << endl;
		
	int selection = readOption(3);

	return selection;
}

void Menu::manageTravelPacksSelection(int selected) {
	int selected_travel_pack;
	clearScreen();

	switch (selected) {
		case 1:
			createTravelPack();			
			break;
		case 2:
			cout << "Which travel pack do you wish to change the information of? Insert the corresponding key." << endl << endl;

			selected_travel_pack = showTravelPacks() - 1;
			clearScreen();
			
			if (!(selected_travel_pack + 1)) { //Op��o de voltar para tr�s
				manageTravelPacksSelection(showManageTravelPacks());
				return;
			}

			//Show travel pack
			cout << "Current Travel Pack Information: \n\n";
			clearScreen();
			AgencyObj.getTravelPacksObjs().at(selected_travel_pack).show();
			changeTravelPacksSelection(showChangeTravelPacks(), selected_travel_pack);
			break;
		case 3:
			cout << "Which travel pack do you wish to remove? Insert the corresponding key." << endl << endl;

			selected_travel_pack = showTravelPacks() - 1;

			if (!(selected_travel_pack + 1)) { //Op��o de voltar para tr�s
				manageTravelPacksSelection(showManageTravelPacks());
				return;
			}
			AgencyObj.removeTravelPack(selected_travel_pack);
			break;
		case 0:
			break;
	}
}

int Menu::showChangeTravelPacks() {
	cout << "\nWhat do you want to change in the travel pack? Insert the corresponding key." << endl << endl
		 << "1) The identifier." << endl
		 << "2) The travel destination." << endl
		 << "3) The departure date." << endl
		 << "4) The arrival date." << endl
		 << "5) The price." << endl
		 << "6) The number of maximum seats." << endl
		 << "7) The number of sold seats." << endl
		 << "0) Go back." << endl;

	int selection = readOption(7);

	return selection;
}

void Menu::changeTravelPacksSelection(int selected, int selected_travel_pack) {
	string aux_string;

	cout << '\n';
	switch (selected) {
		case 1:
			travelPacks[selected_travel_pack].setIdentifier(readInt("Insert the new identifier of the travel pack: "));
			cin.ignore();
			break;
		case 2:
			travelPacks[selected_travel_pack].setTravelDestination(readDestinations("Insert the new travel destination of the travel pack (end with Ctrl+Z): "));
			break;
		case 3:
			travelPacks[selected_travel_pack].setDepartureDate(readArrivalDate("Insert the new departure date of the travel pack(in the format 'YYYY/MM/DD'): ", travelPacks[selected_travel_pack].getDepartureDate()));
			break;
		case 4:
			travelPacks[selected_travel_pack].setArrivalDate(readDepartureDate("Insert the new arrival date of the travel pack (in the format 'YYYY/MM/DD'): ", travelPacks[selected_travel_pack].getArrivalDate()));
			break;
		case 5:
			travelPacks[selected_travel_pack].setPrice(readPositiveInt("Insert the new price of the travel pack: "));
			cin.ignore();
			break;
		case 6:
			travelPacks[selected_travel_pack].setMaximumSeats(readMaximumSeats("Insert the new number of maximum seats of the travel pack: ", travelPacks[selected_travel_pack].getSoldSeats()));
			cin.ignore();
			break;
		case 7:
			travelPacks[selected_travel_pack].setSoldSeats(readSoldSeats("Insert the new number of sold seats of the travel pack: ", travelPacks[selected_travel_pack].getMaximumSeats()));
			cin.ignore();
			break;
		case 0:
			break;
	}
}

void Menu::createTravelPack() {
	int aux_identifier = readInt("What's the identifier of the new travel pack? ");
	cin.ignore();

	vector <string> aux_travel_destination = readDestinations("What's the travel destination of the new travel pack (in the format 'Region - Place1, Place2...')? ");

	Date AuxDepartureDate = readDepartureDate("What's the departure date of the new travel pack (in the format 'YYYY/MM/DD')? ", Date(0000, 01, 01));

	Date AuxArrivalDate = readArrivalDate("What's the arrival date of the new travel pack (in the format 'YYYY/MM/DD')? ", AuxDepartureDate);

	int aux_price = readPositiveInt("What's the price of the new travel pack? ");
	cin.ignore();

	int aux_maximum_seats = readPositiveInt("What's the number of maximum seats of the new travel pack? ");
	cin.ignore();

	int aux_sold_seats = readPositiveInt("What's the number of sold seats of the new travel pack? ");
	cin.ignore();

	travelPacks.push_back(TravelPack(aux_identifier, aux_travel_destination, AuxDepartureDate, AuxArrivalDate, aux_price, aux_maximum_seats, aux_sold_seats));
}
