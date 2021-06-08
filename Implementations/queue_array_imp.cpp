#include <iostream>
#include <string>
#define length 10

class Queue_arr
{
private:
    int rear, front, queue[length];

public:

    Queue_arr()
    {
        front = -1;    
        rear = -1;
    }

    void enqueue(int n)
    {
        if(front == -1 && rear == -1) //empty queue
        {
            queue[0] = n;
            front = rear = 0;
            return;
        } else if((rear+1)%length == front)
        {
            std::cout << "Queue is full!" << std::endl;
            return;
        }
        rear = (rear+1) % length;
        queue[rear] = n;
    }

    void dequeue()
    {
        if(front == -1 && rear == -1) //empty queue
        {
            std::cout << "Queue is empty!" << std::endl;
            return;
        } else if (front == 0 && rear == 0)
        {
            front = rear = -1;
            return;
        }
        front = (front+1) % length;
    }

    int first()
    {
        return queue[front];
    }

    int last()
    {
        return queue[rear];
    }

    void print_queue()
    {
        for(int i=front; i<=rear; i++)
        {
            std::cout << queue[i] << '\t';
        }
        printf("\n");
    }
};

int main()
{
    Queue_arr q;
    q.enqueue(2); //2
    q.enqueue(3); //2, 3
    q.enqueue(4); //2, 3, 4
    q.dequeue(); //3, 4
    q.enqueue(5); //3, 4, 5
    q.dequeue(); //4, 5
    q.enqueue(6); //4, 5, 6

    q.print_queue();
    std::cout << "First element of queue : " << q.first() << std::endl;
    std::cout << "Last element of queue : " << q.last() << std::endl;

    return 0;
}
