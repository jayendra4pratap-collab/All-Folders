#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        a.erase(unique(a.begin(), a.end()), a.end());

        int ans = 1, curr = 1;

        for (int i = 1; i < (int)a.size(); i++) {
            if (a[i] == a[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            ans = max(ans, curr);
        }

        cout << ans << endl;
    }

    return 0;
}/*
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--> 0)
    {
        int n;
        cin >> n;
        vector < int > arr(n);
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] < min)
                min = arr[i];
        }
        int num = 0;
        int flag = 0;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] - min;
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != arr[i - 1])
            {
                j--;
            }
            if (arr[i] != j)
            {

                num = arr[i];
                flag = 1;
                break;
            }
            j++;
        }

        if (flag == 0)
            cout << arr[n - 1] + 1 << endl;
        else
            cout << num << endl;
    }

}
*/