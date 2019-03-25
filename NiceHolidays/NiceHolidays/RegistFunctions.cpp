#include <fstream>
#include "RegistFunctions.h"
#include "Structs.h"

void RegistClients(Agency StructAgency, std::vector <Client> StructClients) {
	std::ofstream ClientsFile;
	ClientsFile.open(StructAgency.ClientsFile);

	for (int i1 = 0; i1 < std::size(StructClients); i1++) {
		ClientsFile << StructClients[i1].Name << std::endl
			        << StructClients[i1].NIF << std::endl
			        << StructClients[i1].Household << std::endl
					<< StructClients[i1].ClientAddress.Street << " / "
					<< StructClients[i1].ClientAddress.DoorNumber << " / "
					<< StructClients[i1].ClientAddress.Apartment << " / "
					<< StructClients[i1].ClientAddress.ZIPCode << " / "
					<< StructClients[i1].ClientAddress.Province << std::endl;

		for (int i2 = 0; i2 < size(StructClients[i1].AdquiredTravelPacks); i2++) {
			if (i2 < size(StructClients[i1].AdquiredTravelPacks) - 1)
				ClientsFile << StructClients[i1].AdquiredTravelPacks[i2] << " ; ";

			else
				ClientsFile << StructClients[i1].AdquiredTravelPacks[i2] << std::endl;
		}

		if (i1 < size(StructClients) - 1)
			ClientsFile << "::::::::::" << std::endl;
	}

	ClientsFile.close();
}