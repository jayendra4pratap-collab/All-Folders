#include <iostream>
using namespace std;

int main() {
    string correctPassword = "1234";
    string inputPassword;
    double balance = 1000;
    double amount;
    int log[5];
    int index;

    try {
        try {
            cout << "Enter password: ";
            cin >> inputPassword;

            if (inputPassword != correctPassword) {
                throw "Incorrect password";
            }

            cout << "Login successful" << endl;

            try {
                cout << "Enter withdrawal amount: ";
                cin >> amount;

                if (amount < 0) {
                    throw "Negative withdrawal amount";
                }
                if (amount > balance) {
                    throw "Insufficient balance";
                }

                balance -= amount;
                cout << "Withdrawal successful. Balance: " << balance << endl;

                try {
                    cout << "Enter log index (0-4): ";
                    cin >> index;

                    if (index < 0 || index >= 5) {
                        throw "Log index out of bounds";
                    }

                    log[index] = amount;
                    cout << "Transaction logged at index " << index << endl;
                }
                catch (const char* msg) {
                    cout << "Log Error: " << msg << endl;
                }

            }
            catch (const char* msg) {
                cout << "Withdrawal Error: " << msg << endl;
            }

        }
        catch (const char* msg) {
            cout << "Login Error: " << msg << endl;
        }
    }
    catch (...) {
        cout << "Transaction failed due to unexpected error" << endl;
    }

    cout << "Program continues..." << endl;

    return 0;
}