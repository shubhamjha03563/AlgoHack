//Incomplete

#include <iostream>

int** allocate(int row, int col)
{
    int** c = new int*[row];
    for(int i=0; i<2; i++) c[i] = new int[col];
    return c;
}

//In Strassen's multiplication, it's assumed that all the matrices are square matrices
int** strassens_formula(int **a, int **b)
{
    int m1, m2, m3, m4, m5, m6, m7, **c = allocate(2, 2);
    m1= (a[0][0] + a[1][1])*(b[0][0]+b[1][1]);
    m2= (a[1][0]+a[1][1])*b[0][0];
    m3= a[0][0]*(b[0][1]-b[1][1]);
    m4= a[1][1]*(b[1][0]-b[0][0]);
    m5= (a[0][0]+a[0][1])*b[1][1];
    m6= (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
    m7= (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
    c[0][0]=m1+m4-m5+m7;
    c[0][1]=m3+m5;
    c[1][0]=m2+m4;
    c[1][1]=m1-m2+m3+m6;
    return c;
}

void print_matrix(int **a, int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++) std::cout << a[i][j] << " ";
        printf("\n");  
    }
}

int main()
{   
    int** matA = allocate(4, 4);  
    matA[0][0] = 1; 
    matA[0][1] = 2; 
    matA[1][0] = 3; 
    matA[1][1] = 4;  
  
    int** matB = allocate(4, 4); 
    matB[0][0] = 7; 
    matB[0][1] = 8; 
    matB[1][0] = 9; 
    matB[1][1] = 10; 
    
    int** matC = allocate(2, 2);
    matC = strassens_formula(matA, matB);
    print_matrix(matC, 2);
    return 0;
}
