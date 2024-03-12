#include <iostream>
#include <string>
using namespace std;

bool isHydroxide(string compound) {
	int length = compound.length();

	if (compound[length - 1] == 'H' && compound[length - 2] == 'O')
		return true;

	else
		return false;
}

int main() {
	string compound = "KOH";

	cout << isHydroxide(compound);

	return 0;
}