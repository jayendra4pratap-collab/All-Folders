#include<iostream>
using namespace std;

class XYZ;   
class Value;  
class Complex
{

    private:
    int real;
    int imag;
    public : 
    Complex()

    {
        real=3;
        imag=4;
    }
    //friend void XYZ::multiply(Complex&,Value&);
    friend class XYZ;
    
};
class XYZ{
    public : 
    void multiply(Complex &c, Value &v) {
    cout << "real = " << c.real * v.a << endl;
    cout << "imag = " << c.imag * v.a << endl;
}
};

class Value
{
    public : 
    int a;
    Value()
    {
        a=4;
    }
};





int main()
{

    Complex c1;
    Value v1;
    XYZ x1;
    x1.multiply(c1,v1);

    return 0;
}