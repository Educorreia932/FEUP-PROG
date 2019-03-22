#include <string>
#include "GetFunctions.h"
#include "AuxiliaryFunctions.h"

void GetAddress(Address &Address, std::string Line) {
	int Counter = 0;
	std::string AuxString;

	for (int i = 0; i < Line.length(); i++) {
		if (Line[i] == '/') {
			switch (Counter) {
			case 0:
				Address.Street = Trim(AuxString);
				break;
			case 1:
				Address.DoorNumber = stoi(AuxString);
				break;
			case 2:
				Address.Apartment = Trim(AuxString);
				break;
			case 3:
				Address.ZIPCode = Trim(AuxString);
				break;
			}

			AuxString = "";
			Counter += 1;
		}

		else
			AuxString += Line[i];
	}

	Address.Province = Trim(AuxString);
}

void GetDate(Date &Date, std::string Line) {
	int Counter = 0;
	std::string StringAux;

	for (int i = 0; i < Line.length(); i++) {
		if (Line[i] == '/') {
			switch (Counter) {
			case 0:
				Date.Year = stoi(StringAux);
				break;
			case 1:
				Date.Month = stoi(StringAux);
				break;
			}

			StringAux = "";
			Counter += 1;
		}

		else
			StringAux += Line[i];
	}

	Date.Day = stoi(StringAux);
}