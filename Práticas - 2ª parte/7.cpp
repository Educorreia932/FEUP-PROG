#include <iostream>
#include <vector>
using namespace std;

template <class T> 
T GetMax(vector <T> v) {
	T greatest;

	for (int i = 0; i < size(v); i++) {
		if (i == 0)
			greatest = v[i];
		else if (v[i] > greatest)
			greatest = v[i];
	}

	return greatest;
}

template <class T>
T GetMin(vector <T> v) {
	T lowest;

	for (int i = 0; i < size(v); i++) {
		if (i == 0)
			lowest = v[i];
		else if (v[i] < lowest)
			lowest = v[i];
	}

	return lowest;
}

int main() {
	vector <string> v = {"asa","basd","zasd" };

	cout << GetMax(v);

	return 0;
}