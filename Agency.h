#pragma once
#include <fstream>
#include <iomanip> 
#include "Client.h"
#include "TravelPack.h"

using namespace std;

class Agency {
	public:
		//Constructors
		Agency();
		Agency(string file_name);

		//Getters
		vector <TravelPack> getTravelPacksObjs() const;
		string getClientsFile() const;
		string getTravelPacksFile() const;

		//View functions
		void viewAllClients() const;
		void viewSpecificClient(size_t index) const;
		void viewAvailablePacks() const;
		void viewSoldPacks() const;
		void buyPack(int pack_index, int client_index);

	private:
		//Variables/Data Structures
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

		void removeTravelPack(int selected);
		void removeClient(int selected);

		friend class Menu;
};
