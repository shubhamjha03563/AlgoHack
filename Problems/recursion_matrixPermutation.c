/*
Finding no.of paths in a n x m grid from starting position to ending position.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int count = 0;

void paths(int row, int col, int last_row, int last_col){
    if (row > last_row || col > last_col) return;
    if (row == last_row && col == last_col){
        count++;
        return;
    }
    paths(row+1, col, last_row, last_col);
    paths(row, col+1, last_row, last_col);
}

int main()
{
    int total_rows = 4, total_cols = 4;
    
    paths(0, 0, total_rows-1, total_cols-1);
    printf("%d", count);

    return 0;
}   