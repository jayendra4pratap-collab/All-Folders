#include <iostream>
using namespace std;

template <class T>
class Calculator
{
    T a, b;

public:
    Calculator(T x, T y)
    {
        a = x;
        b = y;
    }

    void add()
    {
        cout << "Addition = " << a + b << endl;
    }

    void subtract()
    {
        cout << "Subtraction = " << a - b << endl;
    }

    void multiply()
    {
        cout << "Multiplication = " << a * b << endl;
    }

    void divide()
    {
        if (b == 0)
        {
            cout << "Division not possible" << endl;
        }
        else
        {
            cout << "Division = " << a / b << endl;
        }
    }
};

int main()
{
    Calculator<int> c1(20, 10);

    cout << "Integer Calculator\n";
    c1.add();
    c1.subtract();
    c1.multiply();
    c1.divide();

    cout << endl;

    Calculator<float> c2(5.5, 2.2);

    cout << "Float Calculator\n";
    c2.add();
    c2.subtract();
    c2.multiply();
    c2.divide();

    return 0;
}