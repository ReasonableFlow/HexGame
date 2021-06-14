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



struct Cell {

public:
	int index;
	int utility;
	int heuristic;

	Cell(int x, double uu ) :index(x), utility(uu) {
	
	
	
	}


//	Cell(int i, int hh) :index(i), heuristic(hh) {}

	bool operator<(const Cell& c) const {
		//return heuristic < c.heuristic;
		return utility < c.utility;
	}

};
