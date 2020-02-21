#pragma once
#include "Auxiliary.h"

using namespace std;

class Address {
	public:
		//Constructors
		Address();
		Address(string line);
		Address(string street, int door_number, string apartment, string zip_code, string locality);

		//Getters
		string getStreet();
		int getDoorNumber();
		string getApartment();
		string getZipCode();
		string getLocality();
	private:
		string street;
		int door_number;
		string apartment;
		string zip_code;
		string locality;
};
