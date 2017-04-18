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
	game[0][1] = f;
}
void Board::move(int fromr, int fromc, int tor, int toc) {
	game[tor][toc] = game[fromr][fromc];
	Piece p;
	game[fromr][fromc].setOccupant(p);
}
void Board::fight(int attackr, int attackc, int defendr, int defendc) {
	if (game[attackr][attackc].getOccupant().getValue() > game[defendr][defendc].getOccupant().getValue())
	{
		move(attackr, attackc, defendr, defendc);
	}
	else if ((game[attackr][attackc].getOccupant().getValue() == game[defendr][defendc].getOccupant().getValue()))
	{
		Piece p;
		game[attackr][attackc].setOccupant(p);
		game[defendr][defendc].setOccupant(p);
	}
	else
	{
		Piece p;
		game[attackr][attackc].setOccupant(p);
	}
}
vector<pair<int,int>> Board::getMoves(int r, int c) {
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
	bool side = game[r][c].getOccupant().getSide();
	vector<pair<int, int>> attackMoves;
	if (r > 0 && game[r - 1][c].getAccessible() == true && game[r - 1][c].getOccupied() == true && (game[r - 1][c].getOccupant().getSide() != side))
	{
		attackMoves.push_back(make_pair(r - 1, c));
	}
	if (r < 9 && game[r + 1][c].getAccessible() == true && game[r + 1][c].getOccupied() == true && (game[r + 1][c].getOccupant().getSide() != side))
	{
		attackMoves.push_back(make_pair(r + 1, c));
	}
	if (c > 0 && game[r][c - 1].getAccessible() == true && game[r][c - 1].getOccupied() == true && (game[r][c - 1].getOccupant().getSide() != side))
	{
		attackMoves.push_back(make_pair(r, c - 1));
	}
	if (c < 9 && game[r][c + 1].getAccessible() == true && game[r][c + 1].getOccupied() == true && (game[r][c + 1].getOccupant().getSide() != side))
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
				if ((game[i][j].getOccupant().getSide() == true) && (game[i][j].getOccupant().getValue() != -1))
				{
					cout << "r";
				}
				else if(game[i][j].getOccupant().getValue() != -1)
				{
					cout << "b";
				}
				cout << game[i][j].getOccupant().getValue();
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
