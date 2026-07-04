#include<iostream>
#include<vector>
using namespace std;
class Node {
    public : 
    int data;
    Node *next;

    Node(int val): data(val) , next(nullptr){}
};
void insert(Node *&head,int val)
{
    Node *newNode = new Node(val);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;
}
void display(Node *head)
{
    if(head==NULL)
    {
        cout<<"List is empty ."<<endl;
        return;
    }
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void reverse(Node *&head)
{
    Node *curr=head;
    Node *prev=NULL;
    while(curr!=NULL)
    {
        Node *next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}
int main()
{
    Node *head=NULL;
    insert(head,20); 
    insert(head,30);  
    insert(head,40);  
    insert(head,50);  
    insert(head,60);  
    display(head); 
    reverse(head);
    display(head); 
    return 0;
}