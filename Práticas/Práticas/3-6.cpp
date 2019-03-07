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

string month(int number) {
	switch (number) {
		case 1:
			return "January";
		case 2: 
			return "February";
		case 3:
			return "March";
		case 4:
			return "April";
		case 5:
			return "May";
		case 6:
			return "June";
		case 7:
			return "July";
		case 8:
			return "August";
		case 9:
			return "September";
		case 10:
			return "October";
		case 11:
			return "November";
		case 12:
			return "December";
	}
}

int calendar(int month, int year) {
	int width = 10, counter = 1;
		
	for (counter; counter <= 7; counter++) {
		cout << setw(width ) << day(counter % 7);
	}
	
	counter = 1;

	cout << endl;

	for (int i = 1; i <= numberOfdays(month, year); i++) {
		counter %= 7;
		
		if (dayOfweek(i, month, year) != counter) {
			i--;
			cout << setw(width) << "";
		}

		else if (counter == 0) {
			cout << setw(width) << i << endl;
		}

		else {
			cout << setw(width) << i;

		}
		
		counter += 1;
	}
	
	return 0;
}

int main() {
	int userYear;

	cout << "Insert an year: ";
	cin >> userYear;

	for (int userMonth = 1; userMonth <= 12; userMonth++) {
		cout << month(userMonth) << '/' << userYear << endl;
		calendar(userMonth, userYear);
		cout << endl << endl;
	}

	return 0;
}