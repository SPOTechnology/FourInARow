#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "globals.h"

using namespace std;

int possibleMove(int board[6]);

void printBoard(int mov)
{

    char buffer[1000];

        snprintf (buffer, 1000, "\n<br/><br/>Before move:<br/>\n"
              "| %d | %d | %d | %d | %d | %d | %d |<br/>\n"
              "| %d | %d | %d | %d | %d | %d | %d |<br/>\n"
              "| %d | %d | %d | %d | %d | %d | %d |<br/>\n"
              "| %d | %d | %d | %d | %d | %d | %d |<br/>\n"
              "| %d | %d | %d | %d | %d | %d | %d |<br/>\n"
              "| %d | %d | %d | %d | %d | %d | %d |<br/>\n",
              brd[0][5], brd[1][5], brd[2][5], brd[3][5], brd[4][5], brd[5][5], brd[6][5],
              brd[0][4], brd[1][4], brd[2][4], brd[3][4], brd[4][4], brd[5][4], brd[6][4],
              brd[0][3], brd[1][3], brd[2][3], brd[3][3], brd[4][3], brd[5][3], brd[6][3],
              brd[0][2], brd[1][2], brd[2][2], brd[3][2], brd[4][2], brd[5][2], brd[6][2],
              brd[0][1], brd[1][1], brd[2][1], brd[3][1], brd[4][1], brd[5][1], brd[6][1],
              brd[0][0], brd[1][0], brd[2][0], brd[3][0], brd[4][0], brd[5][0], brd[6][0]
             );

    cout << buffer << endl;

    if(mov >= 0 && mov <= 6)
    {
        brd[mov][possibleMove(brd[mov])] = 2;

        snprintf (buffer, 1000, "<br/>After move:<br/>\n"
                "| %d | %d | %d | %d | %d | %d | %d |<br/>\n"
                "| %d | %d | %d | %d | %d | %d | %d |<br/>\n"
                "| %d | %d | %d | %d | %d | %d | %d |<br/>\n"
                "| %d | %d | %d | %d | %d | %d | %d |<br/>\n"
                "| %d | %d | %d | %d | %d | %d | %d |<br/>\n"
                "| %d | %d | %d | %d | %d | %d | %d |<br/>\n",
                  brd[0][5], brd[1][5], brd[2][5], brd[3][5], brd[4][5], brd[5][5], brd[6][5],
                  brd[0][4], brd[1][4], brd[2][4], brd[3][4], brd[4][4], brd[5][4], brd[6][4],
                  brd[0][3], brd[1][3], brd[2][3], brd[3][3], brd[4][3], brd[5][3], brd[6][3],
                  brd[0][2], brd[1][2], brd[2][2], brd[3][2], brd[4][2], brd[5][2], brd[6][2],
                  brd[0][1], brd[1][1], brd[2][1], brd[3][1], brd[4][1], brd[5][1], brd[6][1],
                  brd[0][0], brd[1][0], brd[2][0], brd[3][0], brd[4][0], brd[5][0], brd[6][0]
                 );

        cout << buffer;
    }
}



