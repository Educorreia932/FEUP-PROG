#pragma once
#include <vector>
#include <string>
#include "Address.h"

using namespace std;

class Client {
	public:
		Client(string name, int nif, int household, Address ClientAddress, vector <int> AcquiredTravelPacks, int total_purchases);
	private:
		string name;
		int nif;
		int household;
		Address ClientAddress;			
		vector <int> AcquiredTravelPacks; 
		int total_purchases; 
};
