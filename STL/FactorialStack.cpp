#include<iostream>
#include<stack>
using namespace std;
int factorial(int n)
{
    stack<int> st;
    while(n>1)
    {
        st.push(n);
        n=n-1;
    }
    int r=1;
    while(!st.empty())
    {
        r=r* st.top();
        st.pop();
    }
    return r;
}
int main()
{
    cout<<factorial(5);
    return 0;
}