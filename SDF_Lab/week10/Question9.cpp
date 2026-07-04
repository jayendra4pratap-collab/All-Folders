#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int,string> student;
    student[200]="Alice";
    student[201]="John";
    cout<<student.size()<<endl;

    for(map<int, string>::iterator it=student.begin() ; it!=student.end();it++)
    {
        cout<<"Roll Number : "<<it->first;
        cout<<"\nName : "<<it->second<<endl;
    }

    map<int,string> :: iterator it=student.find(201);
    if(it!=student.end())
    cout<<" Key 201 exists"<<endl;
    else
    cout<<"not exists.";
    return 0;
}