#include<iostream>
using namespace std;

int main() {
    long n,k;
    cin>>n;
	long arr[n][12];
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<12;j++)
	    {
	        cin>>arr[i][j];
	    }
	}
	cin>>k;
	for(int i=0;i<n;i++)
	{
	    double sum=0;
	    for(int j=0;j<12;j++)
	    {
	        sum = sum + arr[i][j];
	    }
	    if((sum/12)>k)
	    cout<<"Yes ";
	    else
	    cout<<"No ";
	}

}
