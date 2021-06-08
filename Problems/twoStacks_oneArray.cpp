#include <iostream>

class TwoStacks
{
    int top1, top2, *arr;

public:
    TwoStacks(int total_size)
    {
        arr = new int[total_size];
        top1 = -1;
        top2 = total_size;
    }   

    void push1(int data)
    {   
        if(top1 < top2-1)
        {
            arr[++top1] = data;
            return;
        }
        std::cout << "Stack 1 is full" << std::endl;
    }   

    void push2(int data)
    {   
        if(top1 < top2-1)
        {
            arr[--top2] = data;
            return;
        }
        std::cout << "Stack 2 is full" << std::endl;
    }   
    
    int pop1()
    {
        return arr[top1--];
    }

    int pop2()
    {
        return arr[top2++];
    }
};

int main()
{
    TwoStacks ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7);  
    
    std::cout << "Popped element from stack1 is " << ts.pop1() << std::endl; 

    ts.push2(40); 
    std::cout << "Popped element from stack2 is " << ts.pop2() << std::endl;

    ts.push2(23); 
    ts.push2(34); 
    ts.push1(27); 

    return 0;
}