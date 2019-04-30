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

		//Function
		int showTravelPacks();

		int showManageTravelPacks();
		void manageTravelPacksSelection(int selected);		

		int showChangeTravelPacks();
		void changeTravelPacksSelection(int selected, int selectedTravelPack);

		void createTravelPack();
};