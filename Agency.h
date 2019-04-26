#pragma once
#include <string>
#include "Address.h"

using namespace std;

class Agency {
	public:
		Agency(string name, unsigned int nif, Address AgencyAddress, string url, string clients_file, string travelpacks_file);
	private:
		string name;
		unsigned int nif;
		Address AgencyAddress;
		string url;
		//lista de pacotes
		//lista de clientes
		string clients_file;
		string travelpacks_file;
};
