/**
 * Declaration
 *
 * I hereby certify that no other part of this submission has been copied from any other sources, including the
 * Internet, books or other student’s work except the ones I have listed below. No part of the code has been
 * written/produced for me by another person or copied from any other source.
 *
 * I hold a copy of this assignment that I can produce if the original is lost or damaged.
 */

#include<iostream>
#include<string>
#include <list>
#include <stack>
#include <vector>
#include <Windows.h>
#include <queue>

using namespace std;

#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "Cell.h"
#include "MonteCarlo.h"
#include "SmartPlayer.h"
#include "HexGame.h"
#include "HexGameApp.h""

int main() {

	srand(time(0));

	HexGameApp h;
	h.playGame();
	
	return 0;
}

