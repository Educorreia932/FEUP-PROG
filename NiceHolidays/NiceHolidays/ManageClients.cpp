#include <iostream>
#include "ManageClients.h"
#include "Structs.h"
#include "GetFunctions.h"
#include "ValidateFunctions.h"

Client CreateClient(std::vector <Client> &StructClients) {
	Client AuxStruct;
	std::string ClientAddress, ClientAdquiredTravelPacks;

	std::cout << "What's the name of the new client? ";
	getline(std::cin, AuxStruct.Name);

	std::cout << "What's the NIF of the new client? ";
	std::cin >> AuxStruct.NIF;
	std::cin.ignore();

	while (!ValidateNumber(AuxStruct.NIF, 'N')) {
		std::cout << "Invalid input! Insert again: ";
		std::cin >> AuxStruct.NIF;
	}
	
	std::cout << "What's the household of the new client? ";
	std::cin >> AuxStruct.Household;

	while (!ValidateNumber(AuxStruct.Household, 'H')) {
		std::cout << "Invalid input! Insert again: ";
		std::cin >> AuxStruct.Household;
	}

	std::cin.ignore();

	std::cout << "What's the address of the new client (insert in the format 'Street / Door Number / Apartment / ZIP Code / Province')? " << std::endl;;
	getline(std::cin, ClientAddress);
	GetAddress(AuxStruct.ClientAddress, ClientAddress); //Mudar para aceitar sem barras ou menos que o suposto

	std::cout << "Which travel packs did the new client adquire (separated by ';'): ";
	getline(std::cin, ClientAdquiredTravelPacks);
	AuxStruct.AdquiredTravelPacks = GetAdquiredTravelPacks(ClientAdquiredTravelPacks);

	return AuxStruct;
}

void ChangeClient(int ClientNumber, std::vector <Client> &StructClients) {
	int Selection;
	std::string ClientAddress;

	std::cout << "What do you want to change in the client? Insert the corresponding key." << std::endl << std::endl
		      << "1) Everything." << std::endl
		      << "2) The name." << std::endl
		      << "3) The NIF." << std::endl
		      << "4) The household." << std::endl
		      << "5) The address." << std::endl
		      << "6) The adquired travel packs." << std::endl; //Mudar nas Travel Packs conforme o household
	std::cin >> Selection;
	std::cin.ignore();
	std::cout << std::endl;

	switch (Selection) {
		case 2:
			std::cout << "Insert the new name of the client: ";
			getline(std::cin, StructClients[ClientNumber].Name);
			break;
		case 3:
			std::cout << "Insert the new NIF of the client: ";
			std::cin >> StructClients[ClientNumber].NIF;

			while (!ValidateNumber(StructClients[ClientNumber].NIF, 'N')) {
				std::cout << "Invalid input! Insert again: ";
				std::cin >> StructClients[ClientNumber].NIF;
			}

			std::cin.ignore();
			break;
		case 4:
			std::cout << "Insert the new household of the client: ";
			std::cin >> StructClients[ClientNumber].Household;

			while (!ValidateNumber(StructClients[ClientNumber].Household, 'H')) {
				std::cout << "Invalid input! Insert again: ";
				std::cin >> StructClients[ClientNumber].Household;
			}

			std::cin.ignore();
			break;
		case 5:			
			std::cout << "Insert the new address of the client (insert in the format 'Street / Door Number / Apartment / ZIP Code / Province'): " << std::endl;
			getline(std::cin, ClientAddress);
			GetAddress(StructClients[ClientNumber].ClientAddress, ClientAddress);
			break;
		case 6:
			std::string ClientAdquiredTravelPacks;
			getline(std::cin, ClientAdquiredTravelPacks);
			StructClients[ClientNumber].AdquiredTravelPacks = GetAdquiredTravelPacks(ClientAdquiredTravelPacks);
			break;
	}
}

void RemoveClient(int ClientNumber, std::vector <Client> &StructClients) {
	std::vector <Client> AuxVector;

	for (int i = 0; i < size(StructClients); i++)
		if (i != ClientNumber)
			AuxVector.push_back(StructClients[i]);

	StructClients = AuxVector;
}

void ManageClients(std::vector <Client> &StructClients) {
	int Selection, ClientNumber;

	std::cout << "What do you want to do? Insert the corresponding key." << std::endl << std::endl
		      << "1) Create a new client." << std::endl
		      << "2) Change the information of a client." << std::endl
		      << "3) Remove an existent client." << std::endl
		      << "0) Go back." << std::endl;
	std::cin >> Selection;
	std::cin.ignore();
	std::cout << std::endl;

	switch (Selection) {
		case 1:
			system("cls");
			StructClients.push_back(CreateClient(StructClients));
			break;
		case 2:
			system("cls");
			std::cout << "Insert the number of the client that you want to change: ";
			std::cin >> ClientNumber;
			std::cin.ignore();
			std::cout << std::endl;

			ChangeClient(ClientNumber, StructClients);
			break;
		case 3:
			system("cls");
			std::cout << "Insert the number of the client that you want to remove: "; //Change to NIF or something else
			std::cin >> ClientNumber;
			std::cin.ignore();
			std::cout << std::endl;

			RemoveClient(ClientNumber, StructClients);
			break;
		case 0:
			system("cls");
			break;
	}
}