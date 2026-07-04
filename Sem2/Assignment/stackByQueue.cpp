#include <iostream>
#include <queue>
using namespace std;
class Stack
{
    queue<int> q;

public:
    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "Stack is Empty\n";
            return;
        }
        q.pop();
    }

    int top()
    {
        if (q.empty())
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return q.front();
    }
    void display()
    {
        queue<int> temp=q;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};
int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.display();
    st.pop();
    st.display();
    return 0;
}