#include<iostream>
#include<queue>
using namespace std;
void display(queue<int> q)      // priority_queue
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";  //q.top()
        q.pop();
    }
    cout<<endl;
}
int main()
{
    queue<int> q;    // priority_queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    display(q);
    q.pop();
    display(q);
    return 0;
}