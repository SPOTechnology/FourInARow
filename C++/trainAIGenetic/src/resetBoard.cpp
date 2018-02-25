#include "globals.h"

void resetBoard(){
    for(int x = 0; x < 7; ++x){
        for(int y = 0; y < 6; ++y){
            brd[x][y] = 0;
        }
    }
}
