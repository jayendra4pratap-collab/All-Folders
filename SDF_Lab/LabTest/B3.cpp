#include<iostream>
#include<cstring>
using namespace std;
class Student
{
    int roll;
    char *name;
    int *marks;
    int numSub;
    
    public :
    Student(){

    }
    Student(int r,char *n,int sb)
    {
        roll=r;
        name = new char[strlen(n)+1];
        strcpy(name,n);
        marks=new int[sb];
        for(int i=0;i<sb;i++)
        {
            marks[i]=0;
        }
        numSub=sb;
    }
    ~Student()
    {
        delete []name;
        delete []marks;
    }

    void readMarks()
    {
         if (numSub <= 0) {
            cout << "No subjects available\n";
            return;
        }
        cout<<"Enter marks of all Subject"<<endl;
        for(int i=0;i<numSub;i++)
        {
            cout<<"Enter marks of subject "<<i+1<<" : ";
            cin>>marks[i];
        }
    }

    const void showDetails()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Roll Number : "<<roll<<endl;
        cout<<"Marks in all subject "<<endl;
        int total;
        for(int i=0;i<numSub;i++)
        {
            cout<<marks[i]<<endl;
            total+=marks[i];
        }
        cout<<"Total Marks obtained : "<<total<<endl;
        cout<<"Percentage : "<<(total/numSub);
    }

    const int getHighestMark()
    {
        int mx=-1;
        for(int i=0;i<numSub;i++)
        {
            mx=max(mx,marks[i]);   
        }
        return mx;
    }
};
int main()
{
    int roll , numSub;
    char name[100];
    cout<<"Enter Roll number : ";
    cin>>roll;
    cin.ignore();
    cout<<"Enter Name of the student : ";
    cin.getline(name,100);

    cout<<"Enter number of the subjects : ";
    cin>>numSub;

    Student *student=new Student(roll,name,numSub) ;
     int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Enter marks\n";
        cout << "2. Display complete details\n";
        cout << "3. Show highest mark\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            student->readMarks();
            break;

        case 2:
            student->showDetails();
            break;

        case 3: {
            int highest = student->getHighestMark();
            if (highest == -1)
                cout << "No subjects available\n";
            else
                cout << "Highest Mark: " << highest << endl;
            break;
        }

        case 4:
            delete student;   // explicitly delete object
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}