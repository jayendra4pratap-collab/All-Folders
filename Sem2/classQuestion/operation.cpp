#include <iostream>
#include <cstring>
using namespace std;

class BankAccount {
private:
    char* accountHolder;   // dynamically allocated name
    double balance;        // account balance

public:
    // (i) Parameterized Constructor
    // Allocates memory and initializes data members
    BankAccount(const char* name, double bal) {
        accountHolder = new char[strlen(name) + 1];
        strcpy(accountHolder, name);
        balance = bal;
        cout << "Parameterized Constructor called\n";
    }

    // (ii) Copy Constructor (Deep Copy)
    // Creates a separate copy of dynamic memory
    BankAccount(const BankAccount& acc) {
        accountHolder = new char[strlen(acc.accountHolder) + 1];
        strcpy(accountHolder, acc.accountHolder);
        balance = acc.balance;
        cout << "Copy Constructor called (Deep Copy)\n";
    }

    // (iii) Destructor
    // Releases dynamically allocated memory
    ~BankAccount() {
        delete[] accountHolder;
        cout << "Destructor called, memory released\n";
    }

    // (iv) Display function
    void display() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    cout << "Creating first account:\n";
    BankAccount acc1("Jayendra Singh", 5000.50);

    cout << "\nDisplaying acc1 details:\n";
    acc1.display();

    cout << "\nCreating second account using copy constructor:\n";
    BankAccount acc2(acc1);   // Copy constructor invoked

    cout << "\nDisplaying acc2 details:\n";
    acc2.display();

    return 0;
}