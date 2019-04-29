#pragma once
#include "Agency.h"

class Menu {
	public:
		Menu(Agency AgencyObj);
		int show();
	private:
		Agency AgencyObj;
};