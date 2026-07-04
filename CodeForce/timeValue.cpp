#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter time : ";
    cin>>n;
    int num=3;
    int temp=num;
    for(int i=0;i<n;i++)
    {
        
        if(temp==1)
        {
            num=num*2;
            temp=num;
        }else{
        temp--;
        }
    }
    cout<<temp+1;
    return 0;
}