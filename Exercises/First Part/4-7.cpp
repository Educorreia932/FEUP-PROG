#include <iostream>
#include <vector>
using namespace std;

void readIntVector(vector<int> &v, int nElem) {
	for (int i = 0; i < nElem; i++) {
		cout << "Insert the value of the element of index " << i << ": ";
		cin >> v[i];
	}
}

int searchValueInVector(const vector<int> &v, int value) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == value)
			return i;
	}

	return -1;
}

vector<int> searchMultValuesInIntVector(const vector<int> &v, int value) {
	vector<int> index;
	int counter = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == value) {
			index[counter] == i;
			counter += 1;
		}
	}

	return index;
}

int main() {
	int nElem, value;
	vector<int> v;

	cout << "Insert the number of elements that you want to write: ";
	cin >> nElem;

	readIntVector(v, nElem);

	cout << "Insert the value that you want to search: ";
	cin >> value;

	if (searchValueInVector(v, value) == -1)
		cout << "The value was not found.";

	else;
		cout << "The value was found on position: " << searchValueInVector(v, value);

	return 0;
}