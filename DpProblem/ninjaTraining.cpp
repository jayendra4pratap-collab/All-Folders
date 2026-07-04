#include<iostream>
#include<vector>
using namespace std;
int ninja (vector<vector<int >> &dp, vector<vector<int >> &arr ,int day,int last)
{
    if(day==0)
    {
        int maxi=0;
        for (int i = 0; i < 3; i++)
        {
            if(i!=last)
            maxi=max(maxi,arr[0][i]);
        }
        return maxi;
    }
    if(dp[day][last]!=-1)
    return dp[day][last];
    int maxi=0;
    for(int i=0;i<3;i++)
    {
        if(i!=last){
        int point = arr[day][i] + ninja(dp,arr,day-1,i);
        maxi = max(point , maxi);
        }
    }
    return dp[day][last]=maxi;
}
int main()
{
    vector<vector<int >> arr = { {20,11,6} , {34,24,56} , { 50,4,25}};
    vector<vector<int >> dp(arr.size(),vector<int> (4,-1));
    int count = ninja(dp,arr,2,3);
    cout<<count;
    return 0;
}


/*int ninja (vector<vector<int >> &arr ,int day,int last)
{
    if(day==0)
    {
        int maxi=0;
        for (int i = 0; i < 3; i++)
        {
            if(i!=last)
            maxi=max(maxi,arr[0][i]);
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++)
    {
        if(i!=last){
        int point = arr[day][i] + ninja(arr,day-1,i);
        maxi = max(point , maxi);
        }
    }
    return maxi;
}*/