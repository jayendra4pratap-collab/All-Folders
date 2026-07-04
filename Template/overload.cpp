#include <iostream>
using namespace std;
// First version of f() template.
template <class X>
void f(X a)
{
    cout << "Inside f(X a, Y b)\n";
}
template <class X, class Y>

void f(Y a)
{
    cout << "Inside f(X a)\n";
}
// Second version of f() template.



int main()
{
    f(10);
    // calls f(X)
    f( 20); // calls f(X, Y)
    return 0;
}