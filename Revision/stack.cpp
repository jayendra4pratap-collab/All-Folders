#include<iostream>
#include<vector>
using namespace std;
class Stack{
    int size;
    int *stack;
    int top;
    public :
    Stack()
    {
        top=-1;
        size = 5;
        stack = new int [size];
    } 
    void push(int val)
    {
        if(top==size-1)
        {
            cout<<"Stack is full."<<endl;
        }else{
            top++;
            stack[top]=val;
        }
    }
    void pop(){
        if(top==-1)
        cout<<"Stack UnderFlow..";
        else
        top=top-1;
    }
    void front()
    {
        if(top==-1)
        cout<<"Stack Empty.";
        else
        cout<<stack[top]<<endl;;
    }
    void display()
    {
        for(int i=top;i>=0;i--)
        {
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Stack st;
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.display();
    st.front();
    st.pop();
    st.display();
    return 0;
}