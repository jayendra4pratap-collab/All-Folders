#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
class List
{
    Node *head;

public:
    List()
    {
        head = NULL;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        head->prev = NULL;
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        Node *temp = head;

        head = head->next;

        if (head != NULL)

        {

            head->prev = NULL;
        }

        delete temp;
    }
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        if (head->next == NULL)

        {

            delete head;

            head = NULL;

            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void insert(int k, int val)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 1; i < k&& temp != NULL; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
    }
    void reverse()
    {
        Node *temp=head;
        if(head==NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }
};
int main()
{
    List l;
    l.push_front(2);
    l.push_front(3);
    l.push_front(4);
    l.push_front(5);
    l.push_front(6);
    l.display();
    l.push_back(1);
    l.display();
    l.pop_front();
    l.pop_back();
    l.display();
    l.insert(2, 9);
    l.display();
    l.reverse();
    return 0;
}