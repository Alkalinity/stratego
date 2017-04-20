//
//
//

#include "board.h"
#include <iostream>
#include <iomanip>

Board::Board() {
	// Blue Team
	Spy bspyOne(false);
	Normal_Piece btwoOne(2, false);
	Normal_Piece btwoTwo(2, false);
	Normal_Piece btwoThree(2, false);
	Normal_Piece btwoFour(2, false);
	Normal_Piece btwoFive(2, false);
	Normal_Piece btwoSix(2, false);
	Normal_Piece btwoSeven(2, false);
	Normal_Piece btwoEight(2, false);

	Three bthreeOne(false);
	Three bthreeTwo(false);
	Three bthreeThree(false);
	Three bthreeFour(false);
	Three bthreeFive(false);

	Normal_Piece bfourOne(4, false);
	Normal_Piece bfourTwo(4, false);
	Normal_Piece bfourThree(4, false);
	Normal_Piece bfourFour(4, false);

	Normal_Piece bfiveOne(5, false);
	Normal_Piece bfiveTwo(5, false);
	Normal_Piece bfiveThree(5, false);
	Normal_Piece bfiveFour(5, false);

	Normal_Piece bsixOne(6, false);
	Normal_Piece bsixTwo(6, false);
	Normal_Piece bsixThree(6, false);
	Normal_Piece bsixFour(6, false);

	Normal_Piece bsevenOne(7, false);
	Normal_Piece bsevenTwo(7, false);
	Normal_Piece bsevenThree(7, false);


	Normal_Piece beightOne(8, false);
	Normal_Piece beightTwo(8, false);

	Normal_Piece bnineOne(9, false);

	Normal_Piece btenOne(10, false);

	Normal_Piece bBombOne(99, false);
	Normal_Piece bBombTwo(99, false);
	Normal_Piece bBombThree(99, false);
	Normal_Piece bBombFour(99, false);
	Normal_Piece bBombFive(99, false);
	Normal_Piece bBombSix(99, false);

	Normal_Piece bflag(0, false);

	// Red Team
	Spy rspyOne(true);

	Normal_Piece rtwoOne(2, true);
	Normal_Piece rtwoTwo(2, true);
	Normal_Piece rtwoThree(2, true);
	Normal_Piece rtwoFour(2, true);
	Normal_Piece rtwoFive(2, true);
	Normal_Piece rtwoSix(2, true);
	Normal_Piece rtwoSeven(2, true);
	Normal_Piece rtwoEight(2, true);

	Three rthreeOne(true);
	Three rthreeTwo(true);
	Three rthreeThree(true);
	Three rthreeFour(true);
	Three rthreeFive(true);

	Normal_Piece rfourOne(4, true);
	Normal_Piece rfourTwo(4, true);
	Normal_Piece rfourThree(4, true);
	Normal_Piece rfourFour(4, true);

	Normal_Piece rfiveOne(5, true);
	Normal_Piece rfiveTwo(5, true);
	Normal_Piece rfiveThree(5, true);
	Normal_Piece rfiveFour(5, true);

	Normal_Piece rsixOne(6, true);
	Normal_Piece rsixTwo(6, true);
	Normal_Piece rsixThree(6, true);
	Normal_Piece rsixFour(6, true);

	Normal_Piece rsevenOne(7, true);
	Normal_Piece rsevenTwo(7, true);
	Normal_Piece rsevenThree(7, true);


	Normal_Piece reightOne(8, true);
	Normal_Piece reightTwo(8, true);

	Normal_Piece rnineOne(9, true);

	Normal_Piece rtenOne(10, true);

	Normal_Piece rBombOne(99, true);
	Normal_Piece rBombTwo(99, true);
	Normal_Piece rBombThree(99, true);
	Normal_Piece rBombFour(99, true);
	Normal_Piece rBombFive(99, true);
	Normal_Piece rBombSix(99, true);

	Normal_Piece rflag(0, true);
	
	gameState = 0;
	redTurn = true;
	color green = { 0,1,0 };
	color blue = { 0,0,1 };
	Normal_Piece p(2, true);
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

	Normal_Piece q(5, false);
	Tile f(green, q);

	game[0][0] = t;
	game[0][1] = f;
}
void Board::move(int fromr, int fromc, int tor, int toc) {
	if (game[tor][toc].getOccupied())
	{
		fight(fromr, fromc, tor, toc);
	}
	else
	{
		game[tor][toc] = game[fromr][fromc];
		Piece p;
		game[fromr][fromc].setOccupant(p);
	}
}
void Board::fight(int attackr, int attackc, int defendr, int defendc) {
	cout << "Your: " << game[attackr][attackc].getOccupant().getValue() << " fought their: " << game[defendr][defendc].getOccupant().getValue();
	if (game[defendr][defendc].getOccupant().getValue() == 0)
	{
		cout << " You captured their flag!" << endl;
		if (game[defendr][defendc].getOccupant().getSide() == true)
		{
			gameState = 1;
		}
		else
		{
			gameState = 2;
		}
	}
	else if (game[attackr][attackc].getOccupant().getValue() > game[defendr][defendc].getOccupant().getValue())
	{
		move(attackr, attackc, defendr, defendc);
		cout << "...You won!" << endl;
	}
	else if ((game[attackr][attackc].getOccupant().getValue() == game[defendr][defendc].getOccupant().getValue()))
	{
		cout << "...You both died." << endl;
		Piece p;
		game[attackr][attackc].setOccupant(p);
		game[defendr][defendc].setOccupant(p);
	}
	else
	{
		cout << "...You lost." << endl;
		Piece p;
		game[attackr][attackc].setOccupant(p);
	}
}
vector<pair<int,int>> Board::getMoves(int r, int c) {
	vector<pair<int, int>> moves;
	bool side = game[r][c].getOccupant().getSide();
	//return no moves for bombs and flags
	if(game[r][c].getOccupant().getValue()==0 || game[r][c].getOccupant().getValue() == 99)
	{
		return moves;
	}
	//get moves for scout piece(2)
	else if (game[r][c].getOccupant().getValue() == 2)
	{
		//up column
		int i = c-1;
		while (i>=0 && game[r][i].getOccupant().getValue() == -1)
		{
			moves.push_back(make_pair(r, i));
			i--;
		}
		if (i >= 0 && game[r][i].getOccupant().getSide() != side)
		{
			moves.push_back(make_pair(r, i));
		}

		//down column
		i = c + 1;
		while (i < 10 && game[r][i].getOccupant().getValue() == -1)
		{
			moves.push_back(make_pair(r, i));
			i++;
		}
		if (i < 10 && game[r][i].getOccupant().getSide() != side)
		{
			moves.push_back(make_pair(r, i));
		}

		//left in row
		i = r - 1;
		while (i >= 0 && game[i][c].getOccupant().getValue() == -1)
		{
			moves.push_back(make_pair(i, c));
			i--;
		}
		if (i >= 0 && game[i][c].getOccupant().getSide() != side)
		{
			moves.push_back(make_pair(i, c));
		}

		//right in row
		i = r + 1;
		while (i < 10 && game[i][c].getOccupant().getValue() == -1)
		{
			moves.push_back(make_pair(i, c));
			i++;
		}
		if (i < 10 && game[i][c].getOccupant().getSide() != side)
		{
			moves.push_back(make_pair(i, c));
		}
	}
	//return the moves for all other pieces
	else 
	{
		if ((r > 0 && game[r - 1][c].getAccessible() == true && game[r - 1][c].getOccupied() == false) || (game[r - 1][c].getOccupied() == true && (game[r - 1][c].getOccupant().getSide() != side)))
		{
			moves.push_back(make_pair(r - 1, c));
		} 
		if ((r < 9 && game[r + 1][c].getAccessible() == true && game[r + 1][c].getOccupied() == false) || (game[r + 1][c].getOccupied() == true && (game[r + 1][c].getOccupant().getSide() != side)))
		{
			moves.push_back(make_pair(r + 1, c));
		}
		if ((c > 0 && game[r][c - 1].getAccessible() == true && game[r][c - 1].getOccupied() == false) || (game[r][c - 1].getOccupied() == true && (game[r][c - 1].getOccupant().getSide() != side)))
		{
			moves.push_back(make_pair(r, c - 1));
		}
		if ((c < 9 && game[r][c + 1].getAccessible() == true && game[r][c + 1].getOccupied() == false) || (game[r][c + 1].getOccupied() == true && (game[r][c + 1].getOccupant().getSide() != side)))
		{
			moves.push_back(make_pair(r, c + 1));
		}
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
	if (redTurn)
	{
		cout << endl << "RED PLAYER'S TURN:" << endl;
	}
	else
	{
		cout << endl << "BLUE PLAYER'S TURN:" << endl;
	}
	cout << endl << "      0      1      2      3      4      5      6      7      8      9" << endl << "   -----------------------------------------------------------------------" << endl;
	for (int i = 0; i<10; ++i)
	{
		cout << i << ": | ";
		for (int j = 0; j < 10; ++j)
		{
			if (game[i][j].getAccessible() == false) cout << "{~~}";
			else
			{
				cout << "{";
				if ((game[i][j].getOccupant().getSide() == redTurn) && (game[i][j].getOccupant().getValue() != -1))
				{
					cout << setw(2) << game[i][j].getOccupant().getValue();
				}
				else if(game[i][j].getOccupant().getValue() != -1)
				{
					cout << "XX";
				}
				else
				{
					cout << "[]";
				}
				
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
	if (game[r][c].getOccupant().getSide() != redTurn) return false;
	return true;
}
int Board::getGameState() {
	return gameState;
}
void Board::nextTurn() {
	redTurn = !redTurn;
}
void Board::saveBoard()
{
	//Save Function
	ofstream outfile("saveFile.txt");
	if (outfile) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++)
			{
				if (game[i][j].getOccupant().getSide() == false)
				{
					outfile << game[i][j].getOccupant().getValue()+11 << endl;
				}
				else
				{
					outfile << game[i][j].getOccupant().getValue() << endl;
				}
			}
		}
	}
	outfile.close();
}
void Board::loadBoard()
{
	//Load Function

	ifstream infile("saveFile.txt");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((i == 4 || i == 5) && (j == 2 || j == 3 || j == 6 || j == 7))
			{
				color blue = { 0,0,1 };
				Tile t(blue, false);
				game[i][j] = t;
			}
			else
			{
				int value;
				infile >> value;
				if (value > 10 && value != 99)
				{
					value -= 10;
					if (value == 3)
					{
						Three f(false);
						game[i][j].setOccupant(f);
					}
					else if (value == 1)
					{
						Spy s(false);
						game[i][j].setOccupant(s);
					}
					else
					{
						Normal_Piece n(value, false);
						game[i][j].setOccupant(n);
					}
				}
				else
				{
					if (value == 3)
					{
						Three f(false);
						game[i][j].setOccupant(f);
					}
					else if (value == 1)
					{
						Spy s(false);
						game[i][j].setOccupant(s);
					}
					else
					{
						Normal_Piece n(value, false);
						game[i][j].setOccupant(n);
					}
				}
			}
			//cout << game[i][j] << ' ';
		}
		cout << endl;
	}
}

