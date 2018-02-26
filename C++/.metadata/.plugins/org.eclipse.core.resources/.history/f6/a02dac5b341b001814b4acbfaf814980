#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include "globals.h"

using namespace std;

char checkState(int board[7][6]);
int possibleMove(int board[6]);

int canEnd(int player) {
	int board[7][6];
	if (player == 2) {
		for (int x = 0; x < 7; ++x) {
			for (int i = 0; i < 7; ++i) {
				for (int j = 0; j < 6; ++j) {
					board[i][j] = brd[i][j];
				}
			}
			int possible = possibleMove(board[x]);
			if (possible != -1) {
				board[x][possible] = 2;
				if (checkState(board) == '2') {
					return x;
				}
			}
		}
		for (int x = 0; x < 7; ++x) {
			for (int i = 0; i < 7; ++i) {
				for (int j = 0; j < 6; ++j) {
					board[i][j] = brd[i][j];
				}
			}
			int possible = possibleMove(board[x]);
			if (possible != -1) {
				board[x][possible] = 1;
				if (checkState(board) == '1') {
					return x;
				}
			}
		}
	} else {
		for (int x = 0; x < 7; ++x) {
			for (int i = 0; i < 7; ++i) {
				for (int j = 0; j < 6; ++j) {
					board[i][j] = brd[i][j];
				}
			}
			int possible = possibleMove(board[x]);
			if (possible != -1) {
				board[x][possible] = 1;
				if (checkState(board) == '1') {
					return x;
				}
			}
		}
		for (int x = 0; x < 7; ++x) {
			for (int i = 0; i < 7; ++i) {
				for (int j = 0; j < 6; ++j) {
					board[i][j] = brd[i][j];
				}
			}
			int possible = possibleMove(board[x]);
			if (possible != -1) {
				board[x][possible] = 2;
				if (checkState(board) == '2') {
					return x;
				}
			}
		}
	}
	return -1;
}
