#include <iostream>
using namespace std;
void solve(vector<int> a, vector<int> &curr, vector<bool> &used, int idx)
{
    if (curr.size() == a.size())
    {
        cout << "{ ";
        for (auto x : curr)
        {
            cout << x << " ";
        }
        cout << "}\n";
        return;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if(used[i])
        continue;
        curr.push_back(a[i]);
        used[i]=true;
        solve(a, curr, used, idx + 1);
        curr.pop_back();
        used[i]=false;
    }
}
int main()
{
    vector<int> a = {1, 2, 3};
    vector<int> cur;
    vector<bool> used(a.size(), false);
    solve(a, cur, used, 0);
    return 0;
}