#include <string>
#include "GetFunctions.h"
#include "AuxiliaryFunctions.h"

std::vector <int> GetAdquiredTravelPacks(std::string Line) {
	std::vector <int> Result;
	std::string AuxString;

	for (int i = 0; i < Line.length(); i++) {
		if (Line[i] == ';') {
			Result.push_back(stoi(AuxString));
			AuxString = "";
		}

		else
			AuxString += Line[i];
	}

	Result.push_back(stoi(AuxString));

	return Result;
}

std::vector <std::string> GetTravelDestination(std::string Line) {
	std::vector <std::string> Result;
	std::string AuxString;

	for (int i = 0; i < Line.length(); i++) {
		if (Line[i] == '–' || Line[i] == ',' || Line[i] == '-') {
			Result.push_back(Trim(AuxString));
			AuxString = "";
		}

		else {
			AuxString += Line[i];
		}
	}

	Result.push_back(Trim(AuxString));

	return Result;
}

void GetAddress(Address &Address, std::string Line) { // Colocar a retornar struct
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