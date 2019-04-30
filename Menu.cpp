#include "Menu.h"

Menu::Menu(Agency AgencyObj) {
	this->AgencyObj = AgencyObj;
}

int Menu::showMenu() {
	int selection;
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
		 << "10) Obtain a list of the clients with one of the travel packs with one of the most visited places." << endl << endl
		 << "0) Exit the program and save the alterations made." << endl;

	cin >> selection;
	cin.ignore();

	return selection;
}

void Menu::menuSelection(int selected) {
	system("cls");

	switch (selected) {
		case 1:
			cout << "Not working. In construction.";
			break;
		case 2:
			manageTravelPacksSelection(showManageTravelPacks());
			break;
		case 3:
			cout << "Not working. In construction.";
			break;
		case 4:
			cout << "Not working. In construction.";
			break;
		case 5:
			cout << "Not working. In construction.";
			break;
		case 6:
			cout << "Not working. In construction.";
			break;
		case 7:
			cout << "Not working. In construction.";
			break;
		case 0:
			break;
	}
}

int Menu::showTravelPacks() {
	int selection;

	for (int i = 0; i < size(AgencyObj.getTravelPacksObjs()); i++)
		cout << i + 1 << ") " << AgencyObj.getTravelPacksObjs()[i].getTravelDestination()[0] << " (" << AgencyObj.getTravelPacksObjs()[i].getIdentifier() << ")" << endl;

	cin >> selection;
	cin.ignore();

	return selection;
}

int Menu::showManageTravelPacks() {
	int selection;

	cout << "What do you want to do ? Insert the corresponding key." << endl << endl
		 << "1) Create a new travel pack." << endl
		 << "2) Change the information of a travel pack." << endl
	 	 << "3) Remove an existent travel pack." << endl
		 << "0) Go back." << endl;

	cin >> selection;
	cin.ignore();

	return selection;
}

void Menu::manageTravelPacksSelection(int selected) {
	int selectedTravelPack;
	system("cls");

	switch (selected) {
		case 1:
			createTravelPack();			
			break;
		case 2:
			cout << "Which travel pack do you wish to change the information of? Insert the corresponding key. " << endl << endl;

			selectedTravelPack = showTravelPacks() - 1; //Apresenta o menu de seleção do pacote a alterar
			changeTravelPacksSelection(showChangeTravelPacks(), selectedTravelPack);
			break;
		case 3:
			cout << "Not working. In construction.";
			break;
		case 0:
			break;
	}

	menuSelection(showMenu()); //Or go back (return)
}

int Menu::showChangeTravelPacks() {
	int selection;

	cout << "What do you want to change in the travel pack? Insert the corresponding key." << endl << endl
		 << "1) The identifier." << endl
		 << "2) The travel destination." << endl
		 << "3) The departure date." << endl
	 	 << "4) The arrival date." << endl
	 	 << "5) The price." << endl
		 << "6) The number of maximum seats." << endl
		 << "0) Go back." << endl;

	cin >> selection;
	cin.ignore();

	return selection;
}

void Menu::changeTravelPacksSelection(int selected, int selectedTravelPack) {
	int aux_int;
	string aux_string;

	switch (selected) {
		case 1:
			cout << "Insert the new identifier of the travel pack: ";
			cin >> aux_int;
			cin.ignore();

			AgencyObj.travelPacksObjs[selectedTravelPack].setIdentifier(aux_int); 
			break;
		case 2:
			cout << "Insert the new travel destination of the travel pack (in the format 'Region - Place1, Place2...'): ";
			getline(cin, aux_string);

			AgencyObj.travelPacksObjs[selectedTravelPack].setTravelDestination(aux_string);
			break;
		case 3:
			cout << "Insert the new departure date of the travel pack (in the format 'YYYY/MM/DD'): ";
			getline(cin, aux_string);

			AgencyObj.travelPacksObjs[selectedTravelPack].setDepartureDate(aux_string);
			break;
		case 4:
			cout << "Insert the new arrival date of the travel pack (in the format 'YYYY/MM/DD'): ";
			getline(cin, aux_string);

			AgencyObj.travelPacksObjs[selectedTravelPack].setArrivalDate(aux_string);
			break;
		case 5:
			cout << "Insert the new price of the travel pack: ";
			cin >> aux_int;
			cin.ignore();

			AgencyObj.travelPacksObjs[selectedTravelPack].setPrice(aux_int);
			break;
		case 6:
			cout << "Insert the new number of maximum seats of the travel pack: ";
			cin >> aux_int;
			cin.ignore();

			AgencyObj.travelPacksObjs[selectedTravelPack].setMaximumSeats(aux_int);
			break;
	}
}

void Menu::createTravelPack() {
	int aux_identifier;
	string aux_travel_destination;
	string aux_date;
	int aux_price;
	int aux_maximum_seats;

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

	AgencyObj.travelPacksObjs.push_back(TravelPack(aux_identifier, aux_travel_destination, AuxDepartureDate, AuxArrivalDate, aux_price, aux_maximum_seats));
}
