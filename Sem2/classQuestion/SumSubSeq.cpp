#include <iostream>
#include <vector>
using namespace std;
int sum = 4;
bool compute(int ind, vector<int> ls, vector<int> &arr, int n, int s)
{
    if (ind == n)
    {
        if (sum == s)
        {
            for (auto it : ls)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }else{
            return false;
        }
        
    }
    ls.push_back(arr[ind]);
    s += arr[ind];
    if(compute(ind + 1, ls, arr, n, s))return true;
    ls.pop_back();
    s -= arr[ind];
    if(compute(ind + 1, ls, arr, n, s))return true;
    return false;
}
/*void compute(int ind,vector<int> ls,vector<int> &arr,int n,int s)
{
    if(ind==n)
    {
        if(sum==s)
        {
             for( auto it : ls)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        }
        return;
    }
    ls.push_back(arr[ind]);
    s+=arr[ind];
    compute(ind+1,ls,arr,n,s);
    ls.pop_back();
    s-=arr[ind];
    compute(ind+1,ls,arr,n,s);
}*/
int main()
{
    vector<int> arr = {2, 3, 1, 1, 2}, ls;
   compute(0, ls, arr, 5, 0);
    return 0;
}