#include <iostream>
#include <vector>
#include "ReadFunctions.h"
#include "Structs.h"
#include "GetFunctions.h"
#include "AuxiliaryFunctions.h"

int readNIF() {
	int input;
	
	do {
		if (std::cin >> input && input >= 100000000 && input <= 999999999)
			return input;

		else {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input! Insert again: ";
		}
		
	} while (true);
}

int readHousehold() {
	int input;

	do {
		if (std::cin >> input && input > 0)
			return input;

		else {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input! Insert again: ";
		}

	} while (true);
}

int readIdentifier(std::vector <TravelPack> StructTravelPacks) { //Tem de ser diferente de algum já existente
	int input; 

	do {
		if (std::cin >> input && input >= 0)
			return input;

		else {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input! Insert again: ";
		}

	} while (true);
}

int readPrice() {
	int input;

	do {
		if (std::cin >> input && input >= 0)
			return input;

		else {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input! Insert again: ";
		}

	} while (true);
}

int readSeats(char mode, int InitialSeats, int SoldSeats) {
	int input;

	do {
		if (std::cin >> input && input > 0) {
			if (mode == 'I' && input >= SoldSeats)
				return input;

			else if (mode == 'S' && input <= InitialSeats)
				return input;

			else {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Invalid input! Insert again: ";
			}
		}

		else {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input! Insert again: ";
		}

	} while (true);
}

bool readDate(std::string StringDate) {
	Date AuxDate;

	getDate(AuxDate, StringDate);

	if (AuxDate.Year < 0 || AuxDate.Month < 0 || AuxDate.Month > 12 || AuxDate.Day > numberOfDays(AuxDate.Month, AuxDate.Year) || AuxDate.Day < 0)
		return false;

	else
		return true;
} //Arrival antes de departures e vice-versa //Copiar READ Fractions

int readSelection(int interval_minimum, int interval_maximum) {
	int input;

	do {
		if (std::cin >> input && input >= interval_minimum && input <= interval_maximum)
			return input;

		else {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input! Insert again: ";
		}

	} while (true);
}