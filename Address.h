#pragma once
#include <string>

using namespace std;

class Address {
	public:
		Address(string street, unsigned int door_number, string apartment, string zip_code, string province);
	private:
		string street;
		unsigned int door_number;
		string apartment;
		string zip_code;
		string province;
};
