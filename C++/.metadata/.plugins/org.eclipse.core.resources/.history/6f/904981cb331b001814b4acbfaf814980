#include <iostream>

#include "globals.h"

using namespace std;

char checkState(int board[7][6]);
int neuralMove();
int benimaxMove(int opDepth, int board[7][6]);
int possibleMove(int board[6]);
void printBoard();
int canEnd(int player);

void playGame(int opDepth) {
	while (1) {
		char state = checkState(brd);
		if(state == 'p') {
			int m = canEnd(2);
			if(m == -1) {
				m = neuralMove();
			}
            brd[m][possibleMove(brd[m])] = 2;
			cout << "NN move: " << m << endl;
			printBoard();
		} else {
			cout << "Benimax wins" << endl;
			printBoard();
			break;
		}

		state = checkState(brd);
		if(state == 'p') {
			int m = canEnd(1);
			if(m == -1) {
				m = benimaxMove(opDepth, brd);
			}
            brd[m][possibleMove(brd[m])] = 1;
			cout << "Benimax move: " << m << endl;
			printBoard();
		} else {
			cout << "NN wins" << endl;
			fitness += 1000;
			printBoard();
			break;
		}
	}
}
