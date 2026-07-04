#include<iostream>
#include<queue>
using namespace std;
int main()
{
    cout<<"Enter number of task : ";
    int n;
    cin>>n;
    queue<int> q;
    char ch = 'A';
    queue<char> level;

    for(int i=0;i<n;i++)
    {
        int task;
        cout<<"Enter the unit of time of task "<<ch<<" : ";
        cin>>task;
        q.push(task);
        level.push(ch);
        ch++;
    }
    cout<<"Enter the time of slice : ";
    int t;
    cin>>t;
    while(!q.empty())
    {
        
        int task=q.front();
        if(task<=t)
        {
            cout<<"Task "<<level.front()<<" is executed and completed."<<endl;
            task=0;
            q.pop();
            level.pop();
        }else{
            task-=t;
            cout<<"Task "<<level.front()<<" is executed for "<<t<<" units and, "<<task<<" units remaining."<<endl;
            q.pop();
            q.push(task);
            level.push(level.front());
            level.pop();
            

        }

    }
    return 0;
}