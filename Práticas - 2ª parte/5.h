#pragma once
#include <string>
#include <vector>
#include "1.h"

class Book {
	public:
		Book(string description, Date TakenDate, bool lost);
		string getDescription() const;
		Date getTakenDate() const;
		bool isLost() const;
	private:
		string description;
		Date TakenDate;
		bool lost;
};

class User {
	public:
		bool isNotActive();
	private:
		vector <Book> borrowed_books;
		bool not_active;
};
