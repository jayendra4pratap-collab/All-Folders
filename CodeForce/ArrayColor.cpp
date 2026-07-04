#include <iostream>
#include<map>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--> 0)
    {
        map < int, int > mpp;
        int n;
        cin>>n;
        int m ;
        for(int i=0;i<n;i++)
        {
            
            cin>>m;
            if(i%2==0)
            mpp[m]=0;
            else
            mpp[m]=1;
        }
        int flag=0;
        for (auto it = mpp.begin(); it != mpp.end(); ++it)
        {
            auto nextIt=it;
            ++nextIt;
            if(nextIt==mpp.end())
            break;
            if(it->second== nextIt->second)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
    }

}