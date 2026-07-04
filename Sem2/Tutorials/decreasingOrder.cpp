#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr({2,5,3,9,4,6});
    int len =arr.size();
    for(int i=0;i<len-1;i++)
    {
        for(int j=len-1;j>0+i;j--)
        {
            if(arr[j]>arr[j-1])
            {
                int temp = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}