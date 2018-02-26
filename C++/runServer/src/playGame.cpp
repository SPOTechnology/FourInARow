#include <iostream>

#include "globals.h"

char checkState(int board[7][6]);
int neuralMove();
int minimaxMove(int maxDepth, int board[7][6]);
int alphabetaMove(int maxDepth, int board[7][6]);
int benimaxMove(int maxDepth, int board[7][6]);
int possibleMove(int board[6]);
int canEnd();

char playGame(int program, bool search) {
	char state = checkState(brd);
	if (state == 'p') {
		if (!search) {
			return state;
		}
		int m = canEnd();
		if (m != -1) {
			automatic = true;
			return m + 48;
		}
		for (int i = 0; i < 7; ++i) {
			int posMove = possibleMove(brd[i]);
			depth += posMove != -1 ? posMove : 7;
		}
		depth /= 8;
		depth += 9;
//		for (int x = 0; x < 7; ++x) {
//			if (possibleMove(brd[x]) == -1 && ) {
//				++depth;
//				break;
//			}
//		}
		if (program == 0) {
			return neuralMove() + 48;
		} else if (program == 1) {
			return minimaxMove(10, brd) + 48;
		} else if (program == 2) {
			return benimaxMove(depth, brd) + 48;
		} else {
			depth *= 2;
			return alphabetaMove(depth, brd) + 48;
		}
	} else if (state == '2') {
		return 'c';
	} else if (state == '1') {
		return 'h';
	} else {
		return 't';
	}
	return 'e';
}
