#include <iostream>
using namespace std;

class BankAccount {
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void withdraw(double amount) {
        if (amount < 0) {
            throw "Negative withdrawal amount";
        }
        if (amount > balance) {
            throw "Insufficient balance";
        }
        balance -= amount;
        cout << "Withdrawal successful. Remaining balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc(1000);
    double amt;

    cout << "Enter withdrawal amount: ";
    cin >> amt;

    try {
        acc.withdraw(amt);
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    return 0;
}