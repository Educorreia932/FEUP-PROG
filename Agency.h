#pragma once
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

		//View functions - To visualize information about packs, clients and the agency
		void viewAllClients() const;
		void viewSpecificClient(size_t index);
		void viewAvailablePacks() const;
		void viewSoldPacks() const;
		void viewNumberAndValueSoldPacks() const;
		void show(); //Display information about the agency

		//Other
		vector<int> packsWithMostVisitedPlaces(vector<string> &places);
		vector<string> mostVisitedPlaces();
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

		//Read Functions
		vector <TravelPack> readTravelPacks(string file_name);
		vector <Client> readClients(string file_name);

		//Update Functions - Saves the alterations made to the respective files
		void updateClientFile();
		void updatePacksFile();

		//Remove Functions
		void removeTravelPack(int selected);
		void removeClient(int selected);

		friend class Menu;
};
