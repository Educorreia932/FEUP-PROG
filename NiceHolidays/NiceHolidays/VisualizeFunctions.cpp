#include <iostream>
#include <iomanip>
#include <vector>
#include "Structs.h"
#include "VisualizeFunctions.h"

void VisualizeSpecificClient(int ClientNumber, std::vector <Client> StructClients) {
	std::cout << "Name: " << StructClients[ClientNumber].Name << std::endl
		<< "NIF: " << StructClients[ClientNumber].NIF << std::endl
		<< "Household: " << StructClients[ClientNumber].Household << std::endl
		<< "Address: " << StructClients[ClientNumber].ClientAddress.Street << ", "
		<< StructClients[ClientNumber].ClientAddress.DoorNumber << ", "
		<< StructClients[ClientNumber].ClientAddress.Apartment << ", "
		<< StructClients[ClientNumber].ClientAddress.ZIPCode << ", "
		<< StructClients[ClientNumber].ClientAddress.Province << std::endl
		<< "Adquired Travel Packs: ";

	for (int i = 0; i < size(StructClients[ClientNumber].AdquiredTravelPacks); i++) {
		if (i < size(StructClients[ClientNumber].AdquiredTravelPacks) - 1)
			std::cout << StructClients[ClientNumber].AdquiredTravelPacks[i] << ", ";

		else
			std::cout << StructClients[ClientNumber].AdquiredTravelPacks[i] << std::endl;
	}
}

void VisualizeAgencyClients(std::vector <Client> StructClients) {
	for (int i = 0; i < size(StructClients); i++) {
		VisualizeSpecificClient(i, StructClients);
		std::cout << std::endl;
	}
}

void VisualizeSpecificTravelPack(int TravelPackNumber, std::vector <TravelPack> StructTravelPacks) {
	std::cout << std::endl
		<< "Numeric identifier: " << StructTravelPacks[TravelPackNumber].Identifier << std::endl
		<< "Travel destination: ";

	for (int i = 0; i < size(StructTravelPacks[TravelPackNumber].TravelDestination); i++) {
		if (i < size(StructTravelPacks[TravelPackNumber].TravelDestination) - 1)
			std::cout << StructTravelPacks[TravelPackNumber].TravelDestination[i] << ", ";

		else
			std::cout << StructTravelPacks[TravelPackNumber].TravelDestination[i] << std::endl;
	}

	std::cout << "Departure date: " << StructTravelPacks[TravelPackNumber].DepartureDate.Year
		<< '/' << std::setw(2) << std::setfill('0') << StructTravelPacks[TravelPackNumber].DepartureDate.Month
		<< '/' << std::setw(2) << std::setfill('0') << StructTravelPacks[TravelPackNumber].DepartureDate.Day << std::endl
		<< "Arrival date: " << StructTravelPacks[TravelPackNumber].ArrivalDate.Year
		<< '/' << std::setw(2) << std::setfill('0') << StructTravelPacks[TravelPackNumber].ArrivalDate.Month
		<< '/' << std::setw(2) << std::setfill('0') << StructTravelPacks[TravelPackNumber].ArrivalDate.Day << std::endl
		<< "Price per person: " << StructTravelPacks[TravelPackNumber].Price << std::endl
		<< "Initially available seats: " << StructTravelPacks[TravelPackNumber].InitiallyAvailableSeats << std::endl
		<< "Sold seats: " << StructTravelPacks[TravelPackNumber].SoldSeats << std::endl;
}

void VisualizeAvailableTravelPacks(std::vector <TravelPack> StructTravelPacks) {
	std::string AuxString;
	int Selection, AuxYear1, AuxMonth1, AuxDay1, AuxYear2, AuxMonth2, AuxDay2;
	char FirstSlash, SecondSlash;

	std::cout << "What travel packs do you want to consult? Insert the corresponding key." << std::endl
		<< "1) All." << std::endl
		<< "2) All related to a specific travel destination." << std::endl
		<< "3) All between two dates." << std::endl
		<< "4) All related to a specific travel destination and between two dates." << std::endl;

	std::cin >> Selection;
	std::cin.ignore();

	switch (Selection) {
		case 1:
			for (int i = 0; i < size(StructTravelPacks); i++)
				VisualizeSpecificTravelPack(i, StructTravelPacks);
			break;
		case 2:
			std::cout << std::endl << "Insert the travel destination: ";
			getline(std::cin, AuxString);

			for (int i = 0; i <= 2; i++) {
				if (find(StructTravelPacks[i].TravelDestination.begin(), StructTravelPacks[i].TravelDestination.end(), AuxString) != StructTravelPacks[i].TravelDestination.end())
					VisualizeSpecificTravelPack(i, StructTravelPacks);
			}
			break;
		case 3:
			std::cout << "Insert the first date (YYYY/MM/DD): ";
			std::cin >> AuxYear1 >> FirstSlash >> AuxMonth1 >> SecondSlash >> AuxDay1;
			std::cin.ignore();
			std::cout << "Insert the second date (YYYY/MM/DD): ";
			std::cin >> AuxYear2 >> FirstSlash >> AuxMonth2 >> SecondSlash >> AuxDay2;

			for (int i = 0; i <= 2; i++) {
				if (StructTravelPacks[i].DepartureDate.Year >= AuxYear1 && StructTravelPacks[i].DepartureDate.Month >= AuxMonth1 && StructTravelPacks[i].DepartureDate.Day >= AuxDay1
					&& StructTravelPacks[i].DepartureDate.Year <= AuxYear2 && StructTravelPacks[i].DepartureDate.Month <= AuxMonth2 && StructTravelPacks[i].DepartureDate.Day <= AuxDay2)
					VisualizeSpecificTravelPack(i, StructTravelPacks);
			}
			break;
		case 4:
			std::cout << "Insert the first date (YYYY/MM/DD): ";
			std::cin >> AuxYear1 >> FirstSlash >> AuxMonth1 >> SecondSlash >> AuxDay1;
			std::cin.ignore();
			std::cout << "Insert the second date (YYYY/MM/DD): ";
			std::cin >> AuxYear2 >> FirstSlash >> AuxMonth2 >> SecondSlash >> AuxDay2;
			std::cin.ignore();
			std::cout << std::endl << "Insert the travel destination: ";
			getline(std::cin, AuxString);

			for (int i = 0; i <= 2; i++) {
				if (StructTravelPacks[i].DepartureDate.Year >= AuxYear1 && StructTravelPacks[i].DepartureDate.Month >= AuxMonth1 && StructTravelPacks[i].DepartureDate.Day >= AuxDay1
					&& StructTravelPacks[i].DepartureDate.Year <= AuxYear2 && StructTravelPacks[i].DepartureDate.Month <= AuxMonth2 && StructTravelPacks[i].DepartureDate.Day <= AuxDay2
					&& find(StructTravelPacks[i].TravelDestination.begin(), StructTravelPacks[i].TravelDestination.end(), AuxString) != StructTravelPacks[i].TravelDestination.end())
					VisualizeSpecificTravelPack(i, StructTravelPacks);
		}

		break;
	}
}

void VisualizeSoldTravelPacks(std::vector <TravelPack> StructTravelPacks) { //To Do
	int Selection;

	std::cout << "What travel packs do you want to consult? Insert the corresponding key." << std::endl
		<< "1) Related a specific client." << std::endl
		<< "2) Related to any client" << std::endl;

	std::cin >> Selection;
	std::cin.ignore();

	switch (Selection) {
		case 1:
			break;
		case 2:
			break;
	}
}