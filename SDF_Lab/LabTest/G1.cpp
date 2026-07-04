#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
    int payrollId;
    char *name;

public:
    // Parameterized constructor
    Employee(int id, const char *n)
    {
        payrollId = id;

        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Destructor
    ~Employee()
    {
        delete[] name;
    }

    int getPayrollId() const
    {
        return payrollId;
    }

    const char* getName() const
    {
        return name;
    }

    void display() const
    {
        cout << "Payroll ID: " << payrollId
             << ", Name: " << name << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    cin.ignore();

    Employee **employees = new Employee*[n];

    for (int i = 0; i < n; i++)
    {
        int id;
        char name[100];

        bool unique;

        do
        {
            unique = true;

            cout << "Enter Payroll ID for Employee " << i + 1 << ": ";
            cin >> id;

            // Check uniqueness
            for (int j = 0; j < i; j++)
            {
                if (employees[j]->getPayrollId() == id)
                {
                    cout << "Payroll ID already exists. Enter a unique ID.\n";
                    unique = false;
                    break;
                }
            }

        } while (!unique);

        cin.ignore();
        cout << "Enter Employee Name: ";
        cin.getline(name, 100);

        employees[i] = new Employee(id, name);
    }

    cout << "\n--- Employee Register ---\n";
    for (int i = 0; i < n; i++)
        employees[i]->display();

    // Search by payroll ID
    int searchId;
    cout << "\nEnter Payroll ID to search: ";
    cin >> searchId;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (employees[i]->getPayrollId() == searchId)
        {
            cout << "Employee Found:\n";
            employees[i]->display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Employee not found\n";

    // Highest and lowest payroll ID
    int highest = employees[0]->getPayrollId();
    int lowest  = employees[0]->getPayrollId();

    for (int i = 1; i < n; i++)
    {
        int id = employees[i]->getPayrollId();

        if (id > highest)
            highest = id;

        if (id < lowest)
            lowest = id;
    }

    cout << "Highest Payroll ID: " << highest << endl;
    cout << "Lowest Payroll ID: " << lowest << endl;

    // Free memory
    for (int i = 0; i < n; i++)
        delete employees[i];

    delete[] employees;

    return 0;
}