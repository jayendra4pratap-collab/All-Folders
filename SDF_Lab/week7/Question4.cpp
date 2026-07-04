#include <iostream>
using namespace std;

// -------- Abstract Base Class --------
class Device
{
public:
    virtual void start() = 0;  // pure virtual function

    virtual void showStatus()
    {
        cout << "Device operating normally" << endl;
    }

    virtual ~Device() {}
};

// -------- Printer Class --------
class Printer : public Device
{
public:
    void start() override
    {
        cout << "Printer is printing documents" << endl;
    }
};

// -------- AirConditioner Class --------
class AirConditioner : public Device
{
public:
    void start() override
    {
        cout << "Air conditioner cooling the room" << endl;
    }
};

// -------- Utility Function --------
void operateDevice(Device *d)
{
    d->start();        // runtime polymorphism
    d->showStatus();   // common behavior
    cout << "----------------------" << endl;
}

// -------- Main Function --------
int main()
{
    // Different devices
    Device *d1 = new Printer();
    Device *d2 = new AirConditioner();

    // Operating devices using common interface
    operateDevice(d1);
    operateDevice(d2);

    // Clean up
    delete d1;
    delete d2;

    return 0;
}