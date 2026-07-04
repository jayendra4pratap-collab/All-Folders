#include <iostream>

using namespace std;

// Base Class

class Employee
{

protected:
    string name;

public:
    Employee(string n) : name(n) {}

    virtual double calculateSalary() = 0; // Pure virtual

    string getName()
    {

        return name;
    }

    // Operator Overloading

    bool operator>(Employee &e)
    {

        return this->calculateSalary() > e.calculateSalary();
    }

    virtual void display() = 0; // Pure virtual
};

// Full Time Employee

class FullTimeEmployee : public Employee
{

    double baseSalary, bonus;

public:
    FullTimeEmployee(string n, double b, double bo)

        : Employee(n), baseSalary(b), bonus(bo)
    {
    }

    double calculateSalary() override
    {

        return baseSalary + bonus;
    }

    void display() override
    {

        cout << "Full Time Employee (" << name << ") Salary: "

             << calculateSalary() << endl;
    }
};

// Part Time Employee

class PartTimeEmployee : public Employee
{

    double hourlyRate;

    int hoursWorked;

public:
    PartTimeEmployee(string n, double rate, int hours)

        : Employee(n), hourlyRate(rate), hoursWorked(hours)
    {
    }

    double calculateSalary() override
    {

        return hourlyRate * hoursWorked;
    }

    void display() override
    {

        cout << "Part Time Employee (" << name << ") Salary: "

             << calculateSalary() << endl;
    }
};

// Freelancer

class Freelancer : public Employee
{

    double projectPay;

public:
    Freelancer(string n, double pay)

        : Employee(n), projectPay(pay)
    {
    }

    double calculateSalary() override
    {

        return projectPay;
    }

    void display() override
    {

        cout << "Freelancer (" << name << ") Salary: "

             << calculateSalary() << endl;
    }
};

int main()
{

    int n;

    cout << "Enter number of employees: ";

    cin >> n;

    Employee *emp[n];

    for (int i = 0; i < n; i++)
    {

        int type;

        cout << "\n1. FullTime  2. PartTime  3. Freelancer\n";

        cout << "Enter type: ";

        cin >> type;

        string name;

        cout << "Name: ";

        cin >> name;

        if (type == 1)
        {

            double base, bonus;

            cout << "Base Salary: ";

            cin >> base;

            cout << "Bonus: ";

            cin >> bonus;

            emp[i] = new FullTimeEmployee(name, base, bonus);
        }

        else if (type == 2)
        {

            double rate;

            int hours;

            cout << "Hourly Rate: ";

            cin >> rate;

            cout << "Hours Worked: ";

            cin >> hours;

            emp[i] = new PartTimeEmployee(name, rate, hours);
        }

        else
        {

            double pay;

            cout << "Project Pay: ";

            cin >> pay;

            emp[i] = new Freelancer(name, pay);
        }
    }

    cout << "\nEmployee Salary Details:\n";

    for (int i = 0; i < n; i++)
    {

        emp[i]->display(); // Polymorphism
    }

    // Comparison

    if (n >= 2)
    {

        cout << "\nSalary Comparison:\n";

        if (*emp[0] > *emp[1])

            cout << emp[0]->getName() << " earns more than "

                 << emp[1]->getName() << endl;

        else

            cout << emp[1]->getName() << " earns more than "

                 << emp[0]->getName() << endl;
    }

    return 0;
}

/*#include <iostream>
using namespace std;
class Employee
{
    string name;
    string id;

public:
    double salary;
    double interest;
    Employee()
    {
        interest = 0;
        salary = 0;
    }
    Employee(string n, string i, double b)
    {
        name = n;
        id = i;
        salary = b;
    }
    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Id : " << id << endl;
        cout << "Salary " << salary << endl;
    }
    void operator>(const Employee &e)
    {
        if (salary > e.salary)
            cout << name << " has higher salary than " << e.name << endl;
        else
            cout << e.name << " has higher salary than " << name << endl;
    }
    virtual void calSalary()
    {
    }
};
class FullTime : public Employee

{
public:
    void calSalary()
    {
        interest = 0.1 * salary;
    }
    void display()
    {
        cout << "Amount = " << salary + interest << endl;
    }
};
class PartTime : public Employee
{
public:
    void calSalary()
    {
        interest = 0.05 * salary;
    }
    void display()
    {
        cout << "Amount = " << salary + interest << endl;
    }
};
class FreeLancer : public Employee
{
public:
    void calSalary()
    {
        interest = 0.2 * salary;
    }
    void display()
    {
        cout << "Amount = " << salary + interest << endl;
    }
};
int main()
{
    int n;
    cout << "Enter number of employee : ";
    cin >> n;
    Employee *e = new Employee[n];
    for (int i = 0; i < n; i++)
    {
        string name;

        string id;
        double sal;
        cout << "Name :";
        cin >> name;
        cout << "Id :";
        cin >> id;
        cout << "Salary : ";
        cin >> sal;
        e[i] = Employee(name, id, sal);
    }
    for(int i=0;i<n-1;i++)
    {
        e[i]>e[i+1];
    }
    for (int i = 0; i < n; i++)
    {
        e[i].calSalary();
    }
    for (int i = 0; i < n; i++)
    {
        e[i].display();
    }
}*/