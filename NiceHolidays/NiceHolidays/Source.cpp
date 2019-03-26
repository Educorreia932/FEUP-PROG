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

	4 - Atualizar os dados nos ficheiros antes do fim da execução (se necessário) ✔
	
	PS: Tomar precauções contra entras válidas (i.e. valores fora da gama admissível)

*/

#include <iostream>
#include <fstream>
#include "Structs.h"
#include "GetFunctions.h"
#include "SaveFunctions.h"
#include "Menu.h"

using namespace std;

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