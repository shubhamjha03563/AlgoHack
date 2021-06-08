#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void exchange();

void permutation(char* a, int l, int r){
    if(l == r){
        printf("%s\t", a);
        return;
    }

    for(int i = l; i <= r; i++){
        exchange(a, l, i);
        permutation(a, l+1, r);
        exchange(a, l, i);
    } 

}

void exchange(char* b, int i, int j){
    int temp  = b[i];
    b[i] = b[j]; 
    b[j] = temp;
}

int main()
{   
    char a[10] = "abc";
    permutation(a, 0, 2);

    return 0;
}