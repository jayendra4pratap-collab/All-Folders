#include <iostream>
#include <vector>
using namespace std;

class Employee
{
    char *name;

public:
    Employee(char *n)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    char *getName() const
    {
        return name;
    }
    ~Employee()
    {
        delete name;
    }
};
class Company
{
    char *name_p;
    Employee *myEmp_p;

public:
    Company(char *n , Employee *e)
    {
        name_p = new char[strlen(n)+1];
        strcpy(name_p,n);
        myEmp_p=e;
    }

    ~Company()
    {
        delete name_p;
    }

    void display()
    {
        cout << "Employee Name : " << myEmp_p->getName()
             << "\nCompany Name : " << name_p << endl;
    }
};
int main()
{
        //Aggregation
    char name[]= "Jayendra";
    Employee e1(name);
    Company c1((char*)"Amazon",&e1);
    c1.display();
    return 0;
}