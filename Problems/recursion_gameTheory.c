#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int max(int a, int b){
    if (a>b) return a;
    return b;
}

int min(int a, int b){
    if (a<b) return a;
    return b;
}

int game(int a[], int l , int r){
    if(l+1 == r) return max(a[l], a[r]);
    return max(a[l] + min(game(a, l+2, r), game(a, l+1, r-1)), a[r] + min(game(a, l+1, r-1), game(a, l, r-2)));
}

int main()
{
    int a[] = {1, 5, 700, 2}; //701
    int b[] = {1, 5, 7, 3, 2, 4}; //12

    printf("\n%d", game(a, 0, 3));
    printf("\n%d", game(b, 0, 5));

    return 0;
}