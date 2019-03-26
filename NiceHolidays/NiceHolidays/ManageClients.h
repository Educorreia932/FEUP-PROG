#pragma once
#ifndef MAN_CLIENTS
#define MAN_CLIENTS
#include "Structs.h"

Client CreateClient(std::vector <Client> &StructClients);
void ChangeClient(int ClientNumber, std::vector <Client> &StructClients);
void RemoveClient(int ClientNumber, std::vector <Client> &StructClients);
void ManageClients(std::vector <Client> &StructClients);

#endif //MAN_CLIENTS