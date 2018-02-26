int possibleMove(int board[6]);

char checkState(int board[7][6]) {
	int possible = 0;
	for (int i = 0; i < 7; ++i) {
		if (possibleMove(board[i]) == -1) {
			++possible;
		}
	}
	if (possible == 7) {
		return 't';
	}
	for (int y = 0; y < 6; ++y) {		//check horizontal win
		for (int x = 0; x <= 3; ++x) {
			if ((board[x][y] == 1) && (board[x + 1][y] == 1)
					&& (board[x + 2][y] == 1) && (board[x + 3][y] == 1)) {
				return '1';
			}
		}
	}
	for (int x = 0; x < 7; ++x) {		//check vertical win
		for (int y = 2; y >= 0; --y) {
			if ((board[x][y] == 1) && (board[x][y + 1] == 1)
					&& (board[x][y + 2] == 1) && (board[x][y + 3] == 1)) {
				return '1';
			}
		}
	}
	for (int y = 0; y <= 2; ++y) {		//check slope 1 win
		for (int x = 0; x <= 3; ++x) {
			if ((board[x][y] == 1) && (board[x + 1][y + 1] == 1)
					&& (board[x + 2][y + 2] == 1)
					&& (board[x + 3][y + 3] == 1)) {
				return '1';
			}
		}
	}
	for (int y = 0; y <= 2; ++y) {		//check slope -1 win
		for (int x = 6; x >= 3; --x) {
			if ((board[x][y] == 1) && (board[x - 1][y + 1] == 1)
					&& (board[x - 2][y + 2] == 1)
					&& (board[x - 3][y + 3] == 1)) {
				return '1';
			}
		}
	}
	for (int y = 0; y < 6; ++y) {		//check horizontal win
		for (int x = 3; x >= 0; --x) {
			if ((board[x][y] == 2) && (board[x + 1][y] == 2)
					&& (board[x + 2][y] == 2) && (board[x + 3][y] == 2)) {
				return '2';
			}
		}
	}
	for (int x = 0; x < 7; ++x) {		//check vertical win
		for (int y = 2; y >= 0; --y) {
			if ((board[x][y] == 2) && (board[x][y + 1] == 2)
					&& (board[x][y + 2] == 2) && (board[x][y + 3] == 2)) {
				return '2';
			}
		}
	}
	for (int y = 0; y <= 2; ++y) {		//check slope 1 win
		for (int x = 0; x <= 3; ++x) {
			if ((board[x][y] == 2) && (board[x + 1][y + 1] == 2)
					&& (board[x + 2][y + 2] == 2)
					&& (board[x + 3][y + 3] == 2)) {
				return '2';
			}
		}
	}
	for (int y = 0; y <= 2; ++y) {		//check slope -1 win
		for (int x = 6; x >= 3; --x) {
			if ((board[x][y] == 2) && (board[x - 1][y + 1] == 2)
					&& (board[x - 2][y + 2] == 2)
					&& (board[x - 3][y + 3] == 2)) {
				return '2';
			}
		}
	}
	return 'p';
}
