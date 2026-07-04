#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int jump(vector<int> arr, int ind, int n)
{
    if (ind == 0)
        return 0;
    int left = 0, right = 0;
    left = jump(arr, ind - 1, n) + abs(arr[ind] - arr[ind - 1]);
    if (ind > 1)
        right = jump(arr, ind - 2, n) + abs(arr[ind] - arr[ind - 2]);

    return min(left, right);
}
int main()
{
    vector<int> arr = {30, 10, 60, 10, 60, 50};
    int prev = 0, prev2 = 0;
    int left = 0, right = 0;
    for (int ind = 0; ind < arr.size(); ind++)
    {
        left = prev + abs(arr[ind] - arr[ind - 1]);
        if (ind > 1)
            right = prev2 + abs(arr[ind] - arr[ind - 2]);
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    cout << prev << endl;
    int MinEnergy = jump(arr, 5, 6);
    cout << MinEnergy;
    return 0;
}