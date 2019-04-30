#pragma once
#include <vector>
#include <string>
#include "Address.h"

using namespace std;

class Client {
	public:
		Client(string name, int nif, int household, Address ClientAddress, vector <int> AcquiredTravelPacks, int total_purchases);
		string getName() const;
		int getNif() const;
		int getHousehold() const;
		Address getClientAddress() const;
		vector <int> getAcquiredTravelPacks() const;
		int getTotalPurchases() const;

	private:
		string name;
		int nif;
		int household;
		Address ClientAddress;			
		vector <int> AcquiredTravelPacks; 
		int totalPurchases; 
};
