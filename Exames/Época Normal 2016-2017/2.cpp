#include "2.h"

Date::Date(int y, int m, int d) { //Exercise 2.a)
	this->y = y;
	this->m = m;
	this->d = d;
}

bool operator<(const Date &left, const Date &right) { //Exercise 2.b)
	if (left.y <= right.y && left.m <= right.m && left.d < right.d)
		return true;

	else
		return false;
}

istream& operator>>(istream &f, Date &date) { //Exercise 2.c)
	string date_string;
	int year, month, day;
	char hyphen;

	getline(f, date_string);

	istringstream dateStream(date_string);

	dateStream >> year >> hyphen >> month >> hyphen >> day;

	if (hyphen != '-' || year < 0 || month <= 0 || day <= 0) {
		runtime_error message("invalid Date");
		throw message;
	}

	date = Date(year, month, day);

	return f;
}

ostream& operator<<(ostream& f, const Date& date) {
	f << date.y << "-" << date.m << "-" << date.d;

	return f;
}

bool operator==(const Date& left, const Date& right) {
	if (left.y == right.y && left.m == right.m && left.d == right.d)
		return true;

	else
		return false;
}

int main() { //Exercise 2.d)
	Date Date1;
	Date Date2;

	cout << "Date1 (yyyy:mm:dd)? "; 

	try {
		cin >> Date1;
	}
		
	catch (runtime_error message) {
		cerr << message.what();
		return 1;
	}

	cout << "Date2 (yyyy:mm:dd)? ";

	try {
		cin >> Date2;
	}

	catch (runtime_error message) {
		cerr << message.what();
		return 1;
	}

	cout << Date1;

	if (Date1 < Date2)
		cout << " is before ";

	else if (Date1 == Date2)
		cout << " is equal ";

	else
		cout << " is after ";

	cout << Date2;

	return 0;
}