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

class Board {

private:
	int count;
	int boardSize;
	int turn;
	int** grid;
	list <int> emptyList;
	int index;
public:

	Board(int bs) {
		boardSize = bs;
		grid = new int* [boardSize];
		for (int i = 0; i < boardSize; i++)
			grid[i] = new int[boardSize];

		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++) {
				grid[i][j] = 0;
			}
		turn = 1;
		count = 0;
		


	}

	virtual ~Board() {

		for (int i = 0; i < boardSize; i++)
			delete[] grid[i];

		delete[] grid;
	}

	Board(Board& cboard) {
		boardSize = cboard.getBoardSize();

		grid = new int* [boardSize];
		for (int i = 0; i < boardSize; i++)
			grid[i] = new int[boardSize];

		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++)
				grid[i][j] = 0;

		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++) {
				grid[i][j] = cboard.getGrid(i, j);
			}

		turn = cboard.getTurn();
		count = cboard.getCount();

		emptyList = cboard.getEmptyCell();

		
	}

	int getCount() {

		return count;
	}

	int getBoardSize() {
		return boardSize;
	}

	int getGrid(int x, int y) {
		return grid[x][y];
	}

	int getTurn() {
		return turn;
	}

	list <int> getEmptyCell() {

		return emptyList;
	}

	stack <int> getNeighbour(int playerType, int x, int y) {

		

		return checkNeighbors(playerType, x, y);
	}



	bool validInput(int, int);

	int checkGameFinished();

	bool addMove(int playerType, int x, int y);

	bool checkWinningStatus(int playerType) {
	
		return checkGameWin(playerType);
	}

	void printBoard();
	void emptyCells();
	int heuristics(int playerType);
	stack <int> checkNeighbors(int playerType, int x, int y);
	bool checkStraightLine(int x, int y, int playerType);
	bool checkGameWin(int playerType);
	

	void reStart();



};


int Board::heuristics(int playerType) {

	int length = 0;
	

	for (int i = 0; i < boardSize; i++) {


		stack <int> firstCell;
		vector <int> visited(boardSize * boardSize, false);				//Fill vector 

		int index;
		int currentNode;
		



		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {

				int k = 0;
				for (int l = 0; j + l < boardSize; l++) {

					if (grid[i][j+l] == playerType) {

						k++;
						index = (i)*boardSize + (boardSize - 1);
						firstCell.push(index);


					}
					else {
						break;
						k = 0;
					}
				}

				if (k > length) {
					length = k;
				}

			}
			
		}


		while (!firstCell.empty()) {

			currentNode = firstCell.top();
			firstCell.pop();
			visited[currentNode] = true;



			if (playerType == 1 && currentNode < boardSize) { //Checking if the cell is on the top row


				
				//return true;
			}
			else if (playerType == -1 && currentNode % boardSize == 0) { //Checking if the cell is on first column

				
				//return true;

			}
			else {
				stack <int> neighbours = checkNeighbors(playerType, (currentNode / boardSize), currentNode % boardSize);

				while (!neighbours.empty()) {

					auto n = neighbours.top();
					neighbours.pop();
					if (visited[n] == false) {

						firstCell.push(n);
					}

				}


			}


		}

		
		cout << "The length is " << length << endl;
		return length;

	}

}


int Board::checkGameFinished() {


	count++;


	if (count == (boardSize * boardSize)) {
		cout << "Game finished" << endl;
		return 1;

	}


}



bool Board::checkStraightLine(int x, int y, int playerType) {

	int straight = 0;


	for (int i = 0; i < boardSize; i++) {



		if (grid[x][i] == -1 && playerType == -1) {

			straight += 1;
			


			if (straight == boardSize) {


				cout << "A staright line found!" << endl;
				cout << "Game finished!" << endl;
				return true;

			}

		}


	}


	straight = 0;

	for (int i = 0; i < boardSize; i++) {


		if (grid[i][y] == 1) {

			straight += 1;
			


			if (straight == boardSize && playerType == 1) {


				cout << "A staright line found!" << endl;
				cout << "Game finished!" << endl;
				return true;

			}

		}


	}

}


bool Board::checkGameWin(int playerType) {

	stack <int> firstCell;
	vector <int> visited(boardSize * boardSize, false);				//Fill vector 

	int index;
	int currentNode;


	for (int i = 0; i < boardSize; i++) {

		

		if (playerType == 1 && grid[boardSize - 1][i] == 1) {

			 index = (boardSize - 1) * boardSize + i;
			
			firstCell.push(index);

		}


		if (playerType == -1 && grid[i][boardSize - 1] == -1) {


			index = (i)*boardSize + (boardSize - 1);
			
			firstCell.push(index);

		}
	}


	while (!firstCell.empty()) {

		currentNode = firstCell.top();
		
		firstCell.pop();
		visited[currentNode] = true;



		if (playerType == 1 && currentNode < boardSize) { //Checking if the cell is on the top row


			cout << "Red is the winner!" << endl;
			return true;
		}
		else if (playerType == -1 && currentNode % boardSize == 0) { //Checking if the cell is on first column

			cout << "Blue is the winner!" << endl;
			return true;

		}
		else {
			stack <int> neighbours = checkNeighbors(playerType, (currentNode / boardSize), currentNode % boardSize);

			while (!neighbours.empty()) {

				auto n = neighbours.top();
				neighbours.pop();
				if (visited[n] == false) {

					firstCell.push(n);
				}

			}


		}



	}


	return false;

}



void Board::reStart() {
	for (int row = 0; row < boardSize; row++)
		for (int col = 0; col < boardSize; col++)
			grid[row][col] = -1;

	count = 0;
}


stack <int> Board::checkNeighbors(int playerType, int x, int y) {


	stack <int> neighbours;

	int left, right, up, down, ur, dl;


	if (x >= 0 && x < boardSize && (y - 1) >= 0 && (y - 1) < boardSize && grid[x][y - 1] == playerType) {

		left = x * boardSize + (y - 1);

		neighbours.push(left);

	}


	if (x >= 0 && x < boardSize && (y + 1) >= 0 && (y + 1) < boardSize && grid[x][y + 1] == playerType) {

		right = x * boardSize + (y + 1);


		neighbours.push(right);
	}


	if ((x - 1) >= 0 && (x - 1) < boardSize && y >= 0 && y < boardSize && grid[x - 1][y] == playerType) {

		up = (x - 1) * boardSize + y;

		neighbours.push(up);
	}


	if ((x - 1) >= 0 && (x - 1) < boardSize && (y + 1) >= 0 && (y + 1) < boardSize && grid[x - 1][y + 1] == playerType) {

		ur = (x - 1) * boardSize + (y + 1);

		neighbours.push(ur);
	}


	if ((x + 1) >= 0 && (x + 1) < boardSize && y >= 0 && (y - 1) < boardSize && grid[x + 1][y - 1] == playerType) {

		dl = (x + 1) * boardSize + (y - 1);

		neighbours.push(dl);
	}

	if ((x + 1) >= 0 && (x + 1) < boardSize && y >= 0 && y < boardSize && grid[x + 1][y] == playerType) {

		down = (x + 1) * boardSize + y;

		neighbours.push(down);
	}


	return neighbours;
}




bool Board::validInput(int x, int y) {

	if (x < 0 || y < 0 || x >= boardSize || y >= boardSize) {
		cout << "Move (" << x + 1 << ", " << y + 1 << ") out of range!" << endl;
		return false;
	}

	if (grid[x][y] != 0) {
		cout << "Invalid move. The cell has been occupied." << endl;
		return false;
	}

	return true;
}

void Board::emptyCells() {



	//Clears the list so the list can update after each turn
	emptyList.clear();



	for (int i = 0; i < boardSize; i++) {

		for (int j = 0; j < boardSize; j++) {

			if (grid[i][j] == 0) {

				index = i * boardSize + j;
				emptyList.push_back(index);


			}
		}

	}


}


bool Board::addMove(int playerType, int x, int y) {

	stack <int> neigh = getNeighbour(playerType, x, y);

	if (playerType != turn) {
		cout << "It is not the player's turn!" << endl;
		return false;
	}

	if (grid[x][y] != 0) {
		cout << "Invalid move. The cell has been occupied." << endl;
		return false;
	}

	grid[x][y] = playerType;
	count++;

	if (neigh.empty()) {

		cout << "No neighbours found!";

	}
	else {

		cout << "The neighbours are indices: ";

	}

	//heuristics(playerType);


	while (!neigh.empty())
	{


		cout << "(" << (neigh.top() / boardSize) + 1 << "," << (neigh.top() % boardSize) + 1 << ")" << endl;
		neigh.pop();
	}

	cout << endl;

	turn = -1 * turn;
	return true;
}

void Board::printBoard() {

	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	cout << "   ";
	for (int j = 0; j < boardSize; j++) {
		if (j < 9)
			cout << j + 1 << "   ";
		else
			cout << j + 1 << "  ";
	}
	cout << endl;
	

	cout << "   ";
	for (int j = 0; j < boardSize; j++) {
		
		cout << "----";
		
	}
	cout << endl;
	

	for (int i = 0; i < boardSize; i++) {
		for (int k = 0; k < i; k++)
			cout << "  ";

		if (i < 9)
			cout << " " << i + 1 << " ";
		else
			cout << i + 1 << " ";

		for (int j = 0; j < boardSize; j++) {
			if (grid[i][j] == 0) {
				if (j == 0) {
					cout << "|   |";
				}
				else {
					cout << "   |";
				}
			}
			else if (grid[i][j] == 1) {
				if (j == 0) {

				

					SetConsoleTextAttribute(hConsole, 15);

		
					cout << "|";
					SetConsoleTextAttribute(hConsole, 12);
					cout << " R ";
					SetConsoleTextAttribute(hConsole, 15);
					cout << "|";


				}

				else {
				

					SetConsoleTextAttribute(hConsole, 12);
					cout << " R";
					SetConsoleTextAttribute(hConsole, 15);
					cout << " |";


				}
			}
			else {
				if (j == 0) {
					
					SetConsoleTextAttribute(hConsole, 15);
					cout << "|";
					SetConsoleTextAttribute(hConsole, 11);
					cout << " B ";
					SetConsoleTextAttribute(hConsole, 15);
					cout << "|";


				}
				else {

					SetConsoleTextAttribute(hConsole, 11);
					cout << " B";
					SetConsoleTextAttribute(hConsole, 15);
					cout << " |";

				}
			}
		}
		cout << endl;
	}

	for (int k = 0; k <= boardSize; k++)
		cout << "  ";

	for (int j = 0; j < boardSize; j++) {
		cout << "----";
	}

	cout << endl;
	cout << endl;
}

//#endif /* BOARD_H_ */
