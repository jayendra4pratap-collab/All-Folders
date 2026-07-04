#include<iostream>
#include<cstring>
using namespace std;

// -------- CPU --------
class CPU
{
    double clock_speed;

public:
    CPU()
    {
        clock_speed = 0;
    }

    CPU(double cs)
    {
        clock_speed = cs;
    }

    double getClockSpeed()
    {
        return clock_speed;
    }

    void setClockSpeed(double cs)
    {
        clock_speed = cs;
    }
};

// -------- Computer (COMPOSITION) --------
class Computer
{
    CPU processor;   // object inside → composition

public:
    Computer() {}

    Computer(double cs) : processor(cs) {}

    CPU getCpu()
    {
        return processor;
    }

    void show()
    {
        cout << "CPU Speed: " << processor.getClockSpeed() << endl;
    }
};

// -------- PC (Inheritance) --------
class PC : public Computer
{
    char *pcname;

public:
    PC(const char *name, double cs) : Computer(cs)
    {
        pcname = new char[strlen(name)+1];
        strcpy(pcname, name);
    }

    void display()
    {
        cout << "PC Name: " << pcname << endl;
        show();
    }
};

// -------- MAIN --------
int main()
{
    PC p("Dell", 3.5);
    p.display();

    return 0;
}