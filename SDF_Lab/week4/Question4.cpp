#include<iostream>
#include<vector>
using namespace std;
class Employee
{
    int id;
    double basicSalary;

    public:
    Employee()
    {
        id=0;
        basicSalary=0;
    }
    Employee(int i , double s)
    {
        id=i;
        basicSalary=s;
    }

    Employee ( const Employee & obj)
    {
        id=obj.id;
        basicSalary=obj.basicSalary;
    }

    friend class Payroll;
     friend void calculateNetSalary(Employee, class Payroll);
};

class Payroll
{
    double allowance;
    double deduction;
     
    public : 
    Payroll(double a,double d)
    {
        allowance=a;
        deduction=d;
    }
     double calculateAllowance(Employee e)
    {
      
        return 0.20 * e.basicSalary;
    }

    double calculateDeduction(Employee e)
    {
     
        return 0.10 * e.basicSalary;
    }

    double calculateNetSalary(Employee e)
    {
        double allowance = calculateAllowance(e);
        double deduction = calculateDeduction(e);

        return e.basicSalary + allowance - deduction;
    }
     friend void calculateNetSalary(Employee, Payroll);
   
};

class Department
{
    string deptName;
    int totalEmployees;

public:
  
    Department(string name, int total)
    {
        deptName = name;
        totalEmployees = total;
    }

   
    friend void transferEmployee(Department &from, Department &to);
};

void calculateNetSalary(Employee e, Payroll p)
{
    double netSalary = e.basicSalary + p.allowance - p.deduction;

    cout << "Employee ID : " << e.id << endl;
    cout << "Net Salary  : " << netSalary << endl;
}

void transferEmployee(Department &from, Department &to)
{
    if (from.totalEmployees > 0)
    {
        from.totalEmployees--;
        to.totalEmployees++;

        cout << "Employee transferred successfully." << endl;
    }
    else
    {
        cout << "No employees to transfer." << endl;
    }

    cout << from.deptName << " Employees : "
         << from.totalEmployees << endl;

    cout << to.deptName << " Employees : "
         << to.totalEmployees << endl;
}



int main()
{
  

    Employee e1;                 // default
    Employee e2(101, 25000);     // parameterized
    Employee e3(e2);             // copy

  
    Payroll p(5000, 2000);
    calculateNetSalary(e2, p);

    cout << endl;

   
    Department d1("CSE", 10);
    Department d2("ECE", 5);

    transferEmployee(d1, d2);

    return 0;
}
