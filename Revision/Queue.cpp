#include <iostream>
#include <vector>
using namespace std;
class Queue
{
    int rear;
    int front;
    int size;
    int *queue;

public:
    Queue()
    {
        rear = -1;
        front = -1;
        size = 5;
        queue = new int[size];
    }
    void push(int val)
    {
        if (rear == size - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1)
            front = 0;
            rear++;
        queue[rear] = val;
    }
    void frnt()
    {
        if (rear == -1 || front>rear)
            cout << "Queue Underflow" << endl;
        else
            cout << queue[front] << endl;
    }
    void pop()
    {
        if (rear == -1 || front >rear)
            cout << "Queue Underflow" << endl;
        else
            front++;
    }
    void display()
    {
        if(front == -1 || front > rear)

        {

            cout << "Queue Empty" << endl;

            return;

        }
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
    ~Queue()

    {

        delete[] queue;

    }
};
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.display();
    q.frnt();
    q.pop();
    q.display();
    q.push(5);
    q.display();

    return 0;
}