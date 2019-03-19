/*                           |
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

#include <string>
using namespace std;

struct Agency {
	string Name;
	int NIF;
	string URL;	
	//Add Address (struct)
	//Add files
};

struct Client {
	string Name;
	int NIF;
	int Household;
	//Add Address (struct)
	//Add Adquired Travel Packs
};

struct TravelPack {
	int Identifier; 
	//Add Travel Destination
	//Add Departure Date (struct)
	//Add Arrival Date (struct)
	int Price;
	int InitiallyAvailableSeats;
	int SoldSeats;
};

struct Address;

struct Date;

int main() {
	return 0;
}