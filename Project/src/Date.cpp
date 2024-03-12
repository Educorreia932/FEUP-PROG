#include "Date.h"

using namespace std;

Date::Date() {
	this->year = 0;
	this->month = 0;
	this->day = 0;
}

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(string yearMonthDay) {
	this->year = stoi(yearMonthDay.substr(0, 4));
	this->month = stoi(yearMonthDay.substr(5, 2));
	this->day = stoi(yearMonthDay.substr(8, 2));
}

void Date::setYear(unsigned int year) {
	this->year = year;
}

void Date::setMonth(unsigned int month) {
	this->month = month;
}

void Date::setDay(unsigned int day) {
	this->day = day;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

unsigned int Date::getYear() const {
	return year;
}

unsigned int Date::getMonth() const {
	return month;
}

unsigned int Date::getDay() const {
	return day;
}

string Date::getDate() const {
	string string_year = to_string(year), string_month = to_string(month), string_day = to_string(day);

	while (string_year.length() < 4)
		string_year = "0" + string_year;

	while (string_month.length() < 2)
		string_month = "0" + string_month;

	while (string_day.length() < 2)
		string_day = "0" + string_day;

	return string_year + '/' + string_month + '/' + string_day;
}

void Date::show() const {
	cout << getDate();
}

bool Date::isBissextile(unsigned int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;

	else
		return false;
}

unsigned int Date::numberOfDays(unsigned int month, unsigned int year)	 {
	switch (month) {
		case 2:
			if (isBissextile(year))
				return 29;
			else
				return 28;
		case 4:
			return 30;
		case 6:
			return 30;
		case 9:
			return 30;
		case 11:
			return 31;
		default:
			return 31;
	}
}

bool Date::isValid() {
	if (month < 1 || month > 12 || day > numberOfDays(month, year) || day < 1)
		return false;

	else
		return true;
}

bool Date::isEqualTo(const Date & date) {
	if (date.day == day && date.month == month && date.day == day)
		return true;

	else
		return false;
}

bool Date::isNotEqualTo(const Date & date) {
	if (isEqualTo(date))
		return false;

	else
		return true;
}

bool Date::isAfter(const Date & date) {
	if (date.year < year || (date.year == year && date.month < month) || (date.year == year && date.month == month && date.day < day))
		return true;

	else
		return false;
}

bool Date::isBefore(const Date & date) {
	if (date.year > year || (date.year == year && date.month > month) || (date.year == year && date.month == month && date.day > day))
		return true;

	else
		return false;
}