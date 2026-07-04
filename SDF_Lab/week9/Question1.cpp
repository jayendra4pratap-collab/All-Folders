#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n1,n2;
    cout<<"Enter Number : ";
    cin>>n1;
    cout<<"Enter Number : ";
    cin>>n2;
    try
    {
        if(n2==0)
        throw "cannot be divide by 0 ";
        else
        cout<<n1/n2;
    }
    catch(const char *s)
    {
        cout<<s;
    }
    return 0;
}