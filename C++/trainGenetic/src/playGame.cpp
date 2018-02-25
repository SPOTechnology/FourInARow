#include <iostream>

#include "globals.h"

using namespace std;

char checkState(int board[7][6]);
int neuralMove(int population, int genome, int startingMove);
int benimaxMove(int opDepth, int board[7][6]);
int possibleMove(int board[6]);
void printBoard();
int canEnd(int player);

void playGame(int opDepth, int population, int genome, int startingMove) {
	while (1) {
		char state = checkState(brd);
		if (state == 'p') {
			int m = canEnd(2);
			if (m == -1) {
				m = neuralMove(population, genome, startingMove);
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
		if (state == 'p') {
			int m = canEnd(1);
			if (m == -1) {
				m = benimaxMove(opDepth, brd);
			}
			brd[m][possibleMove(brd[m])] = 1;
			cout << "Benimax move: " << m << endl;
			printBoard();
		} else {
			cout << "NN wins" << endl;
			if (startingMove == 1 || startingMove == 5) {
				fitness[population][genome].fit += 2000;
			} else if (startingMove == 2 || startingMove == 4) {
				fitness[population][genome].fit += 3000;
			} else if (startingMove == 3) {
				fitness[population][genome].fit += 10000;
			} else {
				fitness[population][genome].fit += 1000;
			}
			printBoard();
			break;
		}
	}
}
