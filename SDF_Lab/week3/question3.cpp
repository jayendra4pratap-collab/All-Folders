#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    long long enr;
    string name;
    string branch;
    double cgpa;

public:
    Student()
    {
        enr = 1;
        name = "Unknown";
        branch = "CSE";
        cgpa = 6.0;
    }

    
    Student(long long e, string n, double c)
    {
        enr = e;
        name = n;
        branch = "CSE";
        cgpa = c;
    }

   
    Student(long long e, string n, string b, double c)
    {
        enr = e;
        name = n;
        branch = b;
        cgpa = c;
    }

   
    long long getEnr()
    {
        return enr;
    }

    string getName()
    {
        return name;
    }

    string getBranch()
    {
        return branch;
    }

    double getCgpa()
    {
        return cgpa;
    }

   
    void setEnr(long long e)
    {
        enr = e;
    }

    void setName(string n)
    {
        name = n;
    }

    void setBranch(string b)
    {
        branch = b;
    }

    void setCgpa(double c)
    {
        cgpa = c;
    }

   
    void put()
    {
        cout << "Student Name: " << name << endl;
        cout << "Enrollment Number: " << enr << endl;
        cout << "Branch: " << branch << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "------------------------" << endl;
    }
};

int main()
{
    Student ob1;
    Student ob2(287, "Jayendra", 8.7);
    Student ob3(285, "Krish", "CSE", 8.5);

    ob3.setCgpa(8.6);

    //ob1.put();
    ob2.put();
    ob3.put();

    return 0;
}