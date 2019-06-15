#include "2.h"

Board::Board(size_t numLines = 10, size_t numColumns = 10) { //Exercise 2.b)
	for (int y = 0; y < board.size(); y++)
		for (int x; x < board[x].size(); x++)
			board[y][x] = -1;
}

bool Board::canPutShip(Position pos, char dir, size_t size) { //Exercise 2.c)
	switch (dir) { // TO DO
		case 'H': // TO DO: test if ship with length 'size' can be put at 'pos', in horizontal direction
			for (int i = pos.lin; i < size; i++)
				if (i < board.size() && board[pos.col][i] != -1)
					return false;

		case 'V': // TO DO, just this line: test if ship ... can be put in vertical direction
			for (int i = pos.col; i < size; i++)
				if (i < board.size() && board[i][pos.lin] != -1)
					return false;

		// DONE. This piece of code was correctly implemented but was carelessly erased …
	}

	return true;
}

bool Board::putShip(const Ship& s) { //Exercise 2.d)
	Position pos = s.pos();
	char dir = s.dir();
	size_t size = s.size();

	if (canPutShip(pos, dir, size)) {
		ships.push_back(s);

		switch (dir) {
			case 'H': 
				for (int i = pos.lin; i < size; i++)
					board[pos.col][i] = s.id();

			case 'V':
				for (int i = pos.lin; i < size; i++)
					board[i][pos.lin] = s.id();
		}

		return true;
	}

	return false;
}

void create10x20Board() { //Exercise 2.e)
	Board b (10, 20);
	unsigned int identifier;
	char symbol, direction;
	Position position;
	size_t size;

	cin >> identifier >> symbol >> position.col >> position.lin >> direction >> size;

	Ship s(identifier, symbol, position, direction, size);

	try {
		if (!b.putShip(s))
			throw "Can't put ship!";

		else
			b.putShip(s);	
	}

	catch (string s) {
		cerr << s;
	}	
}