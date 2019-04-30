#include "Menu.h"

Menu::Menu(Agency AgencyObj) {
	this->AgencyObj = AgencyObj;
}

int Menu::showMenu() {
	int selection;

	cout << "What do you want to do? Insert the corresponding key." << endl << endl
		 << "1) Manage clients." << endl
		 << "2) Manage travel packs." << endl
		 << "3) Visualize a specific client." << endl
		 << "4) Visualize all the clients of the agency." << endl
		 << "5) Visualize available travel packs." << endl
	 	 << "6) Visualize sold travel packs." << endl
		 << "7) Buy a travel pack for a client." << endl
		 << "0) Exit the program and save the alterations made." << endl;

	cin >> selection;
	cin.ignore();

	return selection;
}

void Menu::menuSelection(int selected) {
	system("cls");

	switch (selected) {
		case 1:
			break;
		case 2:
			manageTravelPacksSelection(showManageTravelPacks());
			break;
		case 3:
			break;
		case 0:
			break;
	}
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
	system("cls");

	switch (selected) {
		case 1:
			cout << "Which travel pack do you wish to change the information of? Insert the corresponding key. " << endl << endl;

			showChangeTravelPacks(); //Apresenta o menu de seleção do pacote a alterar
			manageTravelPacksSelection(showChangeTravelPacks());

			cout << endl;
			break;
		case 2:
			break;
		case 3:
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

int Menu::showChangeTravelPacks() {
	int selection;

	cout << "What do you want to change in the travel pack? Insert the corresponding key." << endl << endl
		 << "1) The identifier." << endl
		 << "2) The travel destination." << endl
		 << "3) The departure date." << endl
	 	 << "4) The arrival date." << endl
	 	 << "5) The price." << endl
		 << "6) The initially available seats." << endl
		 << "7) The sold seats." << endl
		 << "0) Go back." << endl;

	cin >> selection;
	cin.ignore();

	return selection;
}

void Menu::manageTravelPacksSelection(int selected) {
	switch (selected) {
		case 1:
			//Identifier
		case 2:
	}
}
