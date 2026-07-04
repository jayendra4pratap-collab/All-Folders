#include<iostream>
#include<vector>
using namespace std;
int top=-1;
void push(int stack[] , int num,int size)
{
    if(top==size-1)
    {
        cout<<"Stack is Full"<<endl;
        return;
    }else{
        top=top+1;
        stack[top]=num;
    }
}
void pop(int stack [])
{
    if(top==0)
    {
        cout<<"Stack is Empty"<<endl;
        return;
    }else{
        top=top-1;
    }
}
void print(int stack[]){
    for(int i=0;i<=top;i++)
    {
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int stack[3];
    push(stack,5,3);
    push(stack,6,3);
    push(stack,7,3);
    //push(stack,8,3);
    print(stack);
    pop(stack);
    print(stack);

    return 0;
}