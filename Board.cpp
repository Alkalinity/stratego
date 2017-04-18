//
//
//

#include "board.h"
#include <iostream>
#include <iomanip>

Board::Board() {
	color green = { 0,1,0 };
	color blue = { 0,0,1 };
	Normal_Piece p(4);
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{	
			if ((i == 4 || i == 5) && (j == 2 || j == 3 || j == 6 || j == 7))
			{
				Tile t(blue, false);
				game[i][j] = t;
			}
		}
	}
	Tile t(green, p);

	Normal_Piece q(5);
	q.setSide(false);
	Tile f(green, q);

	game[0][0] = t;
	game[0][3] = f;
}
void Board::move(int fr, int fc, int tr, int tc) {
	game[tr][tc] = game[fr][fc];
	Piece p;
	game[fr][fc].setOccupant(p);
}
vector<pair<int,int>> Board::getMoves(int r, int c) {
	int row = r;
	int column = c;
	vector<pair<int, int>> moves;
	if (r > 0 && game[r - 1][c].getAccessible() == true && game[r - 1][c].getOccupied() == false)
	{
		moves.push_back(make_pair(r - 1, c));
	}
	if (r < 9 && game[r + 1][c].getAccessible() == true && game[r + 1][c].getOccupied() == false)
	{
		moves.push_back(make_pair(r + 1, c));
	}
	if (c > 0 && game[r][c - 1].getAccessible() == true && game[r][c - 1].getOccupied() == false)
	{
		moves.push_back(make_pair(r, c - 1));
	}
	if (c < 9 && game[r][c + 1].getAccessible() == true && game[r][c + 1].getOccupied() == false)
	{
		moves.push_back(make_pair(r, c + 1));
	}


	return moves;
}
vector<pair<int, int>> Board::getAttacks(int r, int c) {
	int row = r;
	int column = c;
	bool side = game[r][c].getOccupant().getSide();
	vector<pair<int, int>> attackMoves;
	if (r > 0 && game[r - 1][c].getAccessible() == true && game[r - 1][c].getOccupied() == true && game[r - 1][c].getOccupant().getSide() != side)
	{
		attackMoves.push_back(make_pair(r - 1, c));
	}
	if (r < 9 && game[r + 1][c].getAccessible() == true && game[r + 1][c].getOccupied() == true && game[r + 1][c].getOccupant().getSide() != side)
	{
		attackMoves.push_back(make_pair(r + 1, c));
	}
	if (c > 0 && game[r][c - 1].getAccessible() == true && game[r][c - 1].getOccupied() == true && game[r][c - 1].getOccupant().getSide() != side)
	{
		attackMoves.push_back(make_pair(r, c - 1));
	}
	if (c < 9 && game[r][c + 1].getAccessible() == true && game[r][c + 1].getOccupied() == true && game[r][c + 1].getOccupant().getSide() != side)
	{
		attackMoves.push_back(make_pair(r, c + 1));
	}


	return attackMoves;
}
void Board::printBoard() {
	cout << "      0      1      2      3      4      5      6      7      8      9" << endl << "   -----------------------------------------------------------------------" << endl;
	for (int i = 0; i<10; ++i)
	{
		cout << i << ": | ";
		for (int j = 0; j < 10; ++j)
		{
			if (game[i][j].getAccessible() == false) cout << "{~~}";
			else
			{
				cout << "{";
				cout << setw(2) << game[i][j].getOccupant().getValue();
				cout << "}";
			}
			cout << " | ";
		}
		cout << endl << "   -----------------------------------------------------------------------" << endl;
	}
}
bool Board::isValid(int r, int c) {
	if (game[r][c].getOccupant().getValue() == -1) return false;
	if (game[r][c].getAccessible() == false) return false;
	
}
