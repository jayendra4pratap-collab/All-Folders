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

int ValueOfCrystal(Node *head)
{
    int sum = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter number of Mana Crystall : ";
    cin >> n;
    Node *head =NULL,*tail=NULL;
    Node *list = head;

    cout << "Enter Value of each crystall : " << endl;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        Node *newNode =new Node(val);
        if(head==NULL)
        {
            head=list=newNode;
            list->next=tail;
           
        }else{
            list->next=newNode;
            newNode->next=tail;
            list=list->next;

        }
    }
    cout << "Total value is " << ValueOfCrystal(head);

    return 0;
}