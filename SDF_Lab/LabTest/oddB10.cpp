#include<iostream>
#include<cstring>
using namespace std;
class Student 
{
    private :
    int rollNo;
    char *name;
    static int nextRoll;
public:
Student()
{

}
    Student(char *n)
    {
        if (strlen(n) == 0) {
            cout << "Invalid name! Assigning default name.\n";
            n = "Unknown";
        }

        rollNo = nextRoll++;
       
        name = new char[strlen(n)+1];
        strcpy(name,n);
    }
     ~Student() {
        delete[] name;
    }

    int getRollNo() const {
        return rollNo;
    }

    const char* getName() const {
        return name;
    }

    void updateName(const char* newName) {
        if (strlen(newName) == 0) {
            cout << "Name cannot be empty!\n";
            return;
        }
        //delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    // Display student details
    void display() const {
        cout << "Roll No: " << rollNo <<endl<< " Name: " << name << endl;
    }

};

int Student::nextRoll = 1;

int main()
{
    cout<<"Enter number of student  : ";
    int n;
    cin>>n;
    cin.ignore();
    Student **students = new Student*[n];
    int count=n;

     for (int i = 0; i < n; i++) {
        char name[100];
        cout << "Enter student name: ";
        cin.getline(name, 100);
        students[i] = new Student(name);
    }

    int choice;
    do {
        cout << "\n===== STUDENT MENU =====\n";
        cout << "1. Display all students\n";
        cout << "2. Search by roll number\n";
        cout << "3. Update student name\n";
        cout << "4. Delete student record\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            if (count == 0) {
                cout << "No student records available\n";
            } else {
                for (int i = 0; i < count; i++) {
                    students[i]->display();
                }
            }
            break;

        case 2: {
            int roll;
            cout << "Enter roll number to search: ";
            cin >> roll;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (students[i]->getRollNo() == roll) {
                    students[i]->display();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Student not found\n";
            break;
        }

        case 3: {
            int roll;
            char newName[100];
            cout << "Enter roll number to update: ";
            cin >> roll;
            cin.ignore();

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (students[i]->getRollNo() == roll) {
                    cout << "Enter new name: ";
                    cin.getline(newName, 100);
                    students[i]->updateName(newName);
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Student not found\n";
            break;
        }

        case 4: {
            int roll;
            cout << "Enter roll number to delete: ";
            cin >> roll;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (students[i]->getRollNo() == roll) {
                    delete students[i];
                    for (int j = i; j < count - 1; j++) {
                        students[j] = students[j + 1];
                    }
                    count--;
                    found = true;
                    cout << "Student record deleted\n";
                    break;
                }
            }
            if (!found)
                cout << "Student not found\n";
            break;
        }

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    // Cleanup remaining students
    for (int i = 0; i < count; i++) {
        delete students[i];
    }
    delete[] students;

    return 0;
}

