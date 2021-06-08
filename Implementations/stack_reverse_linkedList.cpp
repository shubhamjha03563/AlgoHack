#include <iostream>
#include <stack>
#include <string>

class Node
{
public:
    int data;
    Node *next;
};

void insert_node(int n, int pos, Node *&head)
{
    Node *new_node = new Node();
    new_node->data = n;
    new_node->next = NULL;

    if (pos == 1)
    {
        new_node->next = head;
        head = new_node;
        return;
    }

    Node *temp = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return;
}

void itr_print_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << "\t";
        temp = temp->next;
    }
}

void stack_reverse_list(Node *&head)
{
    std::stack<Node *> rev_list;
    Node *temp = head;
    while (temp != NULL)
    {
        rev_list.push(temp);
        temp = temp->next;
    }

    temp = rev_list.top();
    head = temp;
    rev_list.pop();
    while (!rev_list.empty())
    {
        temp->next = rev_list.top();
        rev_list.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    Node *head = NULL;
    insert_node(2, 1, head); //Insert '2' at position '1'......List -> 2
    insert_node(3, 2, head); //List -> 2, 3
    insert_node(4, 1, head); //List -> 4, 2, 3
    insert_node(5, 2, head); //List -> 4, 5, 2, 3
    itr_print_list(head);
    printf("\n");

    stack_reverse_list(head); //List gets reversed -> 3, 2, 5, 4
    itr_print_list(head);

    return 0;
}