#include <iostream>
using namespace std;

template <class T>
class Complex
{
    T real, imag;

public:
    Complex(T r = 0, T i = 0)
    {
        real = r;
        imag = i;
    }

    Complex operator + (Complex c)
    {
        return Complex(real + c.real, imag + c.imag);
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

template <class T>
T sum(T arg1, T arg2)
{
    return arg1 + arg2;
}

int main()
{
    // Integer addition
    int a = 10, b = 20;
    cout << "Sum of integers = " << sum(a, b) << endl;

    // Complex number addition
    Complex<int> c1(2, 3), c2(4, 5);

    Complex<int> c3 = sum(c1, c2);

    cout << "Sum of complex numbers = ";
    c3.display();

    return 0;
}