#include <iostream>
using namespace std;

class Student
{
    string name;

public:
    Student(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }
};

class Department
{
    string name;

public:
    Department(string n)
    {
        name = n;
    }

    string getDeptName()
    {
        return name;
    }
};

class Course
{
    Student *s;
    Department *d;
    string courseName;

public:
    Course(Student *st, Department *dp, string cname)
    {
        s = st;
        d = dp;
        courseName = cname;
    }

    void display()
    {
        cout << s->getName() << " -> "
             << d->getDeptName() << " ("
             << courseName << ")" << endl;
    }
};

int main()
{
    Student s1("Jay"), s2("Aman");
    Department d1("CSE"), d2("ME");

    Course c[3] = {
        Course(&s1, &d1, "DS"),
        Course(&s1, &d2, "Thermo"),
        Course(&s2, &d1, "Algo")};

    for (int i = 0; i < 3; i++)
    {
        c[i].display();
    }

    return 0;
}