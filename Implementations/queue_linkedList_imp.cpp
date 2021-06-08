#include <iostream>
#include <string>

class Queue_linked_list
{
private:
    Queue_linked_list *next, *front, *rear;
    int data;
public:
    Queue_linked_list()
    {
        rear = front = NULL;
    }

    void enqueue(int n)
    {
        Queue_linked_list *new_node = new Queue_linked_list();
        new_node->data = n;
        new_node->next = NULL;

        if (front == NULL && rear == NULL) 
        {
            front = rear = new_node;
            return;
        }
        rear->next = new_node;
        rear = new_node;
    }

    void dequeue()
    {
        if(front == NULL) //empty queue
        {
            return;
        }
        if(front == rear) //only 1 element is present
        {
            front = rear = NULL;
            return;
        }
        Queue_linked_list *temp = front;
        front = front->next;
        delete temp;
    }

    int first()
    {
        if(front == NULL) return 9999999;
        return front->data;
    }

    int last()
    {
        if(front == NULL) return 9999999;
        return rear->data;
    }

    void print_queue()
    {
        Queue_linked_list *temp = front;
        while(temp != NULL)
        {
            std::cout << temp->data << '\t';
            temp = temp->next;
        }
        printf("\n");
    }
};

int main()
{
    Queue_linked_list q;
    q.enqueue(5); //5
    q.enqueue(8); //5, 8
    q.enqueue(7); //5, 8, 7
    q.dequeue(); //8, 7
    q.enqueue(9); //8, 7, 9
    q.dequeue(); //7, 9
    q.enqueue(1); //7, 9, 1

    q.print_queue();
    std::cout << "First element of queue : " << q.first() << std::endl;
    std::cout << "Last element of queue : " << q.last() << std::endl;

    return 0;
}