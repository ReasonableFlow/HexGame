#pragma once
/**
 * Declaration
 *
 * I hereby certify that no other part of this submission has been copied from any other sources, including the
 * Internet, books or other student’s work except the ones I have listed below. No part of the code has been
 * written/produced for me by another person or copied from any other source.
 *
 * I hold a copy of this assignment that I can produce if the original is lost or damaged.
 */

 //#ifndef HEXGAME_H_
 //#define HEXGAME_H_

class HexGame {
private:
	Board* board;
	Player* player[2];

public:
	HexGame(Board* b, Player* p1, Player* p2) {
		board = b;
		player[0] = p1;
		player[1] = p2;
	}

	void play();

};





void HexGame::play() {
	int won = 0;
	int fullGame = 0;
	int straightFound = false;
	board->printBoard();

	while (!won) {

		board->emptyCells();

		int playerType = board->getTurn();
		int playerIndex = (playerType == player[0]->getType()) ? 0 : 1;
		int x = -1;
		int y = -1;

		if (!player[playerIndex]->getMove(board, x, y)) {
			cout << "No available move" << endl;
			return;
		}

		cout << player[playerIndex]->getPlayerName() << " plays " << " ("
			<< x + 1 << ", " << y + 1 << "):" << endl;

		if (!board->addMove(playerType, x, y))
			return;

		board->printBoard();
		won = board->checkWinningStatus(playerType);
		if (won == playerType)
			cout << player[playerIndex]->getPlayerName() << " player wins!" << endl;

		straightFound = board->checkStraightLine(x, y, playerType);
		fullGame = board->checkGameFinished();
		
		if (fullGame == 1 || straightFound == true || won) {
			break;
		}

		
	}
}

//#endif /* HEXGAME_H_ */
