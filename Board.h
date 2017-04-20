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
	void move(int fromr, int fromc, int tor, int toc);
	vector<pair<int,int>> getMoves(int r, int c);
	vector<pair<int, int>> getAttacks(int r, int c);
	void fight(int attackr, int attackc, int defendr, int defendc);
	void printBoard();
	bool isValid(int r, int c);
	int getGameState();
	void nextTurn();
	void saveBoard();
	void loadBoard();
private:
	Tile game[10][10];
	int n;
	int gameState;
	bool redTurn;
};
#endif