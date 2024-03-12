#pragma once
#include "coin.h"
#include <map>

using namespace std;

class Purse { //Exercise 4.a)
public:
	Purse();
	void insertCoin(Coin Coin);
	void insertCoins(map <Coin, int> coinsToInsert);
	void showCoins() const;
	double getTotalAmount() const;
	Coin removeCoin(Coin Coin);
	map<Coin, int> removeAmount(double amount);
	map<Coin, int> exchangeCoin(Coin Coin);
private:	
	map <Coin, int> Coins; //«Coin» é o tipo de moeda e «int» é o número de moedas desse tipo
};