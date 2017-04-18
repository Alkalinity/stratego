#include <iostream>
#include "Board.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	Board play;
	play.printBoard();
	while(1)
	{
		int fr = 0, fc = 0;
		do
		{
			cout << "Enter the coordinates of a valid piece you want to move(row then column): " << endl;
			cin >> fr;
			cin >> fc;
		} while (fr<0||fr>9||fc<0||fc>9||!play.isValid(fr, fc));
		
		cout << "The valid moves for the piece at (" << fr << " , " << fc << ") are: " << endl;
		vector<pair<int, int>> validMoves = play.getMoves(fr,fc);
		vector<pair<int, int>> validAttacks = play.getAttacks(fr, fc);
		int m = 0;
		for (int i = 0; i < validMoves.size(); i++)
		{
			cout << ++m << ":  (" << validMoves[i].first << " , " << validMoves[i].second << ")" << endl;
		}
		for (int i = 0; i < validAttacks.size(); i++)
		{
			cout << ++m << ":  (" << validMoves[i].first << " , " << validMoves[i].second << ")  Attack" << endl;
		}

		validMoves.insert(validMoves.end(), validAttacks.begin(), validAttacks.end());

		cout << "Choose one of these moves by entering the number(i.e. '1', '2'...) :" << endl;

		int moveChoice = 0;
		cin >> moveChoice;
		play.move(fr, fc, validMoves[moveChoice - 1].first, validMoves[moveChoice - 1].second);

		play.printBoard();

	}
	getchar();

	return 0;
}