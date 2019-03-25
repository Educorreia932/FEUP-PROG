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
	ficheiros. ✔
	2. Gerir os clientes e pacotes turísticos: criar, alterar e remover um cliente ou um pacote turístico. 
	3. Gerar e visualizar de modo formatado a informação de um cliente especificado. ✔
	4. Gerar e visualizar de modo formatado a informação de todos os clientes da agência. ✔
	5. Gerar e visualizar de modo formatado os pacotes turísticos disponíveis (todos, todos relativos a
	um destino específico, todos entre duas datas, todos os relativos a um destino específico e entre
	duas datas). ✔
	6. Gerar e visualizar de modo formatado os pacotes turísticos vendidos (a um cliente específico, a
	todos os clientes). 
	7. Efetuar a compra de um pacote turístico por um cliente.
	8. Calcular e visualizar o número e o valor total de pacotes vendidos.


	1 - Ler os ficheiros: ✔
		a) "agency.txt" (informação estática da agência) ✔
	    b) "clients.txt" (por exemplo) ✔
	    c) "packs.txt" (por exemplo) ✔

	2 - Guardar os dados lidos dos ficheiros nas estruturas de dados internas do programa ✔

	3 - Exibir um menu onde aparecem as opções que implementam as funcionalidades ✔
		a) Gestão de clientes 
		b) Gestão de pacotes turísticos
		c) Visualização de informação (sobre clientes e sobre pacote turísticos)

	4 - Atualizar os dados nos ficheiros antes do fim da execução (se necessário)
	
	PS: Tomar precauções contra entras válidas (i.e. valores fora da gama admissível)

*/

#include <iostream>
#include <fstream>
#include "Structs.h"
#include "AuxiliaryFunctions.h"
#include "GetFunctions.h"
#include "SaveFunctions.h"
#include "VisualizeFunctions.h"
#include "ManageFunctions.h"
#include "RegistFunctions.h"

using namespace std;

void BuyTravelPack(vector <TravelPack> StructTravelPacks) {
}

void Quit(Agency StructAgency, vector <Client> StructClients, vector <TravelPack> StructTravelPacks) {
	RegistClients(StructAgency, StructClients);
}

void Menu(Agency StructAgency, vector <Client> &StructClients, vector <TravelPack> &StructTravelPacks) {
	int Selection;

	//system("cls");

	cout << "What do you want to do? Insert the corresponding key." << endl << endl
		 << "1) Manage clients." << endl
		 << "2) Manage travel packs." << endl
		 << "3) Visualize a specific client." << endl
	     << "4) Visualize all the clients of the agency." << endl
		 << "5) Visualize available travel packs." << endl
	 	 << "6) Visualize sold travel packs." << endl
		 << "7) Buy a travel pack for a client." << endl 
		 << "0) Exit the program and save the alterations made." << endl;

	cin >> Selection;
	cin.ignore();
	cout << endl;

	switch (Selection) {
		case 1:
			ManageClients(StructClients);
			Menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 2:
			ManageTravelPacks(StructTravelPacks);
			Menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 3:
			int ClientNumber;

			cout << "Insert the client number: "; 
			cin >> ClientNumber;
			cin.ignore();
			cout << endl;

			VisualizeSpecificClient(ClientNumber, StructClients);
			Menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 4:
			VisualizeAgencyClients(StructClients);
			Menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 5:
			VisualizeAvailableTravelPacks(StructTravelPacks);
			Menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 6:
			VisualizeSoldTravelPacks(StructTravelPacks, StructClients);
			Menu(StructAgency, StructClients, StructTravelPacks);
			break;
		case 7:
			BuyTravelPack(StructTravelPacks);
			Menu(StructAgency, StructClients, StructTravelPacks);
			break;	
		case 0:
			Quit(StructAgency, StructClients, StructTravelPacks);
			break;
	}
}

int main() {
	string AgencyFile = "agency.txt"; //Deixar o utilizador inserir o nome do ficheiro
	Agency StructAgency;
	vector <Client> StructClients; 
	vector <TravelPack> StructTravelPacks; 

	StructAgency = SaveAgency(AgencyFile);
	SaveClients(StructAgency.ClientsFile, StructClients);
	SaveTravelPacks(StructAgency.TravelPacksFile, StructTravelPacks);

	Menu(StructAgency, StructClients, StructTravelPacks);

	return 0;
}