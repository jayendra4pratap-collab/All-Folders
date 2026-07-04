#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr({1,2,1,3,2,3,5,6});
    int len = arr.size();
    vector<bool> check(len+1,false);
    int curr=0;
    reverse(arr.begin(),arr.end());
    for(int i=0;i<len;i++)
    {
        if(check[arr[i]]==false)
        {
            curr+=1;
            check[arr[i]]=true;
        }else{
            curr-=1;
        }
        cout<<curr<<endl;
    }
    return 0;
}