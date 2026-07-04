#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
    Node *prev;
    Node(char val) : data(val), next(nullptr), prev(nullptr) {}
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
    void insert(char val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
    bool pallin()
    {
        Node *left = head;
        Node *right = tail;
        while (left != right && right->next != left)
        {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};
int main()
{
    DoublyList db;
    db.insert('a');
    db.insert('b');
    db.insert('c');
    db.insert('b');
    db.insert('a');

    db.display();
    if (db.pallin())
        cout << "List is Pallindrome";
    else
        cout << "List is not Pallindrome";
    return 0;
}