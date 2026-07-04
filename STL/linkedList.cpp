#include <iostream>
#include <vector>
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
class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
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
            Node *temp = head;
            Node *prevNode;
            while (temp->next != NULL)
            {
                prevNode = temp;
                temp = temp->next;
            }
            tail = prevNode;
            tail->next = NULL;  // Important
            delete temp;
        }
    }

    void insertAt(int val,int pos)
    {
        if(pos<0)
        return ;
        if(pos==0)
        push_front(val);
        else
        {
            Node *temp = head;
            Node *newNode = new Node(val);
            for(int i=0;i<pos-1;i++)
            {
                temp=temp->next;
            }
            newNode->next= temp->next;
            temp->next=newNode;

        }

    }

    void search(int val)
    {
        Node *temp=head;
        int i=0;
       
        while(temp!=NULL)
        {
            if(temp->data==val)
            {
                cout<<val<<" found at index "<<i;
                return;
            }
            i++;
            temp=temp->next;
        }
        cout<<"Not Found";
        return;

    }
};
int main()
{
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(5);
    ll.print();
    ll.pop_front();
    ll.print();
    ll.pop_back();
    ll.print();
    ll.insertAt(6,1);

    ll.print();
    ll.insertAt(3,3);
    
    ll.print();
    ll.search(6);
    return 0;
}