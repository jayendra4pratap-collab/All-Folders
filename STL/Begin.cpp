#include<iostream>
using namespace std;
int main()
{
    cout<<"This is my first program"<<endl;
    cout<<"Enter your age : ";
    int age;
    cin>>age;
    if(age>=18)
    cout<<"You are eligible ";
    else
    cout<<"You are not eligible";
    return 0;
}