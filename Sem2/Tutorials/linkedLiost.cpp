#include<iostream>
#include<vector>
using namespace std;
class Node
{
     public : 
    int data;
    Node *next;
   
    Node(int val): data(val) , next(NULL){}
};
void insert(Node * &head,int val)
{
    Node *newNode=new Node(val);
    Node *temp=head;
    if(head==NULL)
    {
        head=newNode;
        newNode->next=NULL;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=NULL;
    return;
}
void display(Node *temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data<< " ";
        temp=temp->next;
    }
    cout<<endl;
}
int find(Node *temp,int k)
{
    if(k==1)
    return temp->data;
    do{
        k--;
        if(temp==NULL)
        return -1;
        if(k==0)
        break;
        temp=temp->next;
    }while(k!=0);
    return temp->data;
}
void reverse(Node * &head)
{
    Node *prev=NULL;
    Node *curr=head;
    Node *next=head;
    if(curr==NULL)
    return;
    while(next!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }
    head=prev;
}
void duplicate(Node * &head)
{
    Node *temp=head;
    while(temp->next!=NULL && temp!=NULL)
    {
        if((temp->data)==(temp->next->data))
        {
            temp->next=temp->next->next;
        }
        else{
            temp=temp->next;
        }
    }
}
int main()
{
    Node *head=NULL;
    insert(head,10);
    insert(head,20);
    insert(head,20);
    insert(head,30);
    insert(head,40);
    insert(head,40);
    insert(head,50);
    display(head);
    cout<<find(head,4)<<endl;
    cout<<find(head,9)<<endl;
    reverse(head);
    display(head);
    duplicate(head);
    display(head);
    return 0;
}