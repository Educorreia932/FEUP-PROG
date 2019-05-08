#pragma once
#include "Auxiliary.h"

using namespace std;

string trim(string s);//Necess�rio porque se incluirmos o Auxiliary.h d� erro

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
