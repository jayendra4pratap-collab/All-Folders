#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

    // Utility function to normalize inches
    void normalize() {
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        }
        if (inches < 0) {
            int borrow = (-inches + 11) / 12;
            feet -= borrow;
            inches += borrow * 12;
        }
    }

public:
    // Constructors
    Distance() {
        feet = 0;
        inches = 0;
    }

    Distance(int f, int i) {
        feet = f;
        inches = i;
        normalize();
    }

    // Getter functions
    int getFeet() const { return feet; }
    int getInches() const { return inches; }

    // Setter functions
    void setFeet(int f) { feet = f; }
    void setInches(int i) {
        inches = i;
        normalize();
    }

    // a) Unary minus operator
    Distance operator-() const {
        return Distance(-feet, -inches);
    }

    // b) Relational < operator
    bool operator<(const Distance& d) const {
        int total1 = feet * 12 + inches;
        int total2 = d.feet * 12 + d.inches;
        return total1 < total2;
    }

    // c) Binary + operator
    Distance operator+(const Distance& d) const {
        return Distance(feet + d.feet, inches + d.inches);
    }

    // d) Assignment operator
    Distance& operator=(const Distance& d) {
        if (this != &d) {
            feet = d.feet;
            inches = d.inches;
        }
        return *this;
    }

    // e) Equality == operator
    bool operator==(const Distance& d) const {
        return (feet == d.feet && inches == d.inches);
    }

    // f) Prefix increment ++d
    Distance& operator++() {
        inches++;
        normalize();
        return *this;
    }

    // f) Postfix increment d++
    Distance operator++(int) {
        Distance temp = *this;
        inches++;
        normalize();
        return temp;
    }

    // Display function
    void display() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

int main() {
    Distance d1(5, 8);
    Distance d2(3, 10);

    cout << "d1: ";
    d1.display();

    cout << "d2: ";
    d2.display();

    // Unary minus
    Distance d3 = -d1;
    cout << "Unary minus of d1: ";
    d3.display();

    // Addition
    Distance d4 = d1 + d2;
    cout << "d1 + d2: ";
    d4.display();

    // Relational <
    if (d1 < d2)
        cout << "d1 is less than d2" << endl;
    else
        cout << "d1 is NOT less than d2" << endl;

    // Assignment
    Distance d5;
    d5 = d1;
    cout << "After assignment d5: ";
    d5.display();

    // Equality ==
    if (d1 == d5)
        cout << "d1 and d5 are equal" << endl;

    // Prefix increment
    ++d1;
    cout << "After prefix ++d1: ";
    d1.display();

    // Postfix increment
    d1++;
    cout << "After postfix d1++: ";
    d1.display();

    return 0;
}