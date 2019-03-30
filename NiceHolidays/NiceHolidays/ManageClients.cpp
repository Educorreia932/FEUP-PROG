#include <iostream>
#include "ManageClients.h"
#include "Structs.h"
#include "GetFunctions.h"
#include "ReadFunctions.h"
#include "VisualizeFunctions.h"

Client createClient(std::vector <Client> &StructClients) {
	Client AuxStruct;
	std::string ClientAddress, ClientAdquiredTravelPacks, AuxString;

	std::cout << "What's the name of the new client? ";
	getline(std::cin, AuxStruct.Name);

	std::cout << "What's the NIF of the new client? ";
	AuxStruct.NIF = readNIF();
	std::cin.ignore();

	std::cout << "What's the household of the new client? ";
	AuxStruct.Household = readHousehold();
	std::cin.ignore();

	std::cout << "What's the address of the new client (insert in the format 'Street / Door Number / Apartment / ZIP Code / Province')? " << std::endl;;
	getline(std::cin, ClientAddress);
	getAddress(AuxStruct.ClientAddress, ClientAddress); //Mudar para aceitar sem barras ou menos que o suposto

	std::cout << "Which travel packs did the new client adquire (separated by ';'): ";
	getline(std::cin, ClientAdquiredTravelPacks);
	AuxStruct.AdquiredTravelPacks = getAdquiredTravelPacks(ClientAdquiredTravelPacks);

	return AuxStruct;
}

void changeClient(int ClientNumber, std::vector <Client> &StructClients) {
	int selection;
	std::string ClientAddress, ClientAdquiredTravelPacks, AuxString;

	system("cls");

	std::cout << "What do you want to change in the client? Insert the corresponding key." << std::endl << std::endl
		      << "1) Everything." << std::endl
		      << "2) The name." << std::endl
		      << "3) The NIF." << std::endl
		      << "4) The household." << std::endl
		      << "5) The address." << std::endl
		      << "6) The adquired travel packs." << std::endl //Mudar nas Travel Packs conforme o household
			  << "0) Go back." << std::endl;
	
	selection = readSelection(0, 6);
	std::cin.ignore();
	std::cout << std::endl;

	switch (selection) {
		case 2:
			std::cout << "Insert the new name of the client: ";
			getline(std::cin, StructClients[ClientNumber].Name);
			break;
		case 3:
			std::cout << "Insert the new NIF of the client: ";
			StructClients[ClientNumber].NIF = readNIF();
			std::cin.ignore();
			break;
		case 4:
			std::cout << "Insert the new household of the client: ";
			StructClients[ClientNumber].Household = readHousehold();
			std::cin.ignore();
			break;
		case 5:			
			std::cout << "Insert the new address of the client (insert in the format 'Street / Door Number / Apartment / ZIP Code / Province'): " << std::endl;
			getline(std::cin, ClientAddress);
			getAddress(StructClients[ClientNumber].ClientAddress, ClientAddress);
			break;
		case 6:
			std::cout << "Insert the new adquired travel packs of the client: ";
			getline(std::cin, ClientAdquiredTravelPacks);
			StructClients[ClientNumber].AdquiredTravelPacks = getAdquiredTravelPacks(ClientAdquiredTravelPacks);
			break;
		case 0:
			system("cls");
			break;
	}
}

void removeClient(int ClientNumber, std::vector <Client> &StructClients) {
	std::vector <Client> AuxVector;

	for (int i = 0; i < size(StructClients); i++)
		if (i != ClientNumber)
			AuxVector.push_back(StructClients[i]);

	StructClients = AuxVector;
}

void manageClients(std::vector <Client> &StructClients) {
	int selection, ClientNumber;

	std::cout << "What do you want to do? Insert the corresponding key." << std::endl << std::endl
		      << "1) Create a new client." << std::endl
		      << "2) Change the information of a client." << std::endl
		      << "3) Remove an existent client." << std::endl
		      << "0) Go back." << std::endl;
	
	selection = readSelection(0, 3);
	std::cin.ignore();
	std::cout << std::endl;

	switch (selection) {
		case 1:
			system("cls");
			StructClients.push_back(createClient(StructClients));
			break;
		case 2:
			system("cls");
			std::cout << "Which client do you wish to change the information of? Insert the corresponding key." << std::endl << std::endl;
			visualizeClientsSelection(StructClients);
			std::cin >> ClientNumber;
			ClientNumber -= 1;
			std::cin.ignore();
			std::cout << std::endl;

			changeClient(ClientNumber, StructClients);
			break;
		case 3:
			system("cls");
			std::cout << "Which client do you wish to remove? Insert the corresponding key. " << std::endl << std::endl; 
			visualizeClientsSelection(StructClients); //Permitir voltar para trás
			ClientNumber = readSelection(1, size(StructClients));
			ClientNumber -= 1;
			std::cin.ignore();
			std::cout << std::endl;

			removeClient(ClientNumber, StructClients);
			break;
		case 0:
			system("cls");
			break;
	}
}