// Print numbers from 1 to 10. If odd, add 1; if even subtract 1

#include <stdio.h>

int n = 1;
void odd();
void even();

void odd()
{
    if(n <= 10){
        printf("%d ", n + 1);
        n++;
        even();
    }
}

void even()
{
    if(n <= 10){
        printf("%d ", n - 1);
        n++;
        odd();
    }
}

int main()
{
    odd();
    return 0;
}

//Indirect recursion- 'odd' calls 'even' and then 'even' calls 'odd'.