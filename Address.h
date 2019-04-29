#pragma once
#include "Auxiliary.h"

using namespace std;

class Address {
	public:
		Address();
		Address(string line);
	private:
		string street;
		int door_number;
		string apartment;
		string zip_code;
		string locality;
};
