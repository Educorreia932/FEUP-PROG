#pragma once
#include "coin.h"
#include <vector>
#include <map>

using namespace std;

struct Coins {
	int two_euro;
	int one_euro;
	int fifty_cents;
	int twenty_cents;
};

class Purse { //Exercise 4.a)
	public:
		Purse();
		void insertCoin(Coin Coin);
		void insertCoins(vector <Coins> Coins);
		void showCoins() const;
		double getTotalAmount() const;
		Coin removeCoin(Coin Coin);
		vector <Coin> removeAmount(double amount);
		vector <Coin> exchangeCoin(Coin Coin);
	private:
		map <Coin Coin, int quantity> coins; //«Coin» é o tipo de moeda e «quantity» é o número de moedas com desse tipo
};