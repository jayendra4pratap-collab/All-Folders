#include <iostream>
using namespace std;

class BankAccount
{
    string name;
    int accountNumber;
    double balance;

public:
    void assign(string n, int accNo, double bal)
    {
        name = n;
        accountNumber = accNo;
        balance = bal;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance\n";
    }

    void display()
    {
        cout << "Account Holder Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount acc;
    acc.assign("Jayendra", 12345, 5000);
    acc.deposit(2000);
    acc.withdraw(3000);
    acc.display();
    return 0;
}