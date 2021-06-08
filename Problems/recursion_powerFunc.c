#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//takes 'n' steps for input 'n'.
int power_slow(int x, int n)
{
     if(n==0){
        if(x == 0) printf("Not defined!");
        else return 1;
    }
    return x * power_slow(x, n-1);
}

//faster than previous b/c it takes 'n/2' steps for input 'n'. This is because we have divided 'n' into odd and even.
int power(int x, int n)
{
    if(n==0){
        if(x == 0) printf("Not defined!");
        else return 1;
    } else if(n%2 == 0){
        int y = power(x, n/2);
        return y*y;
    }
    return x*power(x, n-1);
}

int main()
{
    printf("\n%d", power_slow(2, 10)); //in 0.827 secs
    printf("\n%d", power(2, 10)); //in 0.655 secs

    return 0;
}