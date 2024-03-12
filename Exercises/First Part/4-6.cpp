#include <iostream>
using namespace std;

void readIntArray(int a[], int nElem) {
	for (int i = 0; i < nElem; i++) {
		cout << "Insert the value of the element of index " << i << ": ";
		cin >> a[i];
	}
}

int searchValueInIntArray(const int a[], int nElem, int value) {
	for (int i = 0; i < nElem; i++) {
		if (a[i] == value)
			return i;
	}

	return -1;
}

int searchMultValuesInIntArray(const int a[], int nElem, int value, int index[]) {
	int counter = 0;

	for (int i = 0; i < nElem; i++) {
		if (a[i] == value) {
			index[counter] == i;
			counter += 1;
		}
	}

	return counter;
}

int main() {
	int nElem, value, a[100], index[100];

	cout << "Insert the number of elements that you want to write: ";
	cin >> nElem;

	readIntArray(a, nElem);

	cout << "Insert the value that you want to search: ";
	cin >> value;

	if (searchValueInIntArray(a, nElem, value) == -1)
		cout << "The value was not found.";

	else;
		cout << "The value was found on position: " << searchValueInIntArray(a, nElem, value);

	return 0;
}