#include <iostream>
#include <string>
using namespace std;

// -------- Base Class --------
class Person
{
public:
    string name; // Public member

protected:
    int age; // Protected member

private:
    string aadhaarNo; // Private member

public:
    // Function to set all details
    void setPersonDetails(string n, int a, string ad)
    {
        name = n;
        age = a;
        aadhaarNo = ad;
    }

    // Function to display only accessible members
    void displayPersonDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;

        // cout << "Aadhaar No: " << aadhaarNo << endl;
        // ❌ Not displayed as per requirement (private)
    }
};

// -------- Derived Class: Student (Single Inheritance) --------
class Student : public Person
{
public:
    int rollNo;

    void displayStudentDetails()
    {
      
        cout << "\n--- Student Details ---" << endl;
        displayPersonDetails();

        // cout << "Aadhaar No: " << aadhaarNo << endl;
        // ❌ ERROR: aadhaarNo is private in Person
        // Private members are NOT accessible in derived classes
    }
};

// -------- Derived Class: GraduateStudent (Multilevel Inheritance) --------
class GraduateStudent : public Student
{
public:
    string researchTopic;

    void displayGraduateDetails()
    {
        cout << "\n--- Graduate Student Details ---" << endl;
        cout << "Name: " << name << endl;      // From Person
        cout << "Age: " << age << endl;        // From Person
        cout << "Roll No: " << rollNo << endl; // From Student
        cout << "Research Topic: " << researchTopic << endl;
    }
};

// -------- Derived Class: Employee (Hierarchical Inheritance) --------
class Employee : public Person
{
public:
    int employeeId;

    void displayEmployeeDetails()
    {
        cout << "\n--- Employee Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Employee ID: " << employeeId << endl;
    }
};

int main()
{
    Student s;
    s.setPersonDetails("Rahul", 20, "1234-5678-9012");
    s.rollNo = 101;
    s.displayStudentDetails();

    GraduateStudent gs;
    gs.setPersonDetails("Anjali", 24, "9876-5432-1098");
    gs.rollNo = 202;
    gs.researchTopic = "Artificial Intelligence";
    gs.displayGraduateDetails();

}