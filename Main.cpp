#include <iostream>
#include "Board.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	Board play;
	play.printBoard();
	int playing = 0;
	while(playing == 0)
	{
		playing = play.getGameState();

		//get the coordinates of the piece to be moved
		int fr = 0, fc = 0;
		do
		{
			cout << "Enter the coordinates of a valid piece you want to move(row then column): " << endl;
			cin >> fr;
			cin >> fc;
		} while (fr<0||fr>9||fc<0||fc>9||!play.isValid(fr, fc));
		
		//return the valid moves for the chosen piece
		cout << "The valid moves for the piece at (" << fr << " , " << fc << ") are: " << endl;
		vector<pair<int, int>> validMoves = play.getMoves(fr,fc);
		int m = 0;
		for (int i = 0; i < validMoves.size(); i++)
		{
			cout << ++m << ":  (" << validMoves[i].first << " , " << validMoves[i].second << ")" << endl;
		}

		//get the desired move
		cout << "Choose one of these moves by entering the number(i.e. '1', '2'...) :" << endl;

		int moveChoice = 0;
		cin >> moveChoice;

		//make the move
		play.move(fr, fc, validMoves[moveChoice - 1].first, validMoves[moveChoice - 1].second);

		//change the turn and print the updated board
		play.nextTurn();
		play.printBoard();

	}
	getchar();

	return 0;
}