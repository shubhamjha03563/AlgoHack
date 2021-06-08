#include <iostream>

int main()
{
    int mat_order[] = { 1, 2, 3, 4, 3}, size = sizeof(mat_order) / sizeof(mat_order[0]); 
    int mat[size][size], s[size][size];

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++) mat[i][j] = 0;
    }

    //Matrix chain multiplication algo
    for(int diff = 1; diff < size-1; diff++){
        for(int i=1; i+diff < size; i++){
            int j = i + diff, min = INT32_MAX;
            for(int k = i; k < j; k++)
            {   
                int q = mat[i][k] + mat[k+1][j] + (mat_order[i-1] * mat_order[k] * mat_order[j]);
                if(q < min)
                {
                    min = q;
                    s[i][j] = k;
                }
            }
            mat[i][j] = min;
        }
    }

    std::cout << "Min computation = " << mat[1][size-1];

    return 0;
}