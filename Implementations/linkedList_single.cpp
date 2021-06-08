#include <iostream>

class Node
{
public:
    int data;
    Node* next;
};

void insert_node(int n, int pos, Node *&head)
{
    Node* new_node = new Node();
    new_node->data = n;
    new_node->next = NULL;

    if(pos == 1)
    {
        new_node->next = head;
        head = new_node;
        return; 
    }

    Node *temp = head;
    for(int i=0; i<pos-2; i++)
    {
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return;
}

void remove_node(int pos, Node *&head)
{
    Node *del_node = head;
    
    if(pos == 1){
        head = del_node->next;
        delete del_node;
        return;
    }

    Node *temp = head;
    for(int i=0; i<pos-2; i++){
        temp = temp->next;
    }
    del_node = temp->next;
    temp->next = del_node->next;
    delete del_node;
    return;
}

void itr_reverse_list(Node *&head)
{
    if(head->next == NULL) return;
    Node *current, *prev, *next;
    prev = NULL;
    current = head; 
    
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return; 
}

void rec_reverse_list(Node *&head, Node *p) //p is the value of head and gets changed whenever needed
{
    if(p->next == NULL){
        head = p;
        return;
    }

    rec_reverse_list(head, p->next); //recursion
    Node* plus_node = p->next;
    plus_node->next = p;
    p->next = NULL;
}

void itr_print_list(Node *head)
{
    Node *temp = head;
    while(temp != NULL){
        std::cout << temp->data << "\t";
        temp = temp->next;
    }
}

void rec_print_list(Node *head)
{
    if(head == NULL) return;
    std::cout << head->data << "\t";
    rec_print_list(head->next); //recursion
}

void rec_reverse_print_list(Node *head)
{
    if(head == NULL) return;
    rec_print_list(head->next); //recursion
    std::cout << head->data << "\t";
}

int last_nth(Node *head, int n)
{
    Node *temp1, *temp2;
    temp1 = temp2 = head;
    
    for(int i=0; i < n; i++){
        if(temp2 == NULL) return -1;
        temp2 = temp2->next;   
    }
    
    while(temp2 != NULL){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1->data;
}

void merge_sort(Node *head)
{

}

int main()
{
    Node *head;
    head = NULL;

//Creating new nodes
    insert_node(7, 1, head); //Insert '2' at position '1'......List -> 2
    insert_node(6, 2, head); //List -> 7, 6
    insert_node(4, 1, head); //List -> 4, 7, 6
    insert_node(5, 2, head); //List -> 4, 5, 7, 6
    merge_sort(head);
    itr_print_list(head); //Iterative print.........4, 5, 2, 3-----------better than recursive print
    
    /*
    printf("\n");

     std::cout << "from last -> " << last_nth(head, 4) << std::endl;

//Deleting nodes
    remove_node(1, head); //Remove data at position '1'.....List -> 5, 2, 3
    remove_node(2, head); //List -> 5, 3
    rec_print_list(head); //Recursive print.............5, 3
    printf("\n");
    rec_reverse_print_list(head); //Recursive reverse print.........3, 5
    printf("\n");

//Reversing the linked list
    itr_reverse_list(head); //Iterative list reverse.......List -> 3, 5
    itr_print_list(head);
    printf("\n");

    rec_reverse_list(head, head); //Recursive list reverse.......List -> 5, 3
    rec_print_list(head);
    printf("\n");

    return 0;
    */
}