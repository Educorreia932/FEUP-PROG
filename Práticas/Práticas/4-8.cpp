#include <iostream>
#include <vector>
using namespace std;

void bubblesort(vector<string> &v) {
	for (int i1 = 0; i1 < size(v); i1++) {
		for (int i2 = i1; i2 < size(v); i2++) {
			if (v[i2] > v[i2 + 1]) {
				string aux = v[i2];
				v[i2] = v[i2 + 1];
				v[i2 + 1] = aux;
			}
		}
	}	
}

int main() {

	return 0;
}