#pragma once
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

class Card {
		friend ostream& operator<<(ostream& os, const Card& card);
	public:
		Card();
		Card(char suit, unsigned int rank, unsigned int points, bool isFaceUp);
		char getSuit() const; // retorna o naipe
		unsigned int getRank() const; // retorna o valor
		unsigned int getPoints() const; // retorna a pontuação da carta
	private:
		char suit; // o naipe da carta: 'C' - copas, 'E' - espadas, 'O' - ouros, 'P' - paus
		unsigned int rank; // o valor da carta: 1 - ás, 2 - duque, ..., 11 - valete, 12 - dama, 13 - rei
		unsigned int points; // a pontuação da carta: ás - 11, duque - 2, ..., valete/dama/rei - 10
		bool isFaceUp; // true = face virada para cima
};

class Hand {
	public:
		Hand();
		void addCard(Card c); // acrescenta uma carta à mão
		Card getCard(); // retira uma carta da mão
		void show() const; // mostra as cartas da mão, no estado em que cada uma estiver
		unsigned int getPointsTotal() const; // obtém a pontuação total das cartas da mão
	private:
		vector<Card> cards; // o conteúdo da mão
};