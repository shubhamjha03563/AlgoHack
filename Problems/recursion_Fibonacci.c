#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int A[100];

int fib(int n)
{
    if (A[n] != -1){
        return A[n]; 
    }
    A[n] = fib(n-1) + fib(n-2);

    return A[n];
}

int main()
{
    int a;
    scanf("%d", &a);

    for(int i=0; i<100; i++){
        A[i] = -1;
    }
    A[0] = 0;
    A[1] = 1;

    int result = fib(a);
    printf("%d", result);

    return 0;
}