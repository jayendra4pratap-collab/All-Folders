/*Create a C++ program to manage student results using dynamic memory. Create a class Student
with:rollNo (int), name (char*), marks (float), static variable count to store total number of students.
Include the class definitions and the main function to demonstrate the required operations.
1. 2. 3. 4. Allocate memory for N students dynamically.
Create a friend function that finds and displays the student with the highest marks.
Display function to print all student details.
Function to print total number of students having marks greater than 75.
5. Deallocate the memory.*/

#include<iostream>
#include <string.h>
using namespace std;
class student {
    int rollNo;
    char *name;
    float marks;
    static int count ;

    public:
    student()
    {

    }
    student(int r,char *n,float f)
    {
        rollNo=r;
        name=new char[strlen(n)+1];
        strcpy(name,n);
        marks=f;
        count++;
    }
    bool greator()
    {
        if(marks>75)
        return true;
        else
        return false;
    }
    void display()
    {
        cout<<"Roll Number : "<<rollNo<<endl
            <<"Name : "<<name<<endl
            <<"Marks : "<<marks<<endl;
    }
    static int getcount()
    {
    return count;
    }

    friend float compute(student &obj,float maxi);
};
int student::count = 0;
float compute(student &obj,float maxi)
{
    if(obj.marks>maxi)
    maxi = obj.marks;

    return maxi;
}

int main()
{
    cout<<"Enter number of the student : ";
    int n;
    cin>>n;

    student *s=new student[n];
    for(int i=0;i<n;i++)
    {
        char name[100];
        int roll;
        float marks;
        cout<<"Enter the roll number of the student : ";
        cin>>roll;
        cin.ignore();
        cout<<"Enter the name of the student : ";
        cin>>name;
     
        
        cout<<"Enter the marks obtained : ";
        cin>>marks;
     
        s[i]=student(roll,name,marks);
    }
    float maxi=0;
    int index=0;
    cout<<"Highest Marks obtsined by :- "<<endl;
    for(int i=0;i<n;i++)
    {
        if(compute(s[i],maxi)>maxi)
        {
           maxi=compute(s[i],maxi);
           index=i;
        }
    }

    s[index].display();
    cout<<"Students scored above 75 marks : -"<<endl;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i].greator())
        {
            s[i].display();
            cnt++;
        }
    }
    cout<<"Total number of student scored above 75 = "<<cnt<<endl;
    cout<<"Total number of student = "<<student ::getcount();

    delete []s;
    
    return 0;
}