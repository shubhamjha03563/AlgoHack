#include <iostream>

class Stack_Linked_list
{
public:
    int data;
    Stack_Linked_list *next;
    Stack_Linked_list *top;

    Stack_Linked_list()
    {
        top = NULL;
    }

    void push(int x)
    {
        Stack_Linked_list *new_node = new Stack_Linked_list();
        new_node->data = x;
        new_node->next = top;
        top = new_node;
    }

    void pop()
    {
        if (top == NULL)
        {
            std::cout << "No element to pop!" << std::endl;
            return;
        }
        Stack_Linked_list *temp = top;
        top = top->next;
        delete temp;
    }

    int Top()
    {
        return top->data;
    }

    bool is_empty()
    {
        if (top == NULL)
            return true;
        return false;
    }

    void print_stack()
    {
        Stack_Linked_list *temp = top;
        while (temp != NULL)
        {
            std::cout << temp->data << "\t";
            temp = temp->next;
        }
        printf("\n");
    }
};

int main()
{
    Stack_Linked_list *top = NULL;
    Stack_Linked_list s;
    s.push(2);
    s.print_stack(); //2
    s.push(5);
    s.print_stack(); //5, 2
    s.push(10);
    s.print_stack(); //10, 5, 2
    s.pop();
    s.print_stack(); //5, 2
    s.push(12);
    s.print_stack(); //12, 5, 2

    return 0;
}