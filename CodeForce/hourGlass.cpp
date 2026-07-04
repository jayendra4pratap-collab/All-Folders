#include <iostream>
#include<algorithm>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        long long s,k,m;
        cin >> s>>k>>m;
        if(s<k)
        {
            cout<<s-min(m%k,s)<<endl;
        }else{
            if((m/k)%2==0)
            {
                cout<<s-(m%k)<<endl;
            }else{
                cout<<k-(m%k)<<endl; 
            }
        }
       /* long upglass=0,downglass=0;
        while(m>0)
        {
            if(m>=k)
            {
                if(s>=k)
                {
                    upglass=s-k;
                    downglass=s-upglass;
                }
                else
                {
                    upglass=0;
                    downglass=s;
                }
            }
            else
            {
                if(m<=s)
                {
                    upglass-=m;
                    downglass=s-upglass;
                }
                else
                {
                    upglass=0;
                    downglass=s;
                }
            }
            m-=k;
            if(m>=0)
            {
            int temp=upglass;
            upglass=downglass;
            downglass=temp;
            }
            
        }
        
        cout<<upglass<<endl;
        */
        
    }
}