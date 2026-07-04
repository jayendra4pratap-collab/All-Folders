#include <iostream>
using namespace std;

class Node
{
public:
    int coeff;
    int power;
    Node *next;
    Node(int c, int p)
    {
        coeff = c;
        power = p;
        next = NULL;
    }
};
void insert(Node *&head, int c, int p)
{
    Node *newNode = new Node(c, p);

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
}
void display(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->coeff << "x^" << temp->power;

        if (temp->next != NULL)
            cout << " + ";

        temp = temp->next;
    }

    cout << endl;
}

Node *addPolynomial(Node *p1, Node *p2)
{
    Node *result = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->power == p2->power)
        {
            insert(result,
                   p1->coeff + p2->coeff,
                   p1->power);

            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->power > p2->power)
        {
            insert(result, p1->coeff, p1->power);
            p1 = p1->next;
        }
        else
        {
            insert(result, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        insert(result, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        insert(result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;

    insert(poly1, 5, 2);
    insert(poly1, 4, 1);
    insert(poly1, 2, 0);

    insert(poly2, 5, 1);
    insert(poly2, 5, 0);

    cout << "Polynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    Node *result = addPolynomial(poly1, poly2);

    cout << "Result: ";
    display(result);

    return 0;
}