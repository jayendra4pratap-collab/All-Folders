#include<iostream>
#include<vector>
using namespace std;
template <class T>
T add(T x,T y)
{
    return x+y;
}
template <class T>
T sub(T x,T y)
{
    return x-y;
}
template <class T>
T mul(T x,T y)
{
    return x*y;
}
template <class T>
T divide(T x,T y)
{
    return x/y;
}
int main()
{
    cout<<add(2,5)<<endl;
    cout<<add(4.4,6.8)<<endl;
    cout<<sub(9,5)<<endl;
    cout<<mul(3.3,6.2)<<endl;
    cout<<divide(8,3)<<endl;
    return 0;
}