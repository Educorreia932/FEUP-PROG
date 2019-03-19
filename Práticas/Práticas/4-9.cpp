#include <iostream>
#include <vector>
#include <string>
using namespace std;

int binarySearch(const vector<string> &v, string value) {
	int middle, bottom = 0, top = size(v) - 1;
	bool found = false;

	do {
		middle = (bottom + top) / 2;

		if (v[middle] == value)
			found = true;

		else if (v[middle] < value)
			bottom = middle + 1;

		else
			top = middle - 1;

	} while (bottom <= top && found == false);

	if (!found)
		return -1;

	else
		return middle;
}

int main() {
	vector<string> v(50);
	int nElem;
	string value;
	
	cout << "Enter the number of elements of the vector: ";
	cin >> nElem;

	for (int i = 0; i < nElem; i++) {
		cout << "Insert the element of index " << i << ": ";
		getline(cin, v[i]);
	}

	cout << "Insert the value that you want to find: ";
	cin >> value;
	
	cout << "The value " << value << " is located on the position " << binarySearch(v, value) << ".";

	return 0;
}