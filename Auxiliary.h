#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string trim(string s);

vector<int> str_to_PackageIds(string line);

string readName(string message = "");
