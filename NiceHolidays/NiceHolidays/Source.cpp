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

	1. Ler e guardar a informação da agência, dos clientes e dos pacotes turísticos armazenada em
	ficheiros.
	2. Gerir os clientes e pacotes turísticos: criar, alterar e remover um cliente ou um pacote turístico.
	3. Gerar e visualizar de modo formatado a informação de um cliente especificado.
	4. Gerar e visualizar de modo formatado a informação de todos os clientes da agência.
	5. Gerar e visualizar de modo formatado os pacotes turísticos disponíveis (todos, todos relativos a
	um destino específico, todos entre duas datas, todos os relativos a um destino específico e entre
	duas datas).
	6. Gerar e visualizar de modo formatado os pacotes turísticos vendidos (a um cliente específico, a
	todos os clientes).
	7. Efetuar a compra de um pacote turístico por um cliente.
	8. Calcular e visualizar o número e o valor total de pacotes vendidos.


	1 - Ler os ficheiros:
		a) "agency.txt" (informação estática da agência)
	    b) "clients.txt" (por exemplo)
	    c) "packs.txt" (por exemplo)

	2 - Guardar os dados lidos dos ficheiros nas estruturas de dados internas do programa

	3 - Exibir um menu onde aparecem as opções que implementam as funcionalidades
		a) Gestão de clientes
		b) Gestão de pacotes turísticos
		c) Visualização de informação (sobre clientes e sobre pacote turísticos)

	4 - Atualizar os dados nos ficheiros antes do fim da execução (se necessário)
	
	PS: Tomar precauções contra entras válidas (i.e. valores fora da gama admissível)

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "AuxiliaryFunctions.h"
using namespace std;

typedef struct {
	string Street;
	int DoorNumber;
	string Apartment;
	string ZIPCode;
	string Province;
} Address;

typedef struct {
	int Year;
	int Month;
	int Day;
} Date;

typedef struct {
	string Name;
	int NIF;
	string URL;
	Address AgencyAdress;
	string ClientsFile;
	string TravelPacksFile;
} Agency;

typedef struct {
	string Name;
	int NIF;
	int Household;
	Address ClientAdress;
	vector <int> AdquiredTravelPacks;
} Client;

typedef struct  {
	int Identifier; 
	vector <string> TravelDestination;
	Date DepartureDate;
	Date ArrivalDate;
	int Price;
	int InitiallyAvailableSeats;
	int SoldSeats;
} TravelPack;

void ManageClients() {
	//CreateClient, ChangeClient and RemoveClient
}

void ManageTravelPacks() {
	//CreateTravelPack, ChangeTravelPack and RemoveTravelPack
}

void VisualizeSpecificClient(int ClientNumber, Client StructClients) {
	cout << StructClients.Name << endl
		 << StructClients.NIF << endl
		 << StructClients.Household << endl
		 << StructClients.ClientAdress.Street << ", " 
		 << StructClients.ClientAdress.DoorNumber << ", "
		 << StructClients.ClientAdress.Apartment << ", "
		 << StructClients.ClientAdress.ZIPCode << ", "
		 << StructClients.ClientAdress.Province << endl;
}

void VisualizeAgencyClients() {
	cout << "Worked";
} //Usar VisualizeSpecificClient

void VisualizeAvailableTravelPacks() { 
	int Selection;

	cout << "What travel packs do you want to consult? Insert the corresponding key." << endl
		<< "1) All." << endl
		<< "2) All related to a specific client." << endl
		<< "3) All between two dates." << endl
		<< "4) All related to a specific client and between two dates." << endl;

	cin >> Selection;
	cin.ignore();

	switch (Selection) {
		case 1:
			break;
		case 2:
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
					GetAddress(StructAgency.AgencyAdress, Line);
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
	int Counter = 0, ClientCounter = 0;

	if (Clients.is_open()) {
		while (getline(Clients, Line)) {
			if (Line == "::::::::::") {
				Counter = -1;
				ClientCounter += 1;
			}
			
			else 
				switch (Counter) {
					case 0:		
						StructClients[ClientCounter].Name = Line;						
						break;
					case 1:
						StructClients[ClientCounter].NIF = stoi(Line);
						break;
					case 2:
						StructClients[ClientCounter].Household = stoi(Line);
						break;
					case 3:
						GetAddress(StructClients[ClientCounter].ClientAdress, Line);
						break;
					case 4:
						StructClients[ClientCounter].AdquiredTravelPacks = GetAdquiredTravelPacks(Line);
						break;
				}

			Counter += 1;
		} 

		Clients.close();
	}
}

void SaveTravelPacks(string File, vector <TravelPack> &StructTravelPacks) {
	string Line;
	ifstream TravelPacks(File);

	int Counter = 0, TravelPackCounter = 0;
	bool FirstLine = true;

	if (TravelPacks.is_open()) {
		while (getline(TravelPacks, Line)) {
			if (FirstLine) {
				Counter = -1;
				FirstLine = false;
			}

			else if (Line == "::::::::::") {
				Counter = -1;
				TravelPackCounter += 1;
			}

			else
				switch (Counter) {
				case 0:
					StructTravelPacks[TravelPackCounter].Identifier = stoi(Line);
					break;
				case 1:
					StructTravelPacks[TravelPackCounter].TravelDestination = GetTravelDestination(Line);
					break;
				case 2:
					GetDate(StructTravelPacks[TravelPackCounter].DepartureDate, Line);
					break;
				case 3:
					GetDate(StructTravelPacks[TravelPackCounter].ArrivalDate, Line);
					break;
				case 4:
					StructTravelPacks[TravelPackCounter].Price = stoi(Line);
					break;
				case 5:
					StructTravelPacks[TravelPackCounter].InitiallyAvailableSeats = stoi(Line);
					break;
				case 6:
					StructTravelPacks[TravelPackCounter].SoldSeats = stoi(Line);
					break;
				}

			Counter += 1;
		}

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

		VisualizeSpecificClient(ClientNumber, StructClients[ClientNumber]);
		break;
	case 4:
		VisualizeAgencyClients();
		break;
	case 5:
		VisualizeAvailableTravelPacks();
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
	string Line, AgencyName = "agency.txt";
	Agency StructAgency;
	vector <Client> StructClients(50);
	vector <TravelPack> StructTravelPacks(50); //Fazer push_back (recorrendo a uma struct auxiliar)

	SaveAgency(AgencyName, StructAgency);
	SaveClients(StructAgency.ClientsFile, StructClients);
	SaveTravelPacks(StructAgency.TravelPacksFile, StructTravelPacks);

	Menu(StructAgency.ClientsFile, StructAgency.TravelPacksFile, StructClients, StructTravelPacks);
	
	return 0;
}