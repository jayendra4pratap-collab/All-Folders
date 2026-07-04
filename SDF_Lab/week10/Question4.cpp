#include<iostream>
#include<vector>
using namespace std;
template <class T>
T minimum(T x,T y)
{
    if(x<y)
    return x;
    return y;
}
template <class T>
T maximum(T x,T y)
{
    if(x<y)
    return y;
    return x;
}
int main()
{
    cout<<minimum(6,8)<<endl;
    cout<<minimum(5.5,5.8)<<endl;
    cout<<maximum(8.8,9.4)<<endl;
    return 0;
}