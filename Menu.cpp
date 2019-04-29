#include "Menu.h"

Menu::Menu(Agency AgencyObj) {
	this->AgencyObj = AgencyObj;
}

int Menu::show() {
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
