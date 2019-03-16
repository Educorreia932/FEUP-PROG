#include <iostream>
#include <cstring>
using namespace std;

int charCount(char compound[]) {
	int counter = 0;

	for (int i = 0; compound[i] != '\0'; i++) {
		counter++;
	}

	return counter;
}

bool isHydroxide(char compound[]) {
	int length = charCount(compound);

	if (compound[length - 1] == 'H' && compound[length - 2] == 'O')
		return true;
	
	else
		return false;
}

int main() {
	char string[] = "KOH";

	cout << isHydroxide(string);

	return 0;
}