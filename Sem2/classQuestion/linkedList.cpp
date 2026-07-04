#include<iostream>
#include<vector>
using namespace std;
class Node
{
     public : 
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
class List
{
    Node *head;
    Node *tail;

    public : 
    List()
    {
        head=tail=NULL;
    }

    void push_front(int val)
    {     
        Node *newNode = new Node(val);
        if(head==NULL)
        {
            head=newNode;
            tail=head->next;
            return;
        }
        newNode->next=head;
        head=newNode;
    }

    void display()
    {
        Node *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
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
    l.display();
    l.push_front(5);
    l.push_front(6);
    l.display();
    return 0;
}