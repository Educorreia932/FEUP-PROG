#pragma once
#include <string>
#include <vector>
#include "Address.h"

using namespace std;

class Client {
	public:
		Client();
	private:
		string name;
		unsigned int nif;
		unsigned int household;
		Address ClientAddress;			
		vector <int> AdquiredTravelPacks; //Mudar para vector <TravelPack> (?)
		unsigned int total_purchases; //int ou outro tipo (?)
};
