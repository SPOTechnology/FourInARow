#include <iostream>

int possibleMove(int board[6]){
	for(int y = 0; y < 6; ++y){
		if(board[y] == 0){
			return y;
		}
	}
	return -1;
}
