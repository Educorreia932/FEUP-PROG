#pragma once
#include <string>
#include <vector>
#include "Address.h"

using namespace std;

class Client {
	public:
	private:
		string Name;
		int NIF;
		int Household;
		Address ClientAddress;
		vector <int> AdquiredTravelPacks;
};
