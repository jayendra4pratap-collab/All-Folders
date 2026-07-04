#include <iostream>
#include <list>
using namespace std;
class Node
{
public:
    Node *next;
    int data;

    Node(int val) : data(val), next(nullptr) {}
};
int compareList(Node *list1, Node *list2)
{
    Node *temp1 = list1;
    Node *temp2 = list2;
    int len1 = 0, len2 = 0;
    while (temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }
    if (len1 == len2)
    {
        temp1 = list1;
        temp2 = list2;
        while (temp1 != NULL)
        {
            if (temp1->data == temp2->data)
            {
                return temp1->data;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return -1;
}
int main()
{
    Node *common = new Node(8);
    common->next = new Node(9);
    common->next->next = new Node(11);

    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = common;

    Node *head2 = new Node(6);
    head2->next = new Node(7);
    head2->next->next = common;

    int ans = compareList(head1, head2);
    if (ans == -1)
        cout << "No Intersection";
    else
        cout << ans;
    return 0;
}