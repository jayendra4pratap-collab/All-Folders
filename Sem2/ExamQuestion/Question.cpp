#include<iostream>
#include<vector>
using namespace std;
class student
{
    private : 
    string id;
    int studyhr;

    public:
    student(string i , int hr) : id(i),studyhr(hr){}

    student operator+(int add)
    {
        return student(id,studyhr + add);
    }

    student operator-(int minus)
    {
        if(studyhr<minus)
        {
            cout<<"Study Hours not sufficient to minus"<<endl;
            return *this;
        }else
        {
        return student(id,studyhr - minus);
        }
    }
    void display()
    {
        cout<<"Student ID : "<<id<<endl;
        cout<<"Total Study Hours : "<<studyhr<<endl;
    }
    friend void compare(student & ,student &);
};

void compare(student &obj1,student &obj2)
{
    if(obj1.studyhr != obj2.studyhr)
    cout<<"Study Hours are different";
    else
    cout<<"Study are same .";
}
int main()
{
    student s1("100",10);
    student s2("101",15);
    s1.display();
    s2.display();
    student ob1=s1+10;
    student ob2 = s2-5;
    ob1.display();
    ob2.display();
    return 0;
}