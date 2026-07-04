#include <iostream>
using namespace std;

class Quadratic {
private:
    int a, b, c;

public:
    // Default constructor
    Quadratic() {
        a = b = c = 0;
    }

    // Overload >> operator
    friend istream& operator>>(istream& in, Quadratic& q) {
        in >> q.a >> q.b >> q.c;
        return in;
    }

    // Overload << operator
    friend ostream& operator<<(ostream& out, Quadratic& q) {
        out << q.a << "x^2 + " << q.b << "x + " << q.c;
        return out;
    }

    // Overload + operator
    Quadratic operator+(Quadratic q) {
        Quadratic temp;
        temp.a = a + q.a;
        temp.b = b + q.b;
        temp.c = c + q.c;
        return temp;
    }
};

int main() {
    Quadratic q1, q2, q3;

    cout << "Enter coefficients of first equation (a b c): ";
    cin >> q1;

    cout << "Enter coefficients of second equation (a b c): ";
    cin >> q2;

    q3 = q1 + q2;

    cout << "Resultant equation: ";
    cout << q3;

    return 0;
}