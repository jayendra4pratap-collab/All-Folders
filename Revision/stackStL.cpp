#include<iostream>
#include<vector>
using namespace std;
void display(stack<int> st)
{
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    display(st);
    cout<<st.top()<<endl;
    st.pop();
    display(st);
    return 0;
}