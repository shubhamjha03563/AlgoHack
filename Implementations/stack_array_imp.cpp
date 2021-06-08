#include <iostream>
#define MAX_SIZE 101

class Stack_array
{
private:
    int A[MAX_SIZE], top;

public:
    Stack_array()
    {
        top = -1;
    }
    
    void push(int x)
    {
        if(top == MAX_SIZE - 1) //overflow case
        {
            std::cout << "Error, stack overflow!" << std::endl;
            return;
        }
        A[++top] = x;
    }

    void pop()
    {
        if(top == -1)
        {
            std::cout << "No element to pop!" << std::endl;
            return;
        }
        top--;
    }

    int Top()
    {
        return top;
    }

    bool is_empty()
    {
        if(top == -1) return true;
        return false;
    }

    void print_stack()
    {
        for(int i=0; i<= top; i++)
        {
            std::cout << A[i] << "\t";
        }
        printf("\n");
    }
};

int main()
{
    Stack_array s;
    s.push(2); s.print_stack(); //2
    s.push(5); s.print_stack(); //2, 5
    s.push(10); s.print_stack(); //2, 5, 10
    s.pop(); s.print_stack(); //2, 5
    s.push(12); s.print_stack(); //2, 5, 12

    return 0;
}