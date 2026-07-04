#include <iostream>
#include <queue>
using namespace std;

void moveNthFront(queue<int> &q, int n)
{
    // Invalid position
    if (n <= 0 || n > q.size())
    {
        cout << "Invalid Position" << endl;
        return;
    }

    queue<int> temp;

    int nthElement;

    // Remove first n elements
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            nthElement = q.front();
        }
        else
        {
            temp.push(q.front());
        }

        q.pop();
    }

    // Put nth element at front
    q.push(nthElement);

    // Add remaining elements
    while (!q.empty())
    {
        temp.push(q.front());
        q.pop();
    }

    // Restore into original queue
    q.push(nthElement);

    while (!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
    }

    // Remove duplicate nth element
    q.pop();
}

void display(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;

    q.push(5);
    q.push(11);
    q.push(34);
    q.push(67);
    q.push(43);
    q.push(55);

    cout << "Original Queue:\n";
    display(q);

    moveNthFront(q, 3);

    cout << "Queue after moving 3rd element to front:\n";
    display(q);

    return 0;
}