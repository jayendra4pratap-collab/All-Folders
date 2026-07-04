#include<iostream>
#include<vector>
using namespace std;
int main()
{
    try{
    cout<<"\n Hello.  888.   \n";
    throw 10;
    cout<<"World";
    }
    catch(...)
    {
        cout<<"Exception caught"<<endl;
    }
    return 0;
}