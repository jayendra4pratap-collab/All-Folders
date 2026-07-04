#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sum(vector<int> arr, int ind)
{
   if(ind==0)
    return arr[0];
   if(ind<0)
    return 0;

    int pick = arr[ind] + sum(arr,ind-2);
    int notpick= sum(arr,ind-1);

    return max(pick,notpick);
   
}
int main()
{
    int k = 4;
    vector<int> arr = {30, 10, 60, 10, 60, 50};
    int maxSum =sum(arr,5);
    cout<<maxSum;
    return 0;
}