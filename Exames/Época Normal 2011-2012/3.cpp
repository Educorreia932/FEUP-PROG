#include "3.h"

Card::Card(char suit, unsigned int rank, unsigned int points, bool isFaceUp) { //Exercise 3.a)
	this->suit = suit;
	this->rank = rank;
	this->points = points;
	this->isFaceUp = isFaceUp;
}

string cardRankToSymbol(unsigned int rank) { 
	string names[] = { " A"," 2"," 3"," 4"," 5"," 6"," 7"," 8"," 9","10"," J"," Q"," K" };

	if (1 <= rank && rank <= 13)
		return names[rank - 1];

	else
		return "Invalid card";
}

ostream &operator<< (ostream &os, const Card &card) { //Exercise 3.b)
	if (card.isFaceUp) 
		os << setw(2) << cardRankToSymbol(card.rank) << "." << card.suit;

	else
		os << "XXXX";
		
	return os;
}

unsigned int  Hand::getPointsTotal() const { //Exercise 3.c)
	unsigned int total_points = 0;
	int ace_counter = 0;

	for (int i = 0; i < cards.size(); i++) {
		total_points += cards[i].getPoints();

		if (cards[i].getRank() == 1)
			ace_counter++;
	}		

	if (total_points > 21)
		total_points -= 10 * ace_counter;

	return total_points;
}