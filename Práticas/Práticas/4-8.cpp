#include <iostream>
#include <string>
#include <vector>
using namespace std;
	
void bubblesort(vector<string> &v) {
	for (int i1 = 0; i1 < size(v) - 1; i1++) {
		for (int i2 = 0; i2 < size(v) - i1 - 1; i2++) {
			if (v[i2] > v[i2 + 1]) {
				string aux = v[i2];
				v[i2] = v[i2 + 1];
				v[i2 + 1] = aux;
			}
		}
	}	
}

int main() {
	int nElem;
	vector<string> v;

	cout << "Insert the number of elements that you want to insert: ";
	cin >> nElem;
	
	for (int i = 0; i < nElem; i++) {
		cout << "Insert the element of index " << i << ": ";
		getline(cin, v[i]);
	}

	bubblesort(v);

	cout << "The ordered vector is ";

	for (int i = 0; i < size(v); i++)
		cout << v[i] << " ";

	return 0;
}