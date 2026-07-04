#include <iostream>
using namespace std;
struct Student
{
    int roll;
    string name;
    int marks[3];
    int total = 0;
    double avg = 0;
};
int main()
{
    int n;
    cout << "Print number of student :";
    cin >> n;

    struct Student stu[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Roll  Number : ";
        cin >> stu[i].roll;
        cout << "Enter name : ";
        cin >> stu[i].name;
        for (int j = 0; j < n; j++)
        {
            cout << "Enter marks : ";
            cin >> stu[i].marks[j];
            stu[i].total += stu[i].marks[j];
        }
        stu[i].avg = stu[i].total / 3;
    }

    cout << "Search By : " << endl
         << "Enter 1 for Roll No. " << endl
         << "Enter 2 for name";
    int choice;
    cin >> choice;
    int flag = 0;
    int rollNumber;
    string naam;
    switch (choice)
    {
    case 1:
        
        cin >> rollNumber;

        for (int i = 0; i < n; i++)
        {
            if (rollNumber == stu[i].roll)
            {
                cout << "Name is " << stu[i].name << endl;
                cout << "Average marks is " << stu[i].avg;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "This roll number not found" << endl;
        }
        break;

    case 2:
        
        cin >> naam;
        for (int i = 0; i < n; i++)
        {
            if (naam == stu[i].name)
            {
                cout << "Roll number is " << stu[i].roll << endl;
                cout << "Average marks is " << stu[i].avg;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "This roll number not found" << endl;
        }
        break;
    default:
    cout<<"Invalid Input";
    }
    return 0;
}