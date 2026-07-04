#include <iostream>
using namespace std;
class BankAccount
{
private:
    char *accountHolder;
    double balance;

public:
    BankAccount(char *acc, double bal)
    {
        accountHolder = acc;
        balance = bal;
    }
    BankAccount(const BankAccount &obj)
    {
        accountHolder=obj.accountHolder;
        balance=obj.balance;
    }
    ~BankAccount()
    {
        cout << "Destructor called" << endl;
    }
    void display()
    {
        cout << "Name: " << accountHolder << endl;
        cout << "Balance:" << balance << endl;
    }
};

int main()
{
    BankAccount obj1("Jayendra", 15000);
    BankAccount obj2(obj1);         //deep copy
    obj1.display();
    obj2.display();
    return 0;
}