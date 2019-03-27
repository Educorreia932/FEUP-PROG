#pragma once
#ifndef MAN_CLIENTS
#define MAN_CLIENTS
#include "Structs.h"

Client createClient(std::vector <Client> &StructClients);
void changeClient(int ClientNumber, std::vector <Client> &StructClients);
void removeClient(int ClientNumber, std::vector <Client> &StructClients);
void manageClients(std::vector <Client> &StructClients);

#endif //MAN_CLIENTS