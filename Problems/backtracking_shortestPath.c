/*
Finding the shortest path in the maze. Result will be no.of steps.
x,y is the destination point and i,j is the starting point.
The 0's are the obstacles and 1's are the only path on which we can move.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int max(int a, int b){
    if (a>b) return a;
    return b;
}

int min(int a, int b){
    if (a<b) return a;
    return b;
}

bool is_valid(int** a, int i, int j, bool vis[][9]){
    return i>=0 && j>=0 && i<9 && j<9 && *(*(a+i)+j)==1 && !vis[i][j];
}

int recursion(int** a, int i, int j, int x, int y, bool vis[][9]){
    if (!is_valid(a, i, j, vis)) return 1000000;
    if (i == x && j == y) return 0;

    vis[i][j] = true;
    int left = recursion(a, i, j-1, x, y, vis) + 1;
    int right = recursion(a, i, j+1, x, y, vis) + 1; 
    int top = recursion(a, i-1, j, x, y, vis) + 1;
    int bottom = recursion(a, i+1, j, x, y, vis) + 1;
    
    //These two are the only backtracking statements. 
    vis[i][j] = false;
    return min(min(left, right), (top, bottom));
}

int main()
{   
    int a[][9] = {
        {1, 1, 1, 1, 0, 0, 1, 1, 1},
        {1, 0, 1, 1, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 0, 1, 0, 0, 1, 1, 0},
        {0, 0, 1, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 0, 1, 0, 0, 0},
        {1, 1, 1, 1, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 1},
    };

    int** arr = (int**) calloc(9, sizeof(int*));
    for(int i = 0; i < 9; i++){
        *(arr+i) = (int*) calloc(9, sizeof(int));
    }

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            arr[i][j] = a[i][j];
        }
    }

    bool vis[9][9];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            vis[i][j] = false;
        }
    }

    printf("%d", recursion(arr, 0, 0, 7, 0, vis));

    return 0;
}