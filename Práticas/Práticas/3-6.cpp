#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool isBissextile(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;

	else
		return false;
}

int numberOfdays(int month, int year) {
	switch (month) {
		case 2:
			if (isBissextile(year))
				return 29;
			else
				return 28;
		case 4:
			return 31;
		case 6:
			return 31;
		case 9:
			return 31;
		case 11:
			return 31;
		default:
			return 31;
	}
}

int dayOfweek(int day, int month, int year) {
	int c;

	switch (month) {
		case 1:
			if (isBissextile(year)) {
				c = 6;
				break;
			}

			else {
				c = 0;
				break;
			}

		case 2:
			if (isBissextile(year)) {
				c = 2;
				break;
			}

			else {
				c = 3;
				break;
			}

		case 3:
			c = 3;
			break;

		case 4:
			c = 6;
			break;

		case 5:
			c = 1;
			break;

		case 6:
			c = 4;
			break;

		case 7:
			c = 6;
			break;

		case 8:
			c = 2;
			break;

		case 9:
			c = 5;
			break;

		case 10:
			c = 0;
			break;

		case 11:
			c = 3;
			break;

		case 12:
			c = 5;
			break;
	}

	int a = year % 100;
	int s = year / 100;

	return ((int)((5 * a) / 4) + c + day - 2 * (s % 4)) % 7;
}

string day(int number) {
	switch (number) {
		case 0:
			return "Sat";
		case 1:
			return "Sun";
		case 2:
			return "Mon";
		case 3: 
			return "Tue";
		case 4:
			return "Wed";
		case 5:
			return "Thu";
		case 6:
			return "Fri";
	}
}

int main() {
	int userMonth, userYear, width = 10, counter = 1, once = 0;

	cout << "Insert a month and an year: ";
	cin >> userMonth >> userYear;
	
	for (counter; counter <= 7; counter++) {
		cout << setw(width ) << day(counter % 7);
	}
	
	counter = 1;

	cout << endl;

	for (int i = 1; i <= numberOfdays(userMonth, userYear); i++) {
		counter %= 7;

		if (dayOfweek(i, userMonth, userYear) != counter && once <= 7) {
			i--;
			once++;
			cout << "Aaa";
		}

		else if (counter == 0) {
			cout << setw(width) << i << endl;
			counter = 1;
			once = 8;
		}

		else {
			cout << setw(width) << i;
			once = 8 ;
		}
		
		counter += 1;
	}
	
	return 0;
}