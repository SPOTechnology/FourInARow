#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <array>
#include "globals.h"

char checkState(int board[7][6]);
int possibleMove(int board[6]);

long long value[7] = {0};

int benimaxMove(int maxDepth, int board[7][6]) {
	long multiplier[8] = {100000000, 100000000, 10000, 10000, 100, 10, 1, 1};

	int _0[7][6];
	int _1[7][6];
	int _2[7][6];
	int _3[7][6];
	int _4[7][6];
	int _5[7][6];
	int _6[7][6];
	int _7[7][6];

	bool check = false;

    maxDepth = 7;
	for(int x = 0; x < 7; ++x) {
		value[x] = 0;
		int moveY = possibleMove(board[x]);
		if(moveY >= 0) {
			for(int i = 0; i < 7; ++i) {
				for(int j = 0; j < 6; ++j) {
					_0[i][j] = board[i][j];
				}
			}
			_0[x][moveY] = 2;
			if(checkState(_0) == '2') {
                return x;
				value[x] += multiplier[0];
				check = true;
			} else {
				check = false;
			}
		}



		if(!check && maxDepth != 1) {
			for(int x1 = 0; x1 < 7; ++x1) {
				moveY = possibleMove(_0[x1]);
				if(moveY >= 0) {
					for(int i = 0; i < 7; ++i) {
						for(int j = 0; j < 6; ++j) {
							_1[i][j] = _0[i][j];
						}
					}
					_1[x1][moveY] = 1;
					if(checkState(_1) == '1') {
						value[x] -= multiplier[1];
						check = true;
					} else {
						check = false;
					}
				}



				if(!check && maxDepth != 2) {
					for(int x2 = 0; x2 < 7; ++x2) {
						moveY = possibleMove(_1[x2]);
						if(moveY >= 0) {
							for(int i = 0; i < 7; ++i) {
								for(int j = 0; j < 6; ++j) {
									_2[i][j] = _1[i][j];
								}
							}
							_2[x2][moveY] = 2;
							if(checkState(_2) == '2') {
								value[x] += multiplier[2];
								check = true;
							} else {
								check = false;
							}
						}



						if(!check && maxDepth != 3) {
							for(int x3 = 0; x3 < 7; ++x3) {
								moveY = possibleMove(_2[x3]);
								if(moveY >= 0) {
									for(int i = 0; i < 7; ++i) {
										for(int j = 0; j < 6; ++j) {
											_3[i][j] = _2[i][j];
										}
									}
									_3[x3][moveY] = 1;
									if(checkState(_3) == '1') {
										value[x] -= multiplier[3];
										check = true;
									} else {
										check = false;
									}
								}


								if(!check && maxDepth != 4) {
									for(int x4 = 0; x4 < 7; ++x4) {
										moveY = possibleMove(_3[x4]);
										if(moveY >= 0) {
											for(int i = 0; i < 7; ++i) {
												for(int j = 0; j < 6; ++j) {
													_4[i][j] = _3[i][j];
												}
											}
											_4[x4][moveY] = 2;
											if(checkState(_4) == '2') {
												value[x] += multiplier[4];
												check = true;
											} else {
												check = false;
											}
										}



										if(!check && maxDepth != 5) {
											for(int x5 = 0; x5 < 7; ++x5) {
												moveY = possibleMove(_4[x5]);
												if(moveY >= 0) {
													for(int i = 0; i < 7; ++i) {
														for(int j = 0; j < 6; ++j) {
															_5[i][j] = _4[i][j];
														}
													}
													_5[x5][moveY] = 1;
													if(checkState(_5) == '1') {
														value[x] -= multiplier[5];
														check = true;
													} else {
														check = false;
													}
												}



												if(!check && maxDepth != 6) {
													for(int x6 = 0; x6 < 7; ++x6) {
														moveY = possibleMove(_5[x6]);
														if(moveY >= 0) {
															for(int i = 0; i < 7; ++i) {
																for(int j = 0; j < 6; ++j) {
																	_6[i][j] = _5[i][j];
																}
															}
															_6[x6][moveY] = 2;
															if(checkState(_6) == '2') {
																value[x] += multiplier[6];
																check = true;
															} else {
																check = false;
															}
														}



														if(!check && maxDepth != 7) {
															for(int x7 = 0; x7 < 7; ++x7) {
																moveY = possibleMove(_6[x7]);
																if(moveY >= 0) {
																	for(int i = 0; i < 7; ++i) {
																		for(int j = 0; j < 6; ++j) {
																			_7[i][j] = _6[i][j];
																		}
																	}
																	_7[x][moveY] = 1;
																	if(checkState(_7) == '1') {
																		value[x] -= multiplier[7];
																		check = true;
																	} else {
																		check = false;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}






	int bestMove = -1;
	int bestValue = -100;

	if(possibleMove(board[3]) >= 0) {
		bestMove = 3;
		bestValue = value[3];
	} else if(possibleMove(board[2]) >= 0) {
		bestMove = 2;
		bestValue = value[2];
	} else if(possibleMove(board[4]) >= 0) {
		bestMove = 4;
		bestValue = value[4];
	} else if(possibleMove(board[1]) >= 0) {
		bestMove = 1;
		bestValue = value[1];
	} else if(possibleMove(board[5]) >= 0) {
		bestMove = 5;
		bestValue = value[5];
	} else if(possibleMove(board[0]) >= 0) {
		bestMove = 0;
		bestValue = value[0];
	} else if(possibleMove(board[6]) >= 0) {
		bestMove = 6;
		bestValue = value[6];
	} else {
		return 9;
	}
	for(int i = 0; i < 7; ++i) {
		if((value[i] > bestValue) && (possibleMove(board[i]) >= 0)) {
			bestMove = i;
			bestValue = value[i];
		}
	}
	return bestMove;
}
