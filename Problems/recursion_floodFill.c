#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void flood_fill(int a[][7], const int rows, const int cols, int st_r, int st_c, int prev_n, int new_n)
{
    if(st_r<0 || st_r>= rows || st_c<0 || st_c>=cols) return;
    if(a[st_r][st_c] != prev_n) return;
    a[st_r][st_c] = new_n;
    flood_fill(a, rows, cols, st_r-1, st_c, prev_n, new_n);
    flood_fill(a, rows, cols, st_r+1, st_c, prev_n, new_n);
    flood_fill(a, rows, cols, st_r, st_c-1, prev_n, new_n);
    flood_fill(a, rows, cols, st_r, st_c+1, prev_n, new_n);
}

void print_arr(int a[][7], const int rows)
{
    for(int i=0; i<rows; i++){
        for(int j=0; j<7; j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[][7] = {
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 0, 1},
        {1, 2, 2, 1, 0, 1},
        {1, 1, 2, 2, 0, 1},
        {1, 1, 2, 1, 2, 1},
        {1, 1, 2, 1, 1, 1},
        {1, 1, 1, 2, 1, 1},
        {1, 2, 1, 1, 0, 0}
        };
    
    flood_fill(a, 9, 7, 3, 3, 1, 4); // from a[3][3], all the consecutive 1's in all the four directions are changed to '4'.
    print_arr(a, 7);

    return 0;
}