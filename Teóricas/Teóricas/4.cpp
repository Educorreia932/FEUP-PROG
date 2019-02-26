#include <iostream>
using namespace std;

int main() {
	int x;
	bool failed;

	do {
		failed = false;
		cout << "x ? ";
		cin >> x;
			
		if (!cin) {
			cin.clear();
			cin.ignore(1000, '\n');
			failed = true;
		}
	} while (failed);

	cout << "x = " << x << endl;

	return 0;
}