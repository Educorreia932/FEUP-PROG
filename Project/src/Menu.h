#pragma once
#include "Agency.h"
#undef clients
#undef travelPacks
#define clients AgencyObj.clientsObjs
#define travelPacks AgencyObj.travelPacksObjs

class Menu {
	public:
		//Constructor
		Menu(Agency AgencyObj);

		int showMenu();
		void menuSelection(int selected);
	private:
		//Variables/Data Structures
		Agency AgencyObj;

		//Clients Menus
		int showClients();

		int showManageClients();
		void manageClientsSelection(int selected);
		
		int showChangeClients();
		void changeClientsSelection(int selected, int selected_client);

		void createClient();

		//Travel Packs Menus
		int showTravelPacks();

		int showManageTravelPacks();
		void manageTravelPacksSelection(int selected);		

		int showChangeTravelPacks();
		void changeTravelPacksSelection(int selected, int selected_travel_pack);

		void createTravelPack();		
};