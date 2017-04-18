//
//  CS 120 Stratego
//  board.h
//

#ifndef board_h
#define board_h

#include "tile.h"
#include <vector>

class Board{
public:
	Board();
	void move(int fr, int fc, int tr, int tc);
	vector<pair<int,int>> getMoves(int r, int c);
	vector<pair<int, int>> getAttacks(int r, int c);
	void printBoard();
	bool isValid(int r, int c);
private:
	Tile game[10][10];
	int n;
};
#endif