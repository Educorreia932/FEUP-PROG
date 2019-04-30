#pragma once
#include "Agency.h"

class Menu {
	public:
		Menu(Agency AgencyObj);

		int showMenu();
		void menuSelection(int selected);
	private:
		Agency AgencyObj;
		int showManageTravelPacks();
		void manageTravelPacksSelection(int selected);
		int showTravelPacks();
		int showChangeTravelPacks();
		void manageTravelPacksSelection(int selected);
};