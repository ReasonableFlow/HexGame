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

class HexGameApp {



private:
	//int boardSize = 5;
	/*Board* board = new Board(boardSize);*/
	Player* p1;
	Player* p2;

public:

	void playGame();

};

void HexGameApp::playGame() {

	int boardSize = 5;
	cout << "Input the size of board:" << endl;
	cin >> boardSize;
	if (boardSize < 3)
		boardSize = 3;

	Board* board = new Board(boardSize);





	int choice;

	//cout << "Choose gamemode: ";

	cout << "			        Hex Game" << endl;
	cout << "		  =============================================================				" << endl;
	cout << endl;
	cout << endl;



	cout << "Please select which mode you want to play!" << endl;
	cout << endl;


	cout << "||   Press 1 for Human v Human       ||" << endl;
	cout << "||   Press 2 for Human V Random      ||" << endl;
	cout << "||   Press 3 for Random v Random     || " << endl;
	cout << "||   Press 4 for Random v SmartPlayer || " << endl;
	cout << "||   Press 5 for Human v MonteCarlo  || " << endl;

	cout << endl;
	cin >> choice;

	cout << endl;


	//The two different players

	if (choice == 1) {
		p1 = new HumanPlayer(1, "Human (Red)");
		p2 = new HumanPlayer(-1, "Human (Blue)");

		cout << "You have selected Human VS Human, Enjoy!" << endl;

	}

	if (choice == 2) {

		p1 = new HumanPlayer(1, "Human (Red)");
		p2 = new RandomPlayer(-1, "Random (Blue)");

		cout << "You have selected Player VS Random, Enjoy!" << endl;
	}

	if (choice == 3) {

		p1 = new RandomPlayer(1, "Random (Red)");
		p2 = new RandomPlayer(-1, "Random (Blue)");

		cout << "You have selected Random VS Random, Enjoy!" << endl;
	}
	if (choice == 4) {

		p1 = new RandomPlayer(1, "Random (Red)");
		p2 = new SmartPlayer(-1, "SmartPlayer (Blue)");

		cout << "You have selected Random VS Smart Player, Enjoy!" << endl;
	}

	if (choice == 5) {

		p1 = new HumanPlayer(1, "Random (Red)");
		p2 = new MonteCarlo(-1, "Monte Carlo (Blue)");

		cout << "You have selected Human VS MonteCarlo, Enjoy!" << endl;
	}
	

	HexGame game(board, p1, p2);
	game.play();

	delete board;
	delete p1;
	delete p2;


}