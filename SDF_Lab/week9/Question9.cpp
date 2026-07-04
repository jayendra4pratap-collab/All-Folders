#include <iostream>
using namespace std;

double balance = 5000;

void processPayment(double amount) {
    if (amount > balance) {
        throw "Insufficient balance for payment";
    }
    cout << "Payment processed successfully" << endl;
}

void placeOrder(double amount) {
    try {
        processPayment(amount);
        cout << "Order placed successfully" << endl;
    }
    catch (const char* msg) {
        cout << "Logging Error: " << msg << endl;
        throw;
    }
}

int main() {
    double amount;

    cout << "Enter order amount: ";
    cin >> amount;

    try {
        placeOrder(amount);
        cout << "Order confirmed" << endl;
    }
    catch (const char* msg) {
        cout << "Final Error: " << msg << endl;
    }

    cout << "Program continues..." << endl;

    return 0;
}