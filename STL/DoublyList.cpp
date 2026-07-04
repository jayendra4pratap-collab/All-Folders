#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};
class DoublyList
{
    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            newNode->prev = NULL;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "List is empty.";
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;

            if (head != NULL)
            {
                head->prev = NULL;
            }
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "List is empty.";
            return;
        }
        else
        {
            Node *temp = tail;
            tail=tail->prev;
            if(tail!=NULL)
                tail->next=NULL;
            temp->prev=NULL;
            delete temp;
            /*Node *temp = head;
            Node *prevNode;
            while (temp->next != NULL)
            {
                prevNode = temp;
                temp = temp->next;
            }
            tail = prevNode;
            tail->next = NULL; // Important
            delete temp;*/
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertAt(int val, int pos)
    {
        Node *newNode = new Node(val);
        if (pos < 0)
            return;
        if (pos == 0)
            push_front(val);
        else
        {
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next != NULL)
                temp->next->prev = newNode;
            temp->next = newNode;
            if (newNode->next == NULL)
                tail = newNode;
        }
    }
}

;
int main()
{
    DoublyList dl;
    dl.push_front(2);
    dl.push_front(4);
    dl.push_front(6);
    dl.print();
    dl.push_back(4);
    dl.print();
    dl.pop_back();
    dl.print();
    dl.pop_front();
    dl.print();
    dl.insertAt(5, 1);
    dl.print();
    return 0;
}