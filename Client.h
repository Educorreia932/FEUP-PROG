#pragma once
#include <vector>
#include "Address.h"

using namespace std;

class Client {
	public:
		Client();
		Client(string file_name);
	private:
		string name;
		int nif;
		int household;
		Address ClientAddress;			
		vector <int> AdquiredTravelPacks; 
		int total_purchases; 
};
