#include <iostream>
using namespace std;

class Complex;
class Value;

class XYZ {
public:
    void multiply(Complex&, Value&);
};

class Value {
public:
    int a;
    Value() {
        a = 4;
    }
};

class Complex {
private:
    int real;
    int imag;

public:
    Complex() {
        real = 3;
        imag = 4;
    }

    // friend member function
    friend void XYZ::multiply(Complex&, Value&);
};

// function definition AFTER all classes are known
void XYZ::multiply(Complex& c, Value& v) {
    cout << "real = " << c.real * v.a << endl;
    cout << "imag = " << c.imag * v.a << endl;
}

int main() {
    Complex c1;
    Value v1;
    XYZ x1;

    x1.multiply(c1, v1);
    return 0;
}