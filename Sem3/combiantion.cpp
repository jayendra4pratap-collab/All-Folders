#include <iostream>
using namespace std;
void solve(vector<int> a, vector<int> &curr, int idx, int k)
{
    if (idx == a.size())
        return;
    if (k == curr.size())
    {
        cout << "{ ";
        for (auto x : curr)
        {
            cout << x << " ";
        }
        cout << "}\n";
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        curr.push_back(a[i]);
        solve(a, curr, idx + 1, k);
        curr.pop_back();
    }
}
int main()
{
    vector<int> a = {1, 2, 3};
    vector<int> cur;
    solve(a, cur, 0, 2);
    return 0;
}