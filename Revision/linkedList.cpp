#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void push_front(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
void push_back(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = newNode;
}
void pop_front(Node *&head)
{
    if (head == NULL)
    {
        cout << "Empty" << endl;
        return;
    }
    head = head->next;
}
void pop_back(Node *&head)
{
    if (head == NULL)
    {
        cout << "Empty" << endl;
        return;
    }
    Node *temp = head;
    Node *prev;
    while (temp->next != NULL)
    {
        prev=temp;
        temp = temp->next;
    }
    prev->next = NULL;
}
int main()
{
    Node *curr = new Node(5);
    curr->next = new Node(6);
    curr->next->next = new Node(7);
    display(curr);
    push_front(curr, 4);
    push_back(curr, 8);
    display(curr);
    pop_front(curr);
    pop_back(curr);
    display(curr);
    return 0;
}