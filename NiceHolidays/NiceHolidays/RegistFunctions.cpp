#include <iomanip>
#include <fstream>
#include "RegistFunctions.h"
#include "Structs.h"

void RegistIdentifier(std::vector <TravelPack> &StructTravelPacks) {
	for (int i = 0; i < size(StructTravelPacks); i++) {
		if (StructTravelPacks[i].InitiallyAvailableSeats == StructTravelPacks[i].SoldSeats && StructTravelPacks[i].Identifier > 0)
			StructTravelPacks[i].Identifier = -StructTravelPacks[i].Identifier;

		else if (StructTravelPacks[i].InitiallyAvailableSeats != StructTravelPacks[i].SoldSeats && StructTravelPacks[i].Identifier < 0) 
			StructTravelPacks[i].Identifier = abs(StructTravelPacks[i].Identifier);
	}
}

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

void RegistTravelPacks(Agency StructAgency, std::vector <TravelPack> StructTravelPacks) {
	std::ofstream TravelPacksFile;
	TravelPacksFile.open(StructAgency.TravelPacksFile);

	TravelPacksFile << 3 << std::endl; //Mudar mais tarde

	for (int i1 = 0; i1 < std::size(StructTravelPacks); i1++) {
		TravelPacksFile << StructTravelPacks[i1].Identifier << std::endl;

		for (int i2 = 0; i2 < std::size(StructTravelPacks[i1].TravelDestination); i2++) {
			if (i2 == 0) {
				if (size(StructTravelPacks[i1].TravelDestination) == 1) 
					TravelPacksFile << StructTravelPacks[i1].TravelDestination[i2] << std::endl;

				else
					TravelPacksFile << StructTravelPacks[i1].TravelDestination[i2] << " - ";
			}
				

			else if (i2 < size(StructTravelPacks[i1].TravelDestination) - 1)
				TravelPacksFile << StructTravelPacks[i1].TravelDestination[i2] << ", ";

			else
				TravelPacksFile << StructTravelPacks[i1].TravelDestination[i2] << std::endl;
		}

		TravelPacksFile << StructTravelPacks[i1].DepartureDate.Year << "/"
						<< std::setw(2) << std::setfill('0') << StructTravelPacks[i1].DepartureDate.Month << "/"
						<< std::setw(2) << std::setfill('0') << StructTravelPacks[i1].DepartureDate.Day << std::endl
						<< StructTravelPacks[i1].ArrivalDate.Year << "/"
						<< std::setw(2) << std::setfill('0') << StructTravelPacks[i1].ArrivalDate.Month << "/"
						<< std::setw(2) << std::setfill('0') << StructTravelPacks[i1].ArrivalDate.Day << std::endl
						<< StructTravelPacks[i1].Price << std::endl
						<< StructTravelPacks[i1].InitiallyAvailableSeats << std::endl
						<< StructTravelPacks[i1].SoldSeats << std::endl;

		if (i1 < std::size(StructTravelPacks) - 1)
			TravelPacksFile << "::::::::::" << std::endl;
	}		

	TravelPacksFile.close();
}

//Fazer função que calcule alterações