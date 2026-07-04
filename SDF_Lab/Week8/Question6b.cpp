#include<iostream>
#include<cstring>
using namespace std;

// -------- CPU --------
class CPU
{
    double clock_speed;

public:
    CPU(double cs)
    {
        clock_speed = cs;
    }

    double getClockSpeed()
    {
        return clock_speed;
    }
};

// -------- Computer (AGGREGATION) --------
class Computer
{
    CPU *processor;   // pointer → aggregation

public:
    Computer()
    {
        processor = NULL;
    }

    Computer(CPU *p)
    {
        processor = p;
    }

    void setCpu(CPU *p)
    {
        processor = p;
    }

    CPU* getCpu()
    {
        return processor;
    }

    void show()
    {
        if(processor)
            cout << "CPU Speed: " << processor->getClockSpeed() << endl;
    }
};

// -------- PC (Inheritance) --------
class PC : public Computer
{
    char *pcname;

public:
    PC(const char *name, CPU *p) : Computer(p)
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
    CPU c1(4.0);   // created independently

    PC p("HP", &c1);
    p.display();

    return 0;
}