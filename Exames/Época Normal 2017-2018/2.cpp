#include "2.h"

Board::Board(size_t numLines, size_t numColumns) { //Exercise 2.b)
	vector<int> line;

	for (int y = 0; y < numLines; y++) {
		for (int x = 0; x < numColumns; x++)
			line.push_back(-1);

		board.push_back(line);
		line.clear();
	}
		
	this->numLines = numLines;
	this->numColumns = numColumns;
}

bool Board::canPutShip(Position pos, char dir, size_t size) { //Exercise 2.c)
	switch (dir) {
		case 'H': // TO DO: test if ship with length 'size' can be put at 'pos', in horizontal direction
			for (int i = pos.lin; i < pos.lin + size; i++)
				if (i < board.size() && board[pos.col][i] != -1)
					return false;

		case 'V': // TO DO, just this line: test if ship ... can be put in vertical direction
			for (int i = pos.col; i < pos.col + size; i++)
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
				for (int i = pos.lin; i < pos.lin + size; i++)
					board[pos.lin][i] = s.id();

			case 'V':
				for (int i = pos.col; i < pos.col + size; i++)
					board[i][pos.col] = s.id();
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

int main() {
	return 0;
}