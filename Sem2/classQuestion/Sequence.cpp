#include<iostream>
#include<vector>
using namespace std;

void recursion(int ind , vector<int> &ls, vector<int> &arr,int n)
{
    if(ind==n)
    {
        if(ls.empty()){}
       // cout<<"{}"<<endl;
        else{
        for( auto it : ls)
        {
            cout<<it<<" ";
        }
    }
        cout<<endl;
        return;
    }
     recursion(ind+1,ls,arr,n);    //not take
    ls.push_back(arr[ind]);
    recursion(ind+1,ls,arr,n);   //take 
    ls.pop_back();
    
}
int main()
{
    vector<int> ls;
    vector<int> arr ={7,8};
    recursion(0,ls,arr,2);
    return 0;
}