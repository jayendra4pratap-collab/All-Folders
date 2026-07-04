#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int,int> mp;
    cout<<"Enter number of crystals : ";
    int n;
    cin>>n;
    cout<<"Enter types of crystal : "<<endl;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        mp[num]++;
    }
    int max=0;
    int ans=0;
    for(auto it : mp)
    {
        if(it.second >max)
        {
            ans=it.first;
            max=it.second;
        }
    }
    cout<<ans;


    return 0;
}