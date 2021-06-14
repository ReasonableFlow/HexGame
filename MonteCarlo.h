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



class MonteCarlo : public Player {

public:
	MonteCarlo(int t, string name = "MonteCarlo") :
		Player(t, name) {
	}
	bool getMove(Board*, int&, int&);
	double simulation(Board* board);
	double expansion(int playerType, Board* board);

};



bool MonteCarlo::getMove(Board* board, int& x, int& y) {

	bool flag = false;
	
	while (!flag) {

		
		priority_queue<Cell> moves;

		cout << "Utilities of Moves" << endl;
		for (int i = 0; i < board->getBoardSize(); i++) {
			for (int j = 0; j < board->getBoardSize(); j++) {

				if (board->getGrid(i, j) != 0) { 
					
					continue; 
				}


				Board* tempBoard(board);

				tempBoard->addMove(tempBoard->getTurn(), i, j);
				if (tempBoard->checkGameWin(tempBoard->getTurn()) == tempBoard->getTurn()) {

					int index = (i) * tempBoard->getBoardSize() + (j);
				
					x = index / tempBoard->getBoardSize();
					y = index % tempBoard->getBoardSize();

					return true;
					
				}
				double utility = simulation(tempBoard);

				int index = (i) * tempBoard->getBoardSize() + (j);
				
				Cell c(index,utility);

				moves.push(c);
			}
		}
		if (!moves.empty()) {

			x = moves.top().index / board->getBoardSize();
			y = moves.top().index % board->getBoardSize();
			cout<<x<<y;
			cout << "Best utility " << moves.top().utility << endl;
			
		}

		flag = board->validInput(x, y);

		
	}
	return true;
}


double MonteCarlo::simulation(Board* board) {

	int times = 100;
	double winning = 0.0;
	for (int i = 0; i < times; i++) {

		Board* tempBoard(board);
		int player = (type == 1) ? -1 : 1;
		winning += expansion(player, tempBoard);

	}

	return (winning / (double) times);
}

double MonteCarlo::expansion(int playerType, Board* board) {

	

	if (board->checkGameWin(type) == type) {
		return 1.0;
	}
	else if (board->checkGameWin(-type) == -type) {
		return 0.0;
	}


	//Gets random move

	Board tempBoard(*board);

	int x, y;
	
	list<int> empty = tempBoard.getEmptyCell();


	int i = rand() % empty.size();
	list <int> ::iterator it = empty.begin();


	advance(it, i);


	x = (*it / tempBoard.getBoardSize());
	y = (*it % tempBoard.getBoardSize());
	
	cout << empty.size();

	tempBoard.addMove(type, x, y);
	playerType = (type == 1) ? -1 : 1;


	return expansion(type, board);
}