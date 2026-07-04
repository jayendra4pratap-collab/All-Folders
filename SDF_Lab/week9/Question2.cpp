#include <iostream>
#include <ctype>
using namespace std;

int main() {
    int num;
    char ch;

    try {
        cout << "Enter an integer: ";
        cin >> num;

        if (num < 0) {
            throw "Integer is negative";
        }

        cout << "Enter a character: ";
        cin >> ch;

        if (!isalpha(ch)) {
            throw "Character is not an alphabet";
        }

        cout << "Valid input received" << endl;
        cout << "Integer: " << num << ", Character: " << ch << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}