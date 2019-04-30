#include "Menu.h"

int main() {
	Menu ProjMenu(Agency("agency.txt"));

	ProjMenu.menuSelection(ProjMenu.showMenu());

	return 0;
}