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

using namespace std;

class SmartPlayer : public Player {
	
public:
	SmartPlayer(int t, string name = "Smart") :
		Player(t, name) {
	}

	bool getMove(Board* board, int& x, int& y); 
	
};


bool SmartPlayer::getMove(Board* board, int& x, int& y) {

	
	bool flag = false;


	while (!flag) {


		priority_queue<Cell> moves;
		int index;

		for (int i = 0; i < board->getBoardSize(); i++) {
			for (int j = 0; j < board->getBoardSize(); j++) {

				
				Board tempBoard(*board);
				if (tempBoard.validInput(i, j)) {
					tempBoard.addMove(tempBoard.getTurn(), i, j);
					index = i * tempBoard.getBoardSize() + j;
					Cell c(index, tempBoard.heuristics(type));
					moves.push(c);


				}
			}
		}


		if (moves.size() > 0) {
			x = moves.top().index / board->getBoardSize();
			y = moves.top().index % board->getBoardSize();

			//if (board->getGrid(x, y-1) == 1) {

			//	x = (moves.top().index / board->getBoardSize()) + 1;
			//}
		}
		else {
			cout << "Can't find a new replacement" << endl;
		}
		
		flag = board->validInput(x, y);

		cout << "Heuristic = " << moves.top().heuristic << " at ("
			<< (x + 1) << "," << (y + 1) << ")" << endl;

	}
	
	return true;


}