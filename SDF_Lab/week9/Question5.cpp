#include <iostream>
#include <vector>
using namespace std;
void calSquareRoot(int n)
{
    if (n < 0)
            throw "Number is negative";
    cout << "SquareRoot  : " << sqrt(n);
}
int main()
{
    int n;
    cout << "Enter number : ";
    cin >> n;
    try
    {
        
        calSquareRoot(n);
        
    }
    
    catch (const char *s)
    {
        cout << s;
    }
    return 0;
}