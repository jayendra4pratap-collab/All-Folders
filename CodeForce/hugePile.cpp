#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t-->0)
	{
	    long n,k;
	    cin>>n>>k;
	    int two=0;
	    bool possible=false;
	    int calctime=0;
	    //cout<<"HEllo"<<endl;
	    long half;
	    while((2<<two)<n)
	    {
	        
	        half=n/(2<<two);
	       // cout<<"  half = "<<half<<n<<k<<endl;
	        two++;
	        if((half==k )|| (half+1)==k)
	        {
	             possible=true;
	             calctime=two;
	            break;
	        }
	        
	    }
	    if(possible)
	    cout<<calctime<<endl;
	    else
	    cout<<"-1"<<endl;
	}
}
