#include<iostream>
using namespace std;
struct Employee
{
    string id;
    string name;
    double basicSalary;
    double hra;
    double da;
    double grossSalary;
};
int main()
{
    int n;
    cout<<"Enter number of Employee : ";
    cin>>n;
    struct Employee emp[n];
    cout<<"Enter Details of Employee : ";
    for(int i=0;i<n;i++)
    {
        cout<<"Enter id : ";
        cin>>emp[i].id;
        cout<<"Enter name : ";
        cin>>emp[i].name;
        cout<<"Enter salary : ";
        cin>>emp[i].basicSalary;
        emp[i].hra = 0.20 * emp[i].basicSalary;
        emp[i].da  = 0.10 * emp[i].basicSalary;
        emp[i].grossSalary = emp[i].basicSalary + emp[i].hra + emp[i].da;
    }
    int index;
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(emp[i].grossSalary > max)
            index=i;
    }
    cout << "\nHighest Paid Employee: " << emp[index].name;
    cout << "\nGross Salary: " << emp[index].grossSalary << endl;

    // Search by ID or Name
    int choice;
    cout << "\nSearch Basic Salary By:\n1. Employee ID\n2. Name\nEnter choice: ";
    cin >> choice;

    int found = 0;

    switch (choice)
    {
    case 1:
    {
        string empId;
        cout << "Enter Employee ID: ";
        cin >> empId;

        for (int i = 0; i < n; i++)
        {
            if (emp[i].id == empId)
            {
                cout << "Basic Salary: " << emp[i].basicSalary << endl;
                found = 1;
                break;
            }
        }
        break;
    }

    case 2:
    {
        string searchName;
        cout << "Enter Name: ";
        cin >> searchName;

        for (int i = 0; i < n; i++)
        {
            if (emp[i].name == searchName)
            {
                cout << "Basic Salary: " << emp[i].basicSalary << endl;
                found = 1;
                break;
            }
        }
        break;
    }

    default:
        cout << "Invalid Choice\n";
    }

    if (!found)
        cout << "Employee not found!\n";

    return 0;
}
    