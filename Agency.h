#pragma once
#include <fstream>
#include "Client.h"
#include "TravelPack.h"

using namespace std;

class Agency {
	public:
		Agency();
		Agency(string file_name);
		vector <TravelPack> getTravelPacksObjs() const;
		string getClientsFile() const;
		string getTravelPacksFile() const;
	private:
		//Variables/Data Structure
		string name;
		int nif;
		Address AgencyAddress;
		string url;
		string clients_file;
		string travelpacks_file;
		vector <Client> clientsObjs;
		vector <TravelPack> travelPacksObjs;

		//Functions
		vector <TravelPack> readTravelPacks(string file_name);
		vector <Client> readClients(string file_name);

		void updateClientFile();
		void updatePacksFile();

		friend class Menu;
};
