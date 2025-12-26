#include <iostream>
using namespace std;

int main() {
	int n ,t;
	cin>>t;
	while(t-->0)
	{
	    cin>>n;
	    string str;
	    cin>>str;
	    int count=0;
	    for(int i =0;i<n-1;i++)
	    {
	        char ch1 = str.at(i);
	        char ch2 = str.at(i+1);
	        if((ch1=='<'&&ch2=='>') || (ch1=='>'&&ch2=='<'))
	        count++;
	    }
	    if(n==1)
	    cout<<"1";
	    else if(n==2 && count==1)
	    cout<<"0";
	    else
	    cout<<n-count;
	    cout<<endl;
	    
	}

}
