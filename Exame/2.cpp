#include "2.h"

Board::Board(size_t numLines = 10, size_t numColumns = 10) { //Exercise 2.b)
	for (int y; y < size(board); y++)
		for (int x; x < size(board[x]); x++)
			board[y][x] = -1;
}