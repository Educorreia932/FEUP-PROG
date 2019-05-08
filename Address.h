#pragma once
#include "Auxiliary.h"

using namespace std;

string trim(string s);//Necessário porque se incluirmos o Auxiliary.h dá erro

class Address {
	public:
		Address();
		Address(string line);
		Address(string street, int door_number, string apartment, string zip_code, string locality);

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
