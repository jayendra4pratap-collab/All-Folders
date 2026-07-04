#include <iostream>
using namespace std;

class Employee
{
private:
    double basicSalary;

public:
    Employee(double b)
    {
        basicSalary = b;
    }

    // Friend class
    friend class Payroll;
};

class Payroll
{
public:
    double calculateAllowance(Employee e)
    {
        // 20% allowance
        return 0.20 * e.basicSalary;
    }

    double calculateDeduction(Employee e)
    {
        // 10% deduction
        return 0.10 * e.basicSalary;
    }

    double calculateNetSalary(Employee e)
    {
        double allowance = calculateAllowance(e);
        double deduction = calculateDeduction(e);

        return e.basicSalary + allowance - deduction;
    }
};

int main()
{
    Employee emp(20000);   // basic salary

    Payroll p;

    cout << "Allowance = " << p.calculateAllowance(emp) << endl;
    cout << "Deduction = " << p.calculateDeduction(emp) << endl;
    cout << "Net Salary = " << p.calculateNetSalary(emp) << endl;

    return 0;
}