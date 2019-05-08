#pragma once
#include <vector>
#include <string>
#include "Address.h"

using namespace std;

class Client {
	public:
		Client(string name, int nif, int household, Address ClientAddress, vector <int> AcquiredTravelPacks, int total_purchases);

		//Getters
		string getName() const;
		int getNif() const;
		int getHousehold() const;
		Address getClientAddress() const;
		vector <int> getAcquiredTravelPacks() const;
		int getTotalPurchases() const;

		//Setters
		void setName(string name);
		void setNif(int nif);
		void setHousehold(int household);
		void setAddress(string client_address);
		void setAddress(Address new_address);
		void setAcquiredTravelPacks(string adcquired_travel_packs);
		void setAcquiredTravelPacks(vector<int> adcquired_travel_packs);
		void setTotalPurchases(int total_purchases);
	private:
		//Variables/Data Structures
		string name;
		int nif;
		int household;
		Address ClientAddress;			
		vector <int> AcquiredTravelPacks; 
		int totalPurchases; 
};
