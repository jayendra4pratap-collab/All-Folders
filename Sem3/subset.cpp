#include<iostream>
using namespace std;
void solve (vector<int> a, vector <int> curr,int idx)
{
    if(idx==a.size())
    {
        cout<<"{ ";
        for(auto x : curr)
        {
            cout<<x<<" ";
        }
        cout<<"}\n";
        return;
    }
    solve(a,curr,idx+1);
    curr.push_back(a[idx]);
    solve(a,curr,idx+1);
}
int main() {
    vector<int> a={1, 2, 3,4,5};
    vector<int>cur;
    solve(a,cur,0);
    return 0;
}