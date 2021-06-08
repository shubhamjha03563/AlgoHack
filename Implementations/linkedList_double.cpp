#include <iostream>

class Node
{
public:
    int data;
    Node *next, *prev;
};

void insert_node(int n, int pos, Node *&head)
{
    Node* new_node = new Node();
    new_node->data = n;
    new_node->next = NULL;
    new_node->prev = NULL;
    
    if(head == NULL)
    {
        head = new_node;
        return;
    }

    if(pos == 1)
    {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
        return;
    }

    Node *temp = head;
    for(int i=0; i<pos-2; i++) 
    {
        temp = temp->next;
    }

    /*
    new_node->prev = temp->prev;
    new_node->next = temp;
    temp->prev = new_node;
    */

    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next = new_node;
}

void itr_print_list(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        std::cout << temp->data << "\t";
        temp = temp->next;
    }
}

int main()
{
    Node *head;
    head = NULL;

    insert_node(2, 1, head); //2
    insert_node(3, 2, head); //2, 3
    insert_node(4, 1, head); //4, 2, 3
    insert_node(5, 2, head); //4, 5, 2, 3
    itr_print_list(head);
    printf("\n");

    return 0;
}