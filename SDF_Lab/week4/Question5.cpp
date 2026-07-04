#include <iostream>
using namespace std;



class Point
{
    int x, y;

public:

    Point()
    {
        x = 0;
        y = 0;
    }


    Point(int a, int b)
    {
        x = a;
        y = b;
    }


    Point(const Point &p)
    {
        x = p.x;
        y = p.y;
    }

    void display()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

/*-------------------- PART (b) : Distance --------------------*/

class Distance
{
    int feet;
    int inches;

public:
    Distance(int f, int i)
    {
        feet = f;
        inches = i;
    }

    friend void compareDistance(Distance, Distance);
};

void compareDistance(Distance d1, Distance d2)
{
    int total1 = d1.feet * 12 + d1.inches;
    int total2 = d2.feet * 12 + d2.inches;

    if (total1 > total2)
        cout << "First distance is larger" << endl;
    else if (total2 > total1)
        cout << "Second distance is larger" << endl;
    else
        cout << "Both distances are equal" << endl;
}

/*-------------------- PART (c) : Account --------------------*/

class Account
{
    int accountNumber;
    double balance;

public:
    Account(int acc, double bal)
    {
        accountNumber = acc;
        balance = bal;
    }

    friend void transferFunds(Account &, Account &, double);
};

void transferFunds(Account &from, Account &to, double amount)
{
    if (from.balance >= amount)
    {
        from.balance -= amount;
        to.balance += amount;

        cout << "Transfer successful" << endl;
    }
    else
    {
        cout << "Insufficient balance" << endl;
    }

    cout << "From Account balance : " << from.balance << endl;
    cout << "To Account balance   : " << to.balance << endl;
}

/*-------------------- PART (d) : Time --------------------*/

class Time
{
    int hours, minutes, seconds;

public:
    Time(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }

    friend Time addTime(Time, Time);

    void display()
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
};

Time addTime(Time t1, Time t2)
{
    Time t(0, 0, 0);

    t.seconds = t1.seconds + t2.seconds;
    t.minutes = t1.minutes + t2.minutes + t.seconds / 60;
    t.seconds = t.seconds % 60;

    t.hours = t1.hours + t2.hours + t.minutes / 60;
    t.minutes = t.minutes % 60;

    return t;
}

/*-------------------- main --------------------*/

int main()
{

    Point p1;
    Point p2(3, 4);
    Point p3(p2);

    cout << "Points:" << endl;
    p1.display();
    p2.display();
    p3.display();

    cout << endl;


    Distance d1(5, 8);
    Distance d2(6, 2);
    compareDistance(d1, d2);

    cout << endl;


    Account a1(101, 5000);
    Account a2(102, 2000);

    transferFunds(a1, a2, 1500);

    cout << endl;


    Time t1(2, 45, 50);
    Time t2(1, 20, 30);

    Time result = addTime(t1, t2);

    cout << "Added time : ";
    result.display();

    return 0;
}