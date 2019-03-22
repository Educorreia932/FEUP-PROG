/*                                                       |
												   --====|====--
														 |  

													 .-"""""-. 
												   .'_________'. 
												  /_/_|__|__|_\_\
												 ;'-._       _.-';
							,--------------------|    `-. .-'    |--------------------,
							 ``""--..__    ___   ;       '       ;   ___    __..--""``
									   `"-// \\.._\             /_..// \\-"`
										  \\_//    '._       _.'    \\_//
										   `"`        ``---``        `"` 

	1. Ler e guardar a informa��o da ag�ncia, dos clientes e dos pacotes tur�sticos armazenada em
	ficheiros.
	2. Gerir os clientes e pacotes tur�sticos: criar, alterar e remover um cliente ou um pacote tur�stico.
	3. Gerar e visualizar de modo formatado a informa��o de um cliente especificado.
	4. Gerar e visualizar de modo formatado a informa��o de todos os clientes da ag�ncia.
	5. Gerar e visualizar de modo formatado os pacotes tur�sticos dispon�veis (todos, todos relativos a
	um destino espec�fico, todos entre duas datas, todos os relativos a um destino espec�fico e entre
	duas datas).
	6. Gerar e visualizar de modo formatado os pacotes tur�sticos vendidos (a um cliente espec�fico, a
	todos os clientes).
	7. Efetuar a compra de um pacote tur�stico por um cliente.
	8. Calcular e visualizar o n�mero e o valor total de pacotes vendidos.


	1 - Ler os ficheiros:
		a) "agency.txt" (informa��o est�tica da ag�ncia)
	    b) "clients.txt" (por exemplo)
	    c) "packs.txt" (por exemplo)

	2 - Guardar os dados lidos dos ficheiros nas estruturas de dados internas do programa

	3 - Exibir um menu onde aparecem as op��es que implementam as funcionalidades
		a) Gest�o de clientes
		b) Gest�o de pacotes tur�sticos
		c) Visualiza��o de informa��o (sobre clientes e sobre pacote tur�sticos)

	4 - Atualizar os dados nos ficheiros antes do fim da execu��o (se necess�rio)
	
	PS: Tomar precau��es contra entras v�lidas (i.e. valores fora da gama admiss�vel)

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include "AuxiliaryFunctions.h"
#include "Structs.h"
using namespace std;

void ManageClients() {
	//CreateClient, ChangeClient and RemoveClient
}

void ManageTravelPacks() {
	//CreateTravelPack, ChangeTravelPack and RemoveTravelPack
}

void VisualizeSpecificClient(Client StructClients) { //Colocar vetor e ClientNumber
	cout << "Name: " << StructClients.Name << endl
		 << "NIF: " << StructClients.NIF << endl
		 << "Household: " << StructClients.Household << endl
		 << "Address: " << StructClients.ClientAddress.Street << ", " 
		 << StructClients.ClientAddress.DoorNumber << ", "
		 << StructClients.ClientAddress.Apartment << ", "
		 << StructClients.ClientAddress.ZIPCode << ", "
		 << StructClients.ClientAddress.Province << endl
		 << "Adquired Travel Packs: " ;

	for (int i = 0; i < size(StructClients.AdquiredTravelPacks); i++) {
		if (i < size(StructClients.AdquiredTravelPacks) - 1)
			cout << StructClients.AdquiredTravelPacks[i] << ", ";

		else
			cout << StructClients.AdquiredTravelPacks[i] << endl;
	}
}

void VisualizeAgencyClients(vector <Client> StructClients) {
	for (int i = 0; i < size(StructClients); i++) { 
		VisualizeSpecificClient(StructClients[i]);
		cout << endl;
	}
}

void VisualizeSpecificTravelPack(int TravelPackNumber, vector <TravelPack> StructTravelPacks) {
	cout << endl
		 << "Numeric identifier: " << StructTravelPacks[TravelPackNumber].Identifier << endl
		 << "Travel destination: ";
		 
	for (int i = 0; i < size(StructTravelPacks[TravelPackNumber].TravelDestination); i++) {
		if (i < size(StructTravelPacks[TravelPackNumber].TravelDestination) - 1)
			cout << StructTravelPacks[TravelPackNumber].TravelDestination[i] << ", ";

		else
			cout << StructTravelPacks[TravelPackNumber].TravelDestination[i] << endl;
	}
		
	cout << "Departure date: " << StructTravelPacks[TravelPackNumber].DepartureDate.Year 
		 << '/' << setw(2) << setfill('0') << StructTravelPacks[TravelPackNumber].DepartureDate.Month
		 << '/' << setw(2) << setfill('0') << StructTravelPacks[TravelPackNumber].DepartureDate.Day << endl
		 << "Arrival date: " << StructTravelPacks[TravelPackNumber].ArrivalDate.Year
		 << '/' << setw(2) << setfill('0') << StructTravelPacks[TravelPackNumber].ArrivalDate.Month
		 << '/' << setw(2) << setfill('0') << StructTravelPacks[TravelPackNumber].ArrivalDate.Day << endl
		 << "Price per person: " << StructTravelPacks[TravelPackNumber].Price << endl
		 << "Initially available seats: " << StructTravelPacks[TravelPackNumber].InitiallyAvailableSeats << endl
		 << "Sold seats: " << StructTravelPacks[TravelPackNumber].SoldSeats << endl; 		;
} 

void VisualizeAvailableTravelPacks(vector <TravelPack> StructTravelPacks) { 
	string AuxString;
	int Selection;

	cout << "What travel packs do you want to consult? Insert the corresponding key." << endl
		 << "1) All." << endl
		 << "2) All related to a specific travel destination." << endl
		 << "3) All between two dates." << endl
		 << "4) All related to a specific travel destination and between two dates." << endl;

	cin >> Selection;
	cin.ignore();

	switch (Selection) {
		case 1:
			for (int i = 0; i < size(StructTravelPacks); i++)
				VisualizeSpecificTravelPack(i, StructTravelPacks);
			break;
		case 2:
			cout << endl << "Insert the travel destination: ";
			getline(cin, AuxString);

			for (int i = 0; i <= 2; i++) {
				if (find(StructTravelPacks[i].TravelDestination.begin(), StructTravelPacks[i].TravelDestination.end(), AuxString) != StructTravelPacks[i].TravelDestination.end())
					VisualizeSpecificTravelPack(i, StructTravelPacks);
			}
			break;
		case 3:
			break;
		case 4:
			break;
	}
}

void VisualizeSoldTravelPacks() {
	int Selection;

	cout << "What travel packs do you want to consult? Insert the corresponding key." << endl
		<< "1) Related a specific client." << endl
		<< "2) Related to any client" << endl;

	cin >> Selection;
	cin.ignore();

	switch (Selection) {
	case 1:
		break;
	case 2:
		break;
	}
}

void BuyTravelPack() {
}

void Quit() {

}

void GetAddress(Address &Address, string Line) {
	int Counter = 0;
	string AuxString;

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

void GetDate(Date &Date, string Line) {
	int Counter = 0;
	string StringAux;

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

void SaveAgency(string File, Agency &StructAgency) {	
	string Line;
	ifstream Agency(File);
	int Counter = 0;

	if (Agency.is_open()) {
		while (getline(Agency, Line)) {
			switch (Counter) {
				case 0:
					StructAgency.Name = Line;
					break;
				case 1:
					StructAgency.NIF = stoi(Line);
					break;
				case 2:
					StructAgency.URL = Line;
					break;
				case 3:
					GetAddress(StructAgency.AgencyAddress, Line);
					break;
				case 4:
					StructAgency.ClientsFile = Line;
					break;
				case 5:
					StructAgency.TravelPacksFile = Line;
					break; 
			}

			Counter += 1;
		}

		Agency.close();
	}
}

void SaveClients(string File, vector <Client> &StructClients) {
	string Line;
	ifstream Clients(File);
	Client AuxStruct;
	int Counter = 0, ClientCounter = 0;

	if (Clients.is_open()) {
		while (getline(Clients, Line)) {
			if (Line == "::::::::::") {
				StructClients.push_back(AuxStruct);
				Counter = -1;
				ClientCounter += 1;
			}
			
			else 
				switch (Counter) {
					case 0:		
						AuxStruct.Name = Line;						
						break;
					case 1:
						AuxStruct.NIF = stoi(Line);
						break;
					case 2:
						AuxStruct.Household = stoi(Line);
						break;
					case 3:
						GetAddress(AuxStruct.ClientAddress, Line);
						break;
					case 4:
						AuxStruct.AdquiredTravelPacks = GetAdquiredTravelPacks(Line);
						break;
				}

			Counter += 1;
		} 

		StructClients.push_back(AuxStruct);

		Clients.close();
	}
}

void SaveTravelPacks(string File, vector <TravelPack> &StructTravelPacks) {
	string Line;
	ifstream TravelPacks(File);
	TravelPack AuxStruct;

	int Counter = 0, TravelPackCounter = 0;
	bool FirstLine = true;

	if (TravelPacks.is_open()) {
		while (getline(TravelPacks, Line)) {
			if (FirstLine) {
				Counter = -1;
				FirstLine = false;
			}

			else if (Line == "::::::::::") {
				StructTravelPacks.push_back(AuxStruct);
				Counter = -1;
				TravelPackCounter += 1;
			}

			else
				switch (Counter) {
				case 0:
					AuxStruct.Identifier = stoi(Line);
					break;
				case 1:
					AuxStruct.TravelDestination = GetTravelDestination(Line);
					break;
				case 2:
					GetDate(AuxStruct.DepartureDate, Line);
					break;
				case 3:
					GetDate(AuxStruct.ArrivalDate, Line);
					break;
				case 4:
					AuxStruct.Price = stoi(Line);
					break;
				case 5:
					AuxStruct.InitiallyAvailableSeats = stoi(Line);
					break;
				case 6:
					AuxStruct.SoldSeats = stoi(Line);
					break;
				}

			Counter += 1;
		}

		StructTravelPacks.push_back(AuxStruct);

		TravelPacks.close();
	}
}

void Menu(string ClientsName, string TravelPacksName, vector <Client> StructClients, vector <TravelPack> StructTravelPacks) {
	int Selection;

	cout << "What do you want to do? Insert the corresponding key." << endl << endl
		<< "1) Manage clients." << endl
		<< "2) Manage travel packs." << endl
		<< "3) Visualize a specific client." << endl
		<< "4) Visualize all the clients of the agency." << endl
		<< "5) Visualize available travel packs." << endl
		<< "6) Visualize sold travel packs." << endl
		<< "7) Buy a travel pack for a client." << endl 
		<< "0) Exit the program" << endl;

	cin >> Selection;
	cin.ignore();
	cout << endl;

	switch (Selection) {
		case 1:
			ManageClients();
			break;
		case 2:
			ManageTravelPacks();
			break;
		case 3:
			int ClientNumber;

			cout << "Insert the client number: "; 
			cin >> ClientNumber;
			cin.ignore();
			cout << endl;

			VisualizeSpecificClient(StructClients[ClientNumber]);
			break;
		case 4:
			VisualizeAgencyClients(StructClients);
			break;
		case 5:
			VisualizeAvailableTravelPacks(StructTravelPacks);
			break;
		case 6:
			VisualizeSoldTravelPacks();
			break;
		case 7:
			BuyTravelPack();
			break;	
	}
}

int main() {
	string Line, AgencyFile = "agency.txt"; //Deixar o utilizador inserir o nome do ficheiro
	Agency StructAgency;
	vector <Client> StructClients; 
	vector <TravelPack> StructTravelPacks; //Fazer push_back (recorrendo a uma struct auxiliar)

	SaveAgency(AgencyFile, StructAgency);
	SaveClients(StructAgency.ClientsFile, StructClients);
	SaveTravelPacks(StructAgency.TravelPacksFile, StructTravelPacks);

	Menu(StructAgency.ClientsFile, StructAgency.TravelPacksFile, StructClients, StructTravelPacks);
	
	return 0;
}