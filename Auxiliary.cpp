#include "Auxiliary.h"

string trim(string s) {
	s.erase(0, s.find_first_not_of(' ')); //Removes spaces to the left

	if (s[s.length() - 1] == ' ')
		s.erase(s.find_last_of(' ')); //Removes spaces to the right

	return s;
}

//String conversion functions
vector<int> str_to_PackageIds(string line) {

	vector<int> packageIds;
	istringstream s(line);
	int aux;
	char c;
	
	while (s >> aux) {
		packageIds.push_back(aux);
		s >> c;
	}

	return packageIds;
}

//Read functions


//Reads an integer between 0 (inclusive if includingZero is true(default) else exclusive) and maxOption(inclusive)
//Returns that value
int readOption(int maxOptions, bool includingZero) {

	int option;
	if (includingZero) {
		do {
			cout << endl << "Choose your option:  ";
			if (cin >> option && option >= 0 && option <= maxOptions) {
				cin.ignore(1000, '\n');
				return option;
			}
			else {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid input!!" << endl;
			}	
		} while (true);
	}
	else {
		do {
			cout << endl << "Choose your option:  ";
			if (cin >> option && option > 0 && option <= maxOptions) {
				cin.ignore(1000, '\n');
				return option;
			}
			else {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid input!!" << endl;
			}
		} while (true);
	}
}

string readName(string message) {

	string input;
	bool validInput = true;

	do {
		validInput = true;
		cout << message;
		//cin.ignore(1000, '\n');
		getline(cin, input);
		for (size_t i = 0; i < input.length(); i++) {
			if (isdigit(input.at(i)))
				validInput = false;
		}
		if (!validInput || input.length() < 1) {
			cout << "Invalid input!\n";
		}

	} while (!validInput);

	return input;
}

unsigned readNIF(string message) {


	unsigned input;

	do {
		cout << message;
		if (cin >> input && input >= 100000000 && input <= 999999999) {
			return input;
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nInvalid input!!\n" << endl;
		}
	} while (true);
}

int readPositiveInt(string message) {
	int input;

	do {
		cout << message;

		if (cin >> input && input > 0) {
			cin.clear();
			return input;
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input!!" << endl;
		}
	} while (true);
}

int readInt(string message) {

	int input;

	do {
		cout << message;
		if (cin >> input) {
			return input;
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input!!" << endl;
		}
	} while (true);
}

Address readAddress(string message) {
	string aux_street;
	bool invalid = true;

	do 	{
		cout << "Street: ";
		getline(cin, aux_street);
		if (aux_street.length() >= 1)
			invalid = false;
		else
			cerr << "\n ERROR: Invalid input. Please try again:\n";
	} while (invalid);


	int aux_door_number = readPositiveInt("Door Number: ");
	cin.ignore(1000, '\n');

	string aux_apartment;
	invalid = true;

	do	{
		cout << "Apartment: ";
		getline(cin, aux_apartment);

		if (aux_apartment.length() >= 1)
			invalid = false;
		
		else
			cerr << "\n ERROR: Invalid input. Please try again:\n";
	} while (invalid);


	string aux_zip_code = readZipCode("Zipcode: ");
	cin.ignore();

	string aux_locality = readName("Locality: ");


	Address result = Address(aux_street, aux_door_number, aux_apartment, aux_zip_code, aux_locality);
	return result;
}

//Read Functions - Travel Packs

Date readArrivalDate(string message, Date DepartureDate) {
	char c1, c2;
	unsigned int year, month, day;

	do {
		cout << message;

		if ((cin >> year >> c1 >> month >> c2 >> day) && (c1 == '/' && c2 == '/' && year >= 0 && 1 <= month && month <= 12) && (1 <= day && day <= numberOfDays(month, year))) {
			cin.clear();
			cin.ignore(1000, '\n');
			
			Date date = Date(year, month, day);

			if (date.isBefore(DepartureDate)) 
				cout << "Invalid input!!" << endl; 		

			else
				return date;
		}

		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input!!" << endl;
		}

	} while (true);

}

Date readDepartureDate(string message, Date ArrivalDate) {
	char c1, c2;
	unsigned int year, month, day;

	do {
		cout << message;

		if ((cin >> year >> c1 >> month >> c2 >> day) && (c1 == '/' && c2 == '/' && year >= 0 && 1 <= month && month <= 12) && (1 <= day && day <= numberOfDays(month, year))) {
			cin.clear();
			cin.ignore(1000, '\n');

			Date date = Date(year, month, day);

			if (date.isAfter(ArrivalDate))
				cout << "Invalid input!!" << endl;

			else
				return date;
		}

		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input!!" << endl;
		}

	} while (true);

}

string readZipCode(string message) {

	char c1;
	unsigned int first, second;

	do {
		cout << message;
		//cin.ignore(1000, '\n');
		if ((cin >> first >> c1 >> second) && first >= 1000 && first <=9999 && c1 == '-' && second >=0 && second <= 999) {
			ostringstream s;
			s << first << c1 << second;
			return s.str();
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input!!" << endl;
		}

	} while (true);

}

int readMaximumSeats(string message, int sold_seats) {
	int input;

	do {
		cout << message;

		if (cin >> input && input > 0 && input >= sold_seats) {
			cin.clear();
			return input;
		}

		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input!!" << endl;
		}
	} while (true);
}

int readSoldSeats(string message, int maximum_seats) {
	int input;

	do {
		cout << message;

		if (cin >> input && input > 0 && input <= maximum_seats) {
			cin.clear();
			return input;
		}

		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input!!" << endl;
		}
	} while (true);
}

//Ends with Ctrl+Z
vector<string> readDestinations(string message) {

	string s;
	vector <string> result;

	cout << message;
	do {
		getline(cin, s);
		if (cin.eof()) {
			return result;
		}
		else {
			result.push_back(s);
		}

	} while (true);
}

vector<int> readBoughtPacks(string message) {

	int i;
	vector <int> result;

	cout << message;
	do {
		if (cin >> i) {
				result.push_back(i);
		}
		else {
			if (cin.eof()) {
				return result;
			}
			else {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid input!!" << endl;
			}
		}

	} while (true);
}

//Auxiliary date functions
bool isBissextile(unsigned int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;

	else
		return false;
}

unsigned int numberOfDays(unsigned int month, unsigned int year) {
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