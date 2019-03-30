#include <iostream>
#include "Structs.h"
#include "ManageClients.h"
#include "ManageTravelPacks.h"
#include "VisualizeFunctions.h"
#include "RegistFunctions.h"
#include "ReadFunctions.h"

void buyTravelPack(std::vector <Client> &StructClients, std::vector <TravelPack> &StructTravelPacks) {
	int selection1, selection2;

	std::cout << "For which client do you wish to buy a travel pack? Insert the corresponding key." << std::endl << std::endl;
	visualizeClientsSelection(StructClients);
	selection1 = readSelection(1, size(StructClients)) - 1;
	std::cin.ignore();

	system("cls");

	std::cout << "And which travel pack do you wish to buy for the client? Insert the corresponding key." << std::endl << std::endl;
	visualizeTravelPacksSelection(StructTravelPacks); //Não mostrar os esgotados e impedir que haja seleções impossíveis e impedir que o cliente compre um travel pack que já tem
	selection2 = readSelection(1, size(StructTravelPacks)) - 1; 
	std::cin.ignore();

	while (StructTravelPacks[selection2].SoldSeats + StructClients[selection1].Household > StructTravelPacks[selection2].InitiallyAvailableSeats) {
		std::cout << std::endl << "This selection exceeds the number of available seats. Choose another pack: " << std::endl << std::endl;
		visualizeTravelPacksSelection(StructTravelPacks);
		selection2 = readSelection(1, size(StructTravelPacks)) - 1;
		std::cin.ignore();
	}
	
	StructClients[selection1].AdquiredTravelPacks.push_back(abs(StructTravelPacks[selection2].Identifier)); 
	StructTravelPacks[selection2].SoldSeats += StructClients[selection1].Household;
}

void quit(Agency StructAgency, std::vector <Client> StructClients, std::vector <TravelPack> StructTravelPacks) {
	registIdentifier(StructTravelPacks);
	registClients(StructAgency, StructClients);
	registTravelPacks(StructAgency, StructTravelPacks);
}

void menu(Agency StructAgency, std::vector <Client> &StructClients, std::vector <TravelPack> &StructTravelPacks) {
	int selection;

	std::cout << "What do you want to do? Insert the corresponding key." << std::endl << std::endl
			  << "1) Manage clients." << std::endl
			  << "2) Manage travel packs." << std::endl
			  << "3) Visualize a specific client." << std::endl
			  << "4) Visualize all the clients of the agency." << std::endl
			  << "5) Visualize available travel packs." << std::endl
			  << "6) Visualize sold travel packs." << std::endl
			  << "7) Buy a travel pack for a client." << std::endl
			  << "0) Exit the program and save the alterations made." << std::endl;

	selection = readSelection(0, 7);	
	std::cin.ignore();
	std::cout << std::endl;

	switch (selection) {
		case 1:
			system("cls");
			manageClients(StructClients);
			system("cls");
			menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 2:
			system("cls");
			manageTravelPacks(StructTravelPacks);
			menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 3:
			int ClientNumber;
			system("cls");

			std::cout << "Which client do you wish to visualize? Insert the corresponding key." << std::endl << std::endl;
			visualizeClientsSelection(StructClients);
			
			ClientNumber = readSelection(1, size(StructClients));
			ClientNumber -= 1;

			std::cin.ignore();
			std::cout << std::endl;

			visualizeSpecificClient(ClientNumber, StructClients);

			system("pause");
			system("cls");
			menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 4:
			system("cls");
			visualizeAgencyClients(StructClients);
			system("pause");
			system("cls");
			menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 5:
			system("cls");
			visualizeAvailableTravelPacks(StructTravelPacks);
			system("pause");
			system("cls");
			menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 6:
			system("cls");
			visualizeSoldTravelPacks(StructTravelPacks, StructClients);
			menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 7:
			system("cls");
			buyTravelPack(StructClients, StructTravelPacks);
			system("cls");
			menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 0:
			quit(StructAgency, StructClients, StructTravelPacks);
			break;
	}
}