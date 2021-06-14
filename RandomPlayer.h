#pragma once

using namespace std;

class RandomPlayer : public Player {

public:
	RandomPlayer(int t, string name = "Random") :
		Player(t, name) {
	}
	bool getMove(Board*, int&, int&);
};

bool RandomPlayer::getMove(Board* board, int& x, int& y) {
	bool flag = false;
	int bs = board->getBoardSize();


	while (!flag) {

		

		list <int> empty = board->getEmptyCell();

		int i = rand() % empty.size();
		list <int> ::iterator it = empty.begin();


		advance(it, i);


		x = (*it / board->getBoardSize());
		y = (*it % board->getBoardSize());



		flag = board->validInput(x, y);

		if (flag == false)
			cout << "Invalid input! Please input again." << endl;



	}




	return true;
}