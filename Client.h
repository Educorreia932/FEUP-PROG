#pragma once
#include <vector>
#include <string>
#include "Address.h"

using namespace std;

class Client {
	public:
		Client(string name, int nif, int household, Address ClientAddress, vector <int> AcquiredTravelPacks, int total_purchases);
		string getName();
		int getNif();
		int getHousehold();
		Address getClientAddress();
		vector <int> getAcquiredTravelPacks();
		int getTotalPurchases();

	private:
		string name;
		int nif;
		int household;
		Address ClientAddress;			
		vector <int> AcquiredTravelPacks; 
		int totalPurchases; 
};
