#include "ValidateFunctions.h"
#include "Structs.h"
#include "GetFunctions.h"
#include "AuxiliaryFunctions.h"

//ValidateAddress

bool ValidateNumber(int Number, char Mode) {
	switch (Mode) {
		case 'N':
			if (Number > 100000000 && Number < 999999999)
				return true;

			else
				return false;

		case 'H':
			if (Number > 0)
				return true;

			else
				return false;
	}	
}

bool ValidateDate(std::string StringDate) {
	Date AuxDate;

	GetDate(AuxDate, StringDate);

	if (AuxDate.Year < 0 || AuxDate.Month < 0 || AuxDate.Month > 12 || AuxDate.Day > NumberOfDays(AuxDate.Month, AuxDate.Year) || AuxDate.Day < 0)
		return false;

	else
		return true;
}
/*
bool ValidateClientVector(std::vector <Client> StructClients, int Index) {
	if (Index > size(StructClients))
		return false;

	else
		return true;
}

bool ValidateTravelPackVector(std::vector <TravelPack> StructClients, int Index) {
	if (Index > size(StructClients))
		return false;

	else
		return true;
}*/