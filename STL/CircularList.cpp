#include <iostream>
#include <list>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class CircularList
{
    Node *tail;
    Node *head;

public:
    CircularList()
    {
        head = tail = NULL;
    }

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print()
    {
        if (head == NULL)
            return;
        cout << head->data << "->";
        Node *temp = head->next;
        while (temp != head)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << head->data << " ";
        cout << endl;
    }

    void popFront()
    {
        if (head == NULL)
        {
            cout << "List is Empty.";
            return;
        }else if(head==tail)
        {
            delete head;
            head=tail=NULL;
        }
        else
        {
            Node *temp = head;
            head = temp->next;
            tail->next = head;
            temp->next=NULL;    //Dont Miss it...
            delete temp;
        }
    }
    void popBack()
    {
        if (head == NULL)
        {
            cout << "List is Empty.";
            return;
        }else if(head==tail)
        {
            delete head;
            head=tail=NULL;
        }
        else
        {
            Node *prev = head;
            Node *temp=tail;
            while (prev->next!= tail)
            {
               prev=prev->next;
            }
            tail = prev;
            tail->next=head;
            temp->next = NULL;
            delete temp;
        }
    }
};
int main()
{
    CircularList l;
    l.insertAtHead(1);
    l.insertAtHead(2);
    l.insertAtHead(3);
    l.insertAtHead(4);
    l.print();
    l.insertAtTail(9);
    l.insertAtTail(8);
    l.insertAtTail(7);
    l.print();
    l.popFront();
    l.print();
    l.popBack();
    l.print();
    return 0;
}