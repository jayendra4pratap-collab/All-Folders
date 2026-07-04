#include <iostream>
using namespace std;

// -------- Base Class --------
class PaymentMethod
{
public:
    virtual void authenticate() = 0;
    virtual void processPayment(double amount) = 0;

    virtual ~PaymentMethod() {}
};

// -------- Online Payment --------
class OnlinePayment : virtual public PaymentMethod
{
public:
    void authenticate() override
    {
        cout << "Authenticating online payment credentials" << endl;
    }
};

// -------- Card Payment --------
class CardPayment : virtual public PaymentMethod
{
public:
    void processPayment(double amount) override
    {
        cout << "Processing card payment of Rs." << amount << endl;
    }
};

// -------- SmartWallet (Hybrid) --------
class SmartWallet : public OnlinePayment, public CardPayment
{
public:
    // Uses OnlinePayment's authenticate()
    // Uses CardPayment's processPayment()

    void authenticate() override
    {
        OnlinePayment::authenticate();
        cout << "SmartWallet authentication successful" << endl;
    }

    void processPayment(double amount) override
    {
        cout << "SmartWallet initiating payment..." << endl;
        CardPayment::processPayment(amount);
        cout << "SmartWallet payment completed" << endl;
    }
};

// -------- Utility Function --------
void makePayment(PaymentMethod *p, double amount)
{
    p->authenticate();
    p->processPayment(amount);
    cout << "------------------------" << endl;
}

// -------- Main Function --------
int main()
{
    PaymentMethod *p;

    SmartWallet sw;

    p = &sw;   // base class pointer

    makePayment(p, 5000);

    return 0;
}