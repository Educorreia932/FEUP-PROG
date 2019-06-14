#include <iostream>
#include <vector>
#include "1.h"
#include "5.h"

using namespace std;

Book::Book(string description, Date TakenDate, bool lost) {
	this->description = description;
	this->TakenDate = TakenDate;
	this->lost = lost;
}

string Book::getDescription() const {
	return description;
}

Date Book::getTakenDate() const {
	return TakenDate;
}



int main() {
	return 0;
}