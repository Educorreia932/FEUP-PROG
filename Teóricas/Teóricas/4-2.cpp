#include <iostream>
using namespace std;

int main() {
	int x, sum = 0;

	cout << "Insert values (end with X):\n";

	while (cin >> x)
		sum = sum + x;

	cout << "sum = " << sum << endl;

	char ch;
	
	cin.clear();
	cin >> ch;
	cout << ch << endl;
	
	return 0;
}