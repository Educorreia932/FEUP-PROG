#include <iostream>
#include <vector>
using namespace std;

void removeDuplicates(vector <int> &v) {
	vector <int> AuxVector;

	for (int i1 = 0; i1 < size(v); i1++)
		if (!(find(AuxVector.begin(), AuxVector.end(), v[i1]) != AuxVector.end()))
			AuxVector.push_back(v[i1]);

	v = AuxVector;
}

int main() {
	vector <int> v = { 9, 2, 2, 2, 1, 14, 14, 1, 3 };

	removeDuplicates(v);

	for (int i = 0; i < size(v); i++)
		cout << v[i] << endl;

	return 0;
}