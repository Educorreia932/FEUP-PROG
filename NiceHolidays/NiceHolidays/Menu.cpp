#include <iostream>
#include "Structs.h"
#include "ManageClients.h"
#include "ManageTravelPacks.h"
#include "VisualizeFunctions.h"
#include "RegistFunctions.h"

void Quit(Agency StructAgency, std::vector <Client> StructClients, std::vector <TravelPack> StructTravelPacks) {
	RegistIdentifier(StructTravelPacks);
	RegistClients(StructAgency, StructClients);
	RegistTravelPacks(StructAgency, StructTravelPacks);
}

void Menu(Agency StructAgency, std::vector <Client> &StructClients, std::vector <TravelPack> &StructTravelPacks) { //Colocar a voltar para trás
	int Selection;

	std::cout << "What do you want to do? Insert the corresponding key." << std::endl << std::endl
			  << "1) Manage clients." << std::endl
			  << "2) Manage travel packs." << std::endl
			  << "3) Visualize a specific client." << std::endl
			  << "4) Visualize all the clients of the agency." << std::endl
			  << "5) Visualize available travel packs." << std::endl
			  << "6) Visualize sold travel packs." << std::endl
			  << "7) Buy a travel pack for a client." << std::endl
			  << "0) Exit the program and save the alterations made." << std::endl;

	std::cin >> Selection;
	std::cin.ignore();
	std::cout << std::endl;

	switch (Selection) {
		case 1:
			system("cls");
			ManageClients(StructClients);
			system("cls");
			Menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 2:
			system("cls");
			ManageTravelPacks(StructTravelPacks);
			Menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 3:
			int ClientNumber;
			system("cls");

			std::cout << "Insert the client number: ";
			std::cin >> ClientNumber;
			std::cin.ignore();
			std::cout << std::endl;

			VisualizeSpecificClient(ClientNumber, StructClients);
			Menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 4:
			system("cls");
			VisualizeAgencyClients(StructClients);
			Menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 5:
			system("cls");
			VisualizeAvailableTravelPacks(StructTravelPacks);
			Menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 6:
			system("cls");
			VisualizeSoldTravelPacks(StructTravelPacks, StructClients);
			Menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 7:
			Menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 0:
			Quit(StructAgency, StructClients, StructTravelPacks);
			break;
	}
}