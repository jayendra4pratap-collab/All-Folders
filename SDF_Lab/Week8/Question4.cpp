#include<iostream>
#include<cstring>
using namespace std;

// ---------------- Person ----------------
class Person
{
    char *name;

public:
    Person(const char *n)
    {
        name = new char[strlen(n)+1];
        strcpy(name,n);
    }

    void display()
    {
        cout << "Owner: " << name << endl;
    }
};

// ---------------- Wheel ----------------
class Wheel
{
    int size;

public:
    Wheel(int s)
    {
        size = s;
    }

    void display()
    {
        cout << "Wheel size: " << size << endl;
    }
};

// ---------------- Base Class ----------------
class Vehicle
{
protected:
    int wheelbase, maxPower, seat;

public:
    Vehicle(int w,int p,int s)
    {
        wheelbase=w;
        maxPower=p;
        seat=s;
    }

    void display()
    {
        cout << "\nVehicle Details:\n";
        cout << "Wheelbase: " << wheelbase << endl;
        cout << "Power: " << maxPower << endl;
        cout << "Seats: " << seat << endl;
    }
};

// ---------------- Inheritance ----------------
class Car : public Vehicle
{
public:
    Car(int w,int p,int s):Vehicle(w,p,s){}

    void type()
    {
        cout << "Type: Car\n";
    }
};

class Tachograph
{
public:
    void show()
    {
        cout << "Tachograph attached\n";
    }
};

class Lorry : public Vehicle
{
    Tachograph t;   // strong relation (1..1)

public:
    Lorry(int w,int p,int s):Vehicle(w,p,s){}

    void type()
    {
        cout << "Type: Lorry\n";
        t.show();
    }
};

// ---------------- Aggregation + Association ----------------
class VehicleFull : public Vehicle
{
    Person *owner;        // Aggregation
    Wheel *wheels[4];     // Association

public:
    VehicleFull(int w,int p,int s, Person *o,
                Wheel *w1, Wheel *w2, Wheel *w3, Wheel *w4)
        : Vehicle(w,p,s)
    {
        owner = o;

        wheels[0]=w1;
        wheels[1]=w2;
        wheels[2]=w3;
        wheels[3]=w4;
    }

    void show()
    {
        display();
        owner->display();

        cout << "Wheels:\n";
        for(int i=0;i<4;i++)
            wheels[i]->display();
    }
};

// ---------------- MAIN ----------------
int main()
{
    Person p("Jay");

    Wheel w1(16), w2(16), w3(16), w4(16);

    VehicleFull v(100,200,5,&p,&w1,&w2,&w3,&w4);
    v.show();

    Car c(90,150,5);
    c.type();

    Lorry l(120,300,2);
    l.type();

    return 0;
}