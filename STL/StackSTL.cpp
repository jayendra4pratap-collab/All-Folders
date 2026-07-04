#include <iostream>
#include <stack>
using namespace std;
void display(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << "\t";
        s.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << "Stack is :\t";
    display(st);
    cout << "\nThe top element of the stack:\n"
         << st.top();
    cout << "\nStack after removing the top element from the stack :\n ";
    st.pop();
    display(st);
    cout<<"Size of the stack is "<<st.size();
    return 0;
}