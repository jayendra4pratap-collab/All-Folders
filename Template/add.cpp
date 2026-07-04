#include<iostream>
#include<vector>
using namespace std;
template<class T>
T add( T a, T b)
{
    T sum = a+b;
    return sum;
}
int main()
{
    int a=2,b=3;
    float m=1.4,n=4.5;
    cout<<add(a,b)<<endl;
    cout<<add(m,n)<<endl;
    return 0;
}