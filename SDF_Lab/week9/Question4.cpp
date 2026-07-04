#include <iostream>
using namespace std;

class InvalidAgeException {};

int main() {
    int age;

    try {
        cout << "Enter age: ";
        cin >> age;

        if (age < 18) {
            throw InvalidAgeException();
        }

        cout << "Eligible for voting" << endl;
    }
    catch (InvalidAgeException) {
        cout << "Age is less than 18. Not eligible for voting" << endl;
    }

    return 0;
}