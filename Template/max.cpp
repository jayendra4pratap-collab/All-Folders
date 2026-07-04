#include<iostream>
using namespace std;

template<class T1, class T2, class T3>
auto maxi(T1 a, T2 b, T3 c)
{
    if(a > b)
    {
        if(a > c)
            return a;
        else
            return c;
    }
    else
    {
        if(b > c)
            return b;
        else
            return c;
    }
}

int main()
{
    cout << maxi(4, 9, 5) << endl;
    cout << maxi(6.6, 4.4, 8.1) << endl;
    cout << maxi(4, 5.8, 5) << endl;
    return 0;
}