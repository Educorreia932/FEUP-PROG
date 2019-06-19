#include "purse.h"

int main() { //Exercise 4.b)
	Purse p1;
	Purse p2;

	p1.insertCoin(Coin(2, 'E')); //insere uma moeda de 2 euros em cada um;
	p2.insertCoin(Coin(2, 'E'));

	map <Coin, int> coinsToInsert;

	coinsToInsert.insert(pair <Coin, int> (Coin(10, 'C'), 5));
	coinsToInsert.insert(pair <Coin, int>(Coin(20, 'C'), 5));
	coinsToInsert.insert(pair <Coin, int>(Coin(50, 'C'), 1));
	coinsToInsert.insert(pair <Coin, int>(Coin(1, 'E'), 1));

	p1.insertCoins(coinsToInsert); //insere as seguintes moedas em p1: 5 moedas de 10 cêntimos, 5 moedas de 20 cêntimos, 1 moeda de 50 cêntimos e 1 moeda de 1 euro.
	
	p2.insertCoins(p1.exchangeCoin(p2.removeCoin(Coin(2, 'E')))); //remove a moeda de 2 euros de p2, "solicita" a p1 que troque essa moeda por moedas mais pequenas e insere estas moedas em p2.

	p2.showCoins(); //mostra o conteúdo de p2.

	return 0;
}