#include <iostream>
#include <string>
using namespace std;

/* Base Class */
class Staff {
protected:
    int staffID;
    string name;

public:
    // Parameterized constructor
    Staff(int id, string n) {
        staffID = id;
        name = n;
    }

    // Display staff info
    void displayInfo() {
        cout << "Staff ID: " << staffID << endl;
        cout << "Name: " << name << endl;
    }
};

/* Derived Class: Doctor */
class Doctor : public Staff {
private:
    string specialization;
    int yearsOfExperience;

public:
    // Parameterized constructor
    Doctor(int id, string n, string spec, int exp)
        : Staff(id, n) {
        specialization = spec;
        yearsOfExperience = exp;
    }

    // Display doctor info
    void displayInfo() {
        Staff::displayInfo();
        cout << "Specialization: " << specialization << endl;
        cout << "Years of Experience: " << yearsOfExperience << endl;
    }
};

/* Derived Class: Surgeon */
class Surgeon : public Doctor {
private:
    int totalSurgeries;

public:
    // Parameterized constructor
    Surgeon(int id, string n, string spec, int exp, int surgeries)
        : Doctor(id, n, spec, exp) {
        totalSurgeries = surgeries;
    }

    // Display surgeon info
    void displayInfo() {
        Doctor::displayInfo();
        cout << "Total Surgeries Performed: " << totalSurgeries << endl;
    }
};

int main() {
    Surgeon s1(101, "Dr. Arjun", "Cardiology", 10, 250);

    s1.displayInfo();

    return 0;
}
// #include<iostream>
// #include<vector>
// using namespace std;
// class Staff
// {
//     protected:
//     int staffId;
//     string name;

//     Staff(int id,string n)
//     {
//         staffId=id;
//         name=n;
//     }

//     void display()
//     {
//         cout<<"Staff ID : "<<staffId<<endl;
//         cout<<"Name  : "<<name<<endl;
//     }

// };

// class Doctor : public Staff{
//     private : 
//     string special;
//     int yof;


// };
// int main()
// {
    
//     return 0;
// }