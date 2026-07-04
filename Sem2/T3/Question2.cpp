#include <iostream>
#include <vector>
using namespace std;

class BankAccount
{
protected:
    double balance;

public:
    BankAccount(double bal) : balance(bal) {}
    virtual double interest()=0;
    double getBalance() const
    {
        return balance;
    }

    double operator+(const BankAccount &other)
    {
        return balance + other.balance;
    }
    virtual ~BankAccount() {}
};
class SavingsAccount : public BankAccount
{
public:
    SavingsAccount(double bal) : BankAccount(bal) {}
    double interest()
    {
        double interest = balance * 0.04;
        if (balance > 1000)
        {
            interest += balance * 0.01;
        }
        return interest;
    }
};
class CheckingAccount : public BankAccount
{
public:
    CheckingAccount(double bal) : BankAccount(bal) {}
    double interest()
    {
        double interest = balance * 0.02;
        interest -= 5;
        return interest;
    }
};
class BussinessAccount : public BankAccount
{
public:
    BussinessAccount(double bal) : BankAccount(bal) {}
    double interest()
    {
        double interest = balance * 0.05;
        if (balance > 50000)
        {
            interest += balance * 0.02;
        }
        return interest;
    }
};
int main()
{
    BankAccount *acc1 = new SavingsAccount(15000);
    BankAccount *acc2 = new CheckingAccount(8000);
    BankAccount *acc3 = new BussinessAccount(60000);
    cout << "Savings Account Interest: ₹ " << acc1->interest() << endl;
    cout << "Checking Account Interest: ₹ " << acc2->interest() << endl;
    cout << "Business Account Interest: ₹ " << acc3->interest() << endl;

    double totalBalance = *acc1 + *acc3;
    cout << "Combined Balance of Savings and Business Account: Rs. " << totalBalance << endl;

    delete acc1;
    delete acc2;
    delete acc3;
    return 0;
}