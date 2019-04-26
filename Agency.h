#pragma once
#include <string>
#include "Address.h"

using namespace std;

class Agency {
	public:
	private:
		string Name;
		int NIF;
		string URL;
		Address AgencyAddress;
		string ClientsFile;
		string TravelPacksFile;
};
