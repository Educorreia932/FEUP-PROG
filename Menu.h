#pragma once
#include "Agency.h"

class Menu {
	public:
		Menu(Agency AgencyObj);

		int showMenu();
		void menuSelection(int selected);
	private:
		//Variables/Data Structure
		Agency AgencyObj;

		//Clients Menus
		int showClients();

		int showManageClients();
		void manageClientsTravelPacksSelection(int selected);
		
		int showChangeClients();
		void changeClientsSelection(int selected, int selected_client);

		void createClient();
		void removeClient();

		//Travel Packs Menus
		int showTravelPacks();

		int showManageTravelPacks();
		void manageTravelPacksSelection(int selected);		

		int showChangeTravelPacks();
		void changeTravelPacksSelection(int selected, int selected_travel_pack);

		void createTravelPack();
		void removeTravelPack();		
};