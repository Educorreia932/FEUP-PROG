#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "TravelPack.h"
#include "Date.h"
#include "Address.h"

using namespace std;

class Address;//Necessário senão ocorrem erros 
class TravelPack;

string trim(string s);


//String conversion functions
vector<int> str_to_PackageIds(string line);


//Read Functions
int readOption(int maxOptions, bool includingZero = true);
string readName(string message = "");
unsigned readNIF(string message = "");
int readPositiveInt(string message = "");
int readInt(string message = "");
Date readDate(string message = "");
Address readAddress(string message = "");
string readZipCode(string message = "");
vector<string> readDestinations(string message = "");
vector<int> readBoughtPacks(string message = "");
int readTotalPurchases(string message, vector<TravelPack> &packs, vector<int> boughtPacks, int household);

//Auxiliary date functions

bool isBissextile(unsigned int year);
unsigned int numberOfDays(unsigned int month, unsigned int year);
