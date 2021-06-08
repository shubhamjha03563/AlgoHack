/*
Split the given array into two parts such that sum of both parts is half of the total sum.
We'll print just the first part.
*/

#include <stdio.h>
#include <stdbool.h>

bool split_array(int a[], int sum, int ans[], int i){
    if(sum < 0 || i == 6) return false;
    if(sum == 0) return true;

    ans[i] = a[i];
    if(split_array(a, sum-a[i], ans, i+1)) return true;

    //These two are the only backtracking statements.
    ans[i] = -10;
    split_array(a, sum, ans, i+1);
}

int main()
{
    int a[] = {2, 1, 2, 3, 4 ,8}, ans[6], sum = 0;
    for(int i = 0; i < 6; i++){
        sum += a[i];
        ans[i] = -10;
    }

    if(sum%2 != 0) printf("Array split not possible!");

    split_array(a, sum/2, ans, 0);
    for(int i = 0; i < 6; i++){
        if (ans[i] == -10) continue;
        printf("%d\t", ans[i]);
    }

    return 0;
}
