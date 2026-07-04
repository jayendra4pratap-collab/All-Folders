#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> arr1, arr2;
    int x;

    cout << "Enter number in array 1 : ";
    cin >> x;

    while (x >= 0)
    {
        arr1.push_back(x);

        cout << "Enter number: ";
        cin >> x;
    }

    cout << "Enter number in array 2 : ";
    cin >> x;

    while (x >= 0)
    {
        arr2.push_back(x);

        cout << "Enter number: ";
        cin >> x;
    }

    int len1 = arr1.size();
    int len2 = arr2.size();
    for (int i = 0; i < len2; i++)
    {
        bool check = true;
        for (int j = 0; j < len1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                check = false;
                break;
            }
        }
        if (check)
        arr1.push_back(arr2[i]);
    }
    sort(arr1.begin(),arr1.end());
    for(int i=0;i<arr1.size();i++)
    {
        cout<<arr1[i]<<" ";
    }
    return 0;
}