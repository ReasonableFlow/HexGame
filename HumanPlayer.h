#pragma once

using namespace std;

class HumanPlayer : public Player {
public:

	HumanPlayer(int t, string name = "Human") :
		Player(t, name) {
	}
	bool getMove(Board*, int&, int&);
};

bool HumanPlayer::getMove(Board* board, int& x, int& y) {


	bool flag = false;
	int bs = board->getBoardSize();

	while (!flag) {


		//stack <int> neigh = board->getNeighbour(-1, x, y);

		cout << "Input row and column (x, y) between 1 to " << bs << " for "
			<< name << " player:" << endl;
		int row, col;
		cin >> row >> col;

		x = row - 1;
		y = col - 1;


		flag = board->validInput(x, y);


		if (flag == false)
			cout << "Invalid input! Please input again." << endl;

	}

	return true;
}



