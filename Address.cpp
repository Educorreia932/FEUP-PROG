#include "Address.h"

Address::Address() {
	this->street = "N/A";
	this->door_number = -1;
	this->apartment = "N/A";
	this->zip_code = "N/A";
}

Address::Address(string line) {
	int counter = 0;
	string aux_string;

	for (size_t i = 0; i < line.length(); i++) {
		if (line[i] == '/') {
			switch (counter) {
				case 0:
					this->street = trim(aux_string);
					break;
				case 1:
					this->door_number = stoi(aux_string);
					break;
				case 2:
					this->apartment = trim(aux_string);
					break;
				case 3:
					this->zip_code = trim(aux_string);
					break;
			}

			aux_string = "";
			counter += 1;
		}

		else
			aux_string += line[i];
	}

	this->locality = trim(aux_string);
}

string Address::getStreet() {
	return this->street;
}

int Address::getDoorNumber() {
	return this->door_number;
}

string Address::getApartment() {
	return this->apartment;
}

string Address::getZipCode() {
	return this->zip_code;
}

string Address::getLocality() {
	return this->locality;
}