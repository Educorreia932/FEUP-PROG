#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "Date.h"
#include "Address.h"

using namespace std;

class Address;//Necessário senão ocorrem erros 

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

//Auxiliary date functions

bool isBissextile(unsigned int year);
unsigned int numberOfDays(unsigned int month, unsigned int year);
