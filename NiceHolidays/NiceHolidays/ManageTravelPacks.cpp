#include <iostream>
#include "ManageTravelPacks.h"
#include "Structs.h"
#include "GetFunctions.h"
#include "ValidateFunctions.h"

TravelPack CreateTravelPack(std::vector <TravelPack> &StructTravelPacks) {
	TravelPack AuxStruct;
	std::string AuxString;

	std::cout << "What's the identifier of the travel pack? ";
	std::cin >> AuxStruct.Identifier;
	std::cin.ignore();
	std::cout << "What's the travel destination of the travel pack (in the format 'Region - Place1, Place2...')? " << std::endl;
	getline(std::cin, AuxString);
	AuxStruct.TravelDestination = GetTravelDestination(AuxString);
	std::cout << "What's the departure date of the travel pack (in the format 'YYYY/MM/DD')? ";
	getline(std::cin, AuxString);
	GetDate(AuxStruct.DepartureDate, AuxString);
	std::cout << "What's the arrival date of the travel pack (in the format 'YYYY/MM/DD')? ";
	getline(std::cin, AuxString);
	GetDate(AuxStruct.ArrivalDate, AuxString);
	std::cout << "What's the price of the travel pack? ";
	std::cin >> AuxStruct.Price;
	std::cin.ignore();
	std::cout << "How many are the initially available seats? ";
	std::cin >> AuxStruct.InitiallyAvailableSeats;
	std::cin.ignore();
	std::cout << "How many are the sold seats? ";
	std::cin >> AuxStruct.SoldSeats;
	std::cin.ignore();

	return AuxStruct;
}

void ChangeTravelPack(int TravelPackNumber, std::vector <TravelPack> &StructTravelPacks) {
	int Selection;
	std::string AuxString;

	std::cout << "What do you want to change in the travel pack? Insert the corresponding key." << std::endl << std::endl
		      << "1) Everything." << std::endl
		      << "2) The identifier." << std::endl
		      << "3) The travel destination." << std::endl
		      << "4) The departure date." << std::endl
		      << "5) The arrival date." << std::endl
		      << "6) The price." << std::endl
		      << "7) The initially available seats." << std::endl
		      << "8) The sold seats." << std::endl;
	std::cin >> Selection;
	std::cin.ignore();
	std::cout << std::endl;

	switch (Selection) {
		case 1:
			break;
		case 2:
			std::cout << "Insert the new identifier of the travel pack: ";
			std::cin >> StructTravelPacks[TravelPackNumber].Identifier;
			std::cin.ignore();
			break;
		case 3:
			std::cout << "Insert the new travel destination of the travel pack (in the format 'Region - Place1, Place2...'): " << std::endl;
			getline(std::cin, AuxString);
			StructTravelPacks[TravelPackNumber].TravelDestination = GetTravelDestination(AuxString);
			break;
		case 4:
			std::cout << "Insert the new departure date of the travel pack (in the format 'YYYY/MM/DD'): ";
			getline(std::cin, AuxString);

			while (!ValidateDate(AuxString)) {
				std::cout << "Invalid input! Insert again: ";
				getline(std::cin, AuxString);
			}

			GetDate(StructTravelPacks[TravelPackNumber].DepartureDate, AuxString);
			break;
		case 5:
			std::cout << "Insert the new arrival date of the travel pack (in the format 'YYYY/MM/DD'): ";
			getline(std::cin, AuxString);
		
			while (!ValidateDate(AuxString)) {
				std::cout << "Invalid input! Insert again: ";
				getline(std::cin, AuxString);
			}				
			
			GetDate(StructTravelPacks[TravelPackNumber].ArrivalDate, AuxString);
			break;
		case 6:
			std::cout << "Insert the new price of the travel pack: ";
			std::cin >> StructTravelPacks[TravelPackNumber].Price;

			while (!ValidateNumber(StructTravelPacks[TravelPackNumber].Price, 'H')) {
				std::cout << "Invalid input! Insert again: ";
				std::cin >> StructTravelPacks[TravelPackNumber].Price;
			}

			std::cin.ignore();
			break;
		case 7:
			std::cout << "Insert the new quantity of initially available seats of the travel pack: ";
			std::cin >> StructTravelPacks[TravelPackNumber].InitiallyAvailableSeats;
			
			while (!ValidateNumber(StructTravelPacks[TravelPackNumber].InitiallyAvailableSeats, 'H')) {
				std::cout << "Invalid input! Insert again: ";
				std::cin >> StructTravelPacks[TravelPackNumber].InitiallyAvailableSeats;
			}

			std::cin.ignore();
			break;
		case 8:
			std::cout << "Insert the new quantity of sold seats of the travel pack: ";
			std::cin >> StructTravelPacks[TravelPackNumber].SoldSeats;

			while (!ValidateNumber(StructTravelPacks[TravelPackNumber].SoldSeats, 'H')) {
				std::cout << "Invalid input! Insert again: ";
				std::cin >> StructTravelPacks[TravelPackNumber].SoldSeats;
			}

			std::cin.ignore();
			break;
	}
}

void RemoveTravelPack(int TravelPackNumber, std::vector <TravelPack> &StructTravelPacks) {
	std::vector <TravelPack> AuxVector;

	for (int i = 0; i < size(StructTravelPacks); i++)
		if (i != TravelPackNumber)
			AuxVector.push_back(StructTravelPacks[i]);

	StructTravelPacks = AuxVector;
}

void ManageTravelPacks(std::vector <TravelPack> &StructTravelPacks) {
	int Selection, TravelPackNumber;

	std::cout << "What do you want to do ? Insert the corresponding key." << std::endl << std::endl
			  << "1) Create a new travel pack." << std::endl
			  << "2) Change the information of a travel pack." << std::endl
			  << "3) Remove an existent travel pack." << std::endl
			  << "0) Go back." << std::endl;

	std::cin >> Selection;
	std::cin.ignore();
	std::cout << std::endl;

	switch (Selection) {
	case 1:
		system("cls");
		StructTravelPacks.push_back(CreateTravelPack(StructTravelPacks));
		break;
	case 2:
		system("cls");
		std::cout << "Insert the number of the travel pack that you want to change: ";
		std::cin >> TravelPackNumber;
		std::cin.ignore();
		std::cout << std::endl;

		ChangeTravelPack(TravelPackNumber, StructTravelPacks);
		break;
	case 3:
		system("cls");
		std::cout << "Insert the number of the travel pack that you want to change: ";
		std::cin >> TravelPackNumber;
		std::cin.ignore();
		std::cout << std::endl;

		RemoveTravelPack(TravelPackNumber, StructTravelPacks);
		break;
	case 0:
		system("cls");
		break;
	}
}