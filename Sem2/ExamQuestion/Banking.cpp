#include <iostream>
#include <vector>
using namespace std;

class Bank
{
    protected : 
    int acc_number;
    string name;
    double balance;

public:
    Bank(int num, string n, double b) : acc_number(num), name(n), balance(b) {}

    void deposit(double amount)
    {
        balance += amount;
        cout << "Amount added successfully .";
    }

    void withdraw(double amount)
    {
        if (balance < amount)
            cout << "Your balance is low ..can't be withdraw" << endl;
        else
        {
            balance -= amount;
            cout << "Your amount has been withdraw." << endl;
        }
    }
    void display()
    {
        cout << "Account Number : " << acc_number << endl
             << "Account Holder Name : " << name << endl
             << "Balance : " << balance << endl;
    }
};

class SavingAccount : public Bank
{
    double interest;

public:
    SavingAccount(double i, int num, string n, double b) : interest(i), Bank(num, n, b) {}

    void applyInterest()
    {
        balance += (balance * ((interest) / 100));
    }

    void display()
    {
        Bank::display();
        cout << "Interest Rate : " << interest << endl;
    }
};

class CurrAccount : public Bank
{
    double limit;

public:
    CurrAccount(double l, int num, string n, double b) : limit(l), Bank(num, n, b) {}

    void withdraw(double amount)
    {
        if (amount > balance + limit)
        {
            cout << "Withdrawal exceeds overdraft limit!" << endl;
           return ; 
        }
        balance -= amount;
        cout << "Withdrawn " << amount << ". New Balance: " << balance << endl;
        
    }

    void display()
    {
        Bank::display();
        cout << "OverDraft Limit : " << limit << endl;
    }
};
int main()
{
    SavingAccount obj1(3.5,1001,"Jay",5000);
    CurrAccount obj2(1002,3000,"Manas",1000);
    obj1.display();
    obj2.display();
    obj1.deposit(1000);
    obj1.applyInterest();
    obj2.withdraw(3500);
    obj1.display();
    obj2.display();
    return 0;
}