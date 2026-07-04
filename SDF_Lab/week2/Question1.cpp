#include <iostream>
using namespace std;

int main()
{
    int A[3] = {10, 100, 200};
    int *ptr;

    
    cout << "(i) Incrementing Pointer (++):\n";
    ptr = A;  

    for (int i = 0; i < 3; i++)
    {
        cout << "Address of var[" << i << "] = " << ptr << endl;
        cout << "Value of var[" << i << "] = " << *ptr << endl;
        ptr++;   
    }

    
    cout << "\n(ii) Decrementing Pointer (--):\n";
    ptr = &A[2];   

    for (int i = 2; i >= 0; i--)
    {
        cout << "Address of var[" << i << "] = " << ptr << endl;
        cout << "Value of var[" << i << "] = " << *ptr << endl;
        ptr--;  
    }

    return 0;
}